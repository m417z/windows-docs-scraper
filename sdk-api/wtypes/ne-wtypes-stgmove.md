# STGMOVE enumeration

## Description

The
**STGMOVE** enumeration values indicate whether a storage element is to be moved or copied. They are used in the
[IStorage::MoveElementTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-moveelementto) method.

## Constants

### `STGMOVE_MOVE:0`

Indicates that the method should move the data from the source to the destination.

### `STGMOVE_COPY:1`

Indicates that the method should copy the data from the source to the destination. A copy is the same as a move except that the source element is not removed after copying the element to the destination. Copying an element on top of itself is undefined.

### `STGMOVE_SHALLOWCOPY:2`

Not implemented.

## See also

[IStorage::MoveElementTo](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-moveelementto)