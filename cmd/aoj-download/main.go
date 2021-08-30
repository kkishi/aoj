package main

import (
	"errors"
	"flag"
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"os/exec"
	"path"
)

const rootDir = "problems"

func exists(path string) (bool, error) {
	_, err := os.Stat(path)
	if err == nil {
		return true, nil
	}
	if os.IsNotExist(err) {
		return false, nil
	}
	return false, err
}

var tmpl = `#include <bits/stdc++.h>

#include "aoj.h"

void Main() {
}`

func createDir(problem string) error {
	dir := path.Join(rootDir, problem)
	if err := os.MkdirAll(dir, 0750); err != nil && !os.IsExist(err) {
		return err
	}
	mainCC := path.Join(dir, "main.cc")
	if e, err := exists(mainCC); err != nil {
		return err
	} else if !e {
		if err := ioutil.WriteFile(mainCC, []byte(tmpl), 0644); err != nil {
			return err
		}
	}
	return nil
}

func downloadSamples(problem string) error {
	dir := path.Join(rootDir, problem)
	testDir := path.Join(dir, "test")
	if e, err := exists(testDir); err != nil {
		return err
	} else if e {
		log.Printf("%s already exists; skip", testDir)
		return nil
	}
	url := fmt.Sprintf("https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=%s", problem)
	cmd := exec.Command("oj", "d", url)
	cmd.Dir = dir
	cmd.Stdin = os.Stdin
	cmd.Stdout = os.Stdout
	cmd.Stderr = os.Stderr
	if err := cmd.Run(); err != nil {
		// oj d fails in the following cases:
		//
		// 1) There's no problem corresponding to the URL
		// 2) The problem doesn't have samples (e.g., it's an interactive problem)
		//
		// To handle both cases reasonably, on errors we just report and continue.
		log.Printf("oj d failed: %s", err)
	}
	return nil
}

func run() error {
	if len(flag.Args()) != 1 {
		return errors.New("problem not specified")
	}
	problem := flag.Arg(0)
	if err := createDir(problem); err != nil {
		return err
	}
	return downloadSamples(problem)
}

func main() {
	flag.Parse()
	log.SetFlags(log.Flags() | log.Lmicroseconds)
	if err := run(); err != nil {
		log.Println("Error:", err)
		os.Exit(1)
	}
}
