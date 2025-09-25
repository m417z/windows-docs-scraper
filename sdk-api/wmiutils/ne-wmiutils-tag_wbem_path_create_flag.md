# tag_WBEM_PATH_CREATE_FLAG enumeration

## Description

Contains flags specifying the type of paths accepted.

## Constants

### `WBEMPATH_CREATE_ACCEPT_RELATIVE:0x1`

Allow paths without server names.

### `WBEMPATH_CREATE_ACCEPT_ABSOLUTE:0x2`

Reserved for future use.

### `WBEMPATH_CREATE_ACCEPT_ALL:0x4`

Allow setting an empty path (which additionally clears out the object), Also allows paths which have just the server names, or paths which don't have server names.

### `WBEMPATH_TREAT_SINGLE_IDENT_AS_NS:0x8`

A simple path, such as "XYZ" is interpreted as a namespace.