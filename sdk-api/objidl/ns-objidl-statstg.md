# STATSTG structure

## Description

The
**STATSTG** structure contains statistical data about an open storage, stream, or byte-array object. This structure is used in the
[IEnumSTATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg),
[ILockBytes](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ilockbytes),
[IStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istorage), and
[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) interfaces.

## Members

### `pwcsName`

A pointer to a **NULL**-terminated Unicode string that contains the name. Space for this string is allocated by the method called and freed by the caller (for more information, see
[CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree)). To not return this member, specify the STATFLAG_NONAME value when you call a method that returns a
**STATSTG** structure, except for calls to [IEnumSTATSTG::Next](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstatstg), which provides no way to specify this value.

### `type`

Indicates the type of storage object. This is one of the values from the
[STGTY](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-stgty) enumeration.

### `cbSize`

Specifies the size, in bytes, of the stream or byte array.

### `mtime`

Indicates the last modification time for this storage, stream, or byte array.

### `ctime`

Indicates the creation time for this storage, stream, or byte array.

### `atime`

Indicates the last access time for this storage, stream, or byte array.

### `grfMode`

Indicates the access mode specified when the object was opened. This member is only valid in calls to
**Stat** methods.

### `grfLocksSupported`

Indicates the types of region locking supported by the stream or byte array. For more information about the values available, see the
[LOCKTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-locktype) enumeration. This member is not used for storage objects.

### `clsid`

Indicates the class identifier for the storage object; set to CLSID_NULL for new storage objects. This member is not used for streams or byte arrays.

### `grfStateBits`

Indicates the current state bits of the storage object; that is, the value most recently set by the
[IStorage::SetStateBits](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setstatebits) method. This member is not valid for streams or byte arrays.

### `reserved`

Reserved for future use.

## See also

[IStorage::SetElementTimes](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setelementtimes)