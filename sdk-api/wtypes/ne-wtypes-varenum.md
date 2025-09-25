# VARENUM enumeration

## Description

Specifies the variant types.

## Constants

### `VT_EMPTY:0`

Not specified.

### `VT_NULL:1`

Null.

### `VT_I2:2`

A 2-byte integer.

### `VT_I4:3`

A 4-byte integer.

### `VT_R4:4`

A 4-byte real.

### `VT_R8:5`

An 8-byte real.

### `VT_CY:6`

 Currency.

### `VT_DATE:7`

A date.

### `VT_BSTR:8`

A string.

### `VT_DISPATCH:9`

An [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch) pointer.

### `VT_ERROR:10`

An SCODE value.

### `VT_BOOL:11`

A Boolean value. True is -1 and false is 0.

### `VT_VARIANT:12`

A variant pointer.

### `VT_UNKNOWN:13`

An [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer.

### `VT_DECIMAL:14`

A 16-byte fixed-pointer value.

### `VT_I1:16`

A character.

### `VT_UI1:17`

An unsigned character.

### `VT_UI2:18`

An unsigned short.

### `VT_UI4:19`

An unsigned long.

### `VT_I8:20`

A 64-bit integer.

### `VT_UI8:21`

A 64-bit unsigned integer.

### `VT_INT:22`

An integer.

### `VT_UINT:23`

An unsigned integer.

### `VT_VOID:24`

A C-style void.

### `VT_HRESULT:25`

An HRESULT value.

### `VT_PTR:26`

A pointer type.

### `VT_SAFEARRAY:27`

A safe array. Use VT_ARRAY in VARIANT.

### `VT_CARRAY:28`

A C-style array.

### `VT_USERDEFINED:29`

A user-defined type.

### `VT_LPSTR:30`

A null-terminated string.

### `VT_LPWSTR:31`

A wide null-terminated string.

### `VT_RECORD:36`

A user-defined type.

### `VT_INT_PTR:37`

A signed machine register size width.

### `VT_UINT_PTR:38`

An unsigned machine register size width.

### `VT_FILETIME:64`

A [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) value.

### `VT_BLOB:65`

Length-prefixed bytes.

### `VT_STREAM:66`

The name of the stream follows.

### `VT_STORAGE:67`

The name of the storage follows.

### `VT_STREAMED_OBJECT:68`

The stream contains an object.

### `VT_STORED_OBJECT:69`

The storage contains an object.

### `VT_BLOB_OBJECT:70`

The blob contains an object.

### `VT_CF:71`

A clipboard format.

### `VT_CLSID:72`

A class ID.

### `VT_VERSIONED_STREAM:73`

A stream with a GUID version.

### `VT_BSTR_BLOB:0xfff`

Reserved.

### `VT_VECTOR:0x1000`

A simple counted array.

### `VT_ARRAY:0x2000`

A SAFEARRAY pointer.

### `VT_BYREF:0x4000`

A void pointer for local use.

### `VT_RESERVED:0x8000`

### `VT_ILLEGAL:0xffff`

### `VT_ILLEGALMASKED:0xfff`

### `VT_TYPEMASK:0xfff`

## Remarks

The following table shows where these values can be used.

| Value | VARIANT | TYPEDESC | Property set | Safe array |
| --- | --- | --- | --- | --- |
| **VT_ARRAY** | X |  |  |  |
| **VT_BLOB** |  |  | X |  |
| **VT_BLOB_OBJECT** |  |  | X |  |
| **VT_BOOL** | X | X | X | X |
| **VT_BSTR** | X | X | X | X |
| **VT_BSTR_BLOB** |  |  |  |  |
| **VT_BYREF** | X |  |  |  |
| **VT_CARRAY** |  | X |  |  |
| **VT_CF** |  |  | X |  |
| **VT_CLSID** |  |  | X |  |
| **VT_CY** | X | X | X | X |
| **VT_DATE** | X | X | X | X |
| **VT_DECIMAL** | X | X |  | X |
| **VT_DISPATCH** | X | X |  | X |
| **VT_EMPTY** | X |  | X |  |
| **VT_ERROR** | X | X | X | X |
| **VT_FILETIME** |  |  | X |  |
| **VT_HRESULT** |  |  | X |  |
| **VT_I1** | X | X | X | X |
| **VT_I2** | X | X | X | X |
| **VT_I4** | X | X | X | X |
| **VT_I8** |  | X | X |  |
| **VT_INT** | X | X | X | X |
| **VT_INT_PTR** |  |  | X |  |
| **VT_LPSTR** |  | X | X |  |
| **VT_LPWSTR** |  | X | X |  |
| **VT_NULL** | X |  | X |  |
| **VT_PTR** |  |  | X |  |
| **VT_R4** | X | X | X | X |
| **VT_R8** | X | X | X | X |
| **VT_RECORD** | X |  | X | X |
| **VT_SAFEARRAY** |  | X |  |  |
| **VT_STORAGE** |  |  | X |  |
| **VT_STORED_OBJECT** |  |  | X |  |
| **VT_STREAM** |  |  | X |  |
| **VT_STREAMED_OBJECT** |  |  | X |  |
| **VT_UI1** | X | X | X | X |
| **VT_UI2** | X | X | X | X |
| **VT_UI4** | X | X | X | X |
| **VT_UI8** |  | X | X |  |
| **VT_UINT** | X | X |  | X |
| **VT_UINT_PTR** |  |  | X |  |
| **VT_UNKNOWN** | X | X |  | X |
| **VT_USERDEFINED** |  |  | X |  |
| **VT_VARIANT** | X | X | X | X |
| **VT_VECTOR** |  |  | X |  |
| **VT_VERSIONED_STREAM** |  |  | X |  |
| **VT_VOID** |  |  | X |  |

**VT_BSTR_BLOB** is reserved for system use.