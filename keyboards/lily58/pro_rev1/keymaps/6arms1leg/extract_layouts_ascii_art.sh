#!/usr/bin/env bash

# Show keyboard layout help (extract ASCII-art comments from QMK keymap file)

SCRIPT_DIR="$(dirname "$(readlink -f "${BASH_SOURCE[0]}")")"
FILE="${SCRIPT_DIR}/keymap.c"

# Use `sed` to extract and print keymap layouts, then pipe to `less` for no-wrap
# view
sed -n '
  # Look for the start of a block comment that contains a dashed line
  /^\/\*/{
    :a
    N # Append next line to the pattern space

    # Loop until we see the line with the long dashed separator
    /,-----------------------------------------\./!ba

    :b
    N # Keep appending until the closing `*/`
    /\*\//!bb # Stop when we hit the terminating `*/`

    # At this point pattern space holds the whole comment block

    # Remove the opening `/*` and closing `*/` themselves
    s/^\/\*//; s/\*\/$//

    # Strip a leading `*` (and optional whitespace) from every line
    s/^[[:space:]]*\*[[:space:]]\?//gm

    p # Print the cleaned‑up block
  }
' "$FILE" | less --chop-long-lines
