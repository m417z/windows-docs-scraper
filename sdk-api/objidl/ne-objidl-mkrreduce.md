# MKRREDUCE enumeration

## Description

Specifies how far a moniker should be reduced.

## Constants

### `MKRREDUCE_ONE`

Performs only one step of reducing the moniker. In general, the caller must have specific knowledge about the particular kind of moniker to take advantage of this option.

### `MKRREDUCE_TOUSER`

Reduces the moniker to a form that the user identifies as a persistent object. If no such point exists, then this option should be treated as MKRREDUCE_ALL.

### `MKRREDUCE_THROUGHUSER`

Reduces the moniker to where any further reduction would reduce it to a form that the user does not identify as a persistent object. Often, this is the same stage as MKRREDUCE_TOUSER.

### `MKRREDUCE_ALL:0`

Reduces the moniker until it is in its simplest form, that is, reduce it to itself.

## See also

[IMoniker::Reduce](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-reduce)