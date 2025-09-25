# STATFLAG enumeration

## Description

The
**STATFLAG** enumeration values indicate whether the method should try to return a name in the **pwcsName** member of the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure. The values are used in the
[ILockBytes::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-stat),
[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat), and
[IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) methods to save memory when the **pwcsName** member is not required.

## Constants

### `STATFLAG_DEFAULT:0`

Requests that the statistics include the **pwcsName** member of the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure.

### `STATFLAG_NONAME:1`

Requests that the statistics not include the **pwcsName** member of the
[STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structure. If the name is omitted, there is no need for the
[ILockBytes::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-stat),
[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat), and
[IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) methods to allocate and free memory for the string value of the name, therefore the method reduces time and resources used in an allocation and free operation.

### `STATFLAG_NOOPEN:2`

Not implemented.

## See also

[ILockBytes::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ilockbytes-stat)

[IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat)

[IStream::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat)