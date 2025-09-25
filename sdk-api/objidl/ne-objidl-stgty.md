# STGTY enumeration

## Description

The
**STGTY** enumeration values are used in the **type** member of the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure to indicate the type of the storage element. A storage element is a storage object, a stream object, or a byte-array object (LOCKBYTES).

## Constants

### `STGTY_STORAGE:1`

Indicates that the storage element is a storage object.

### `STGTY_STREAM:2`

Indicates that the storage element is a stream object.

### `STGTY_LOCKBYTES:3`

Indicates that the storage element is a byte-array object.

### `STGTY_PROPERTY:4`

Indicates that the storage element is a property storage object.

## See also

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)

[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg)