# OLECMDEXECOPT enumeration

## Description

Specifies command execution options.

## Constants

### `OLECMDEXECOPT_DODEFAULT:0`

Prompt the user for input or not, whichever is the default behavior.

### `OLECMDEXECOPT_PROMPTUSER:1`

Execute the command after obtaining user input.

### `OLECMDEXECOPT_DONTPROMPTUSER:2`

Execute the command without prompting the user. For example, clicking the Print toolbar button causes a document to be immediately printed without user input.

### `OLECMDEXECOPT_SHOWHELP:3`

Show help for the corresponding command, but do not execute.

## See also

[IOleCommandTarget::Exec](https://learn.microsoft.com/windows/desktop/api/docobj/nf-docobj-iolecommandtarget-exec)