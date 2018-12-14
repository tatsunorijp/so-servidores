#!/bin/bash
for fold_dir in server*; do
  make -C "$fold_dir"
done