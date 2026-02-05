{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  name = "java-dev-shell";

  buildInputs = with pkgs; [
    gcc
    glibc.dev 
    stdenv.cc.libc
    raylib
  ];

  shellHook = ''
    echo "gcc main.c -o MySorter -lraylib -lm && ./MySorter" &&
    codium . 
  '';
}
### Ausführen: 
# nix-shell myraylib.nix
