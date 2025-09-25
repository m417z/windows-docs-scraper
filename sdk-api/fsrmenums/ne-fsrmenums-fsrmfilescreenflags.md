# FsrmFileScreenFlags enumeration

## Description

Defines the options for failing IO operations that violate a file screen.

## Constants

### `FsrmFileScreenFlags_Enforce:0x1`

If this flag is set, the server will fail any IO operation that violates the file screen. If this flag is
not set, the server will not fail violating IO operations but will still run any action associated with the file
screen.

## See also

[IFsrmFileScreenBase::FileScreenFlags](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nf-fsrmscreen-ifsrmfilescreenbase-get_filescreenflags)