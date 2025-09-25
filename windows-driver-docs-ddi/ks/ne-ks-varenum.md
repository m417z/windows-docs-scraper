## Description

Specifies the variant types.

## Constants

### `VT_EMPTY`

Not specified.

### `VT_NULL`

Null.

### `VT_I2`

A 2-byte integer.

### `VT_I4`

A 4-byte integer.

### `VT_R4`

A 4-byte real.

### `VT_R8`

An 8-byte real.

### `VT_CY`

 Currency.

### `VT_DATE`

A date.

### `VT_BSTR`

A string.

### `VT_DISPATCH`

An [IDispatch](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-idispatch) pointer.

### `VT_ERROR`

An SCODE value.

### `VT_BOOL`

A Boolean value. True is -1 and false is 0.

### `VT_VARIANT`

A variant pointer.

### `VT_UNKNOWN`

An [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) pointer.

### `VT_DECIMAL`

A 16-byte fixed-pointer value.

### `VT_I1`

A character.

### `VT_UI1`

An unsigned character.

### `VT_UI2`

An unsigned short.

### `VT_UI4`

An unsigned long.

### `VT_I8`

A 64-bit integer.

### `VT_UI8`

A 64-bit unsigned integer.

### `VT_INT`

An integer.

### `VT_UINT`

An unsigned integer.

### `VT_VOID`

A C-style void.

### `VT_HRESULT`

An HRESULT value.

### `VT_PTR`

A pointer type.

### `VT_SAFEARRAY`

A safe array. Use VT_ARRAY in VARIANT.

### `VT_CARRAY`

A C-style array.

### `VT_USERDEFINED`

A user-defined type.

### `VT_LPSTR`

A null-terminated string.

### `VT_LPWSTR`

A wide null-terminated string.

### `VT_FILETIME`

A [FILETIME](https://learn.microsoft.com/windows/win32/api/minwinbase/ns-minwinbase-filetime) value.

### `VT_BLOB`

Length-prefixed bytes.

### `VT_STREAM`

The name of the stream follows.

### `VT_STORAGE`

The name of the storage follows.

### `VT_STREAMED_OBJECT`

The stream contains an object.

### `VT_STORED_OBJECT`

The storage contains an object.

### `VT_BLOB_OBJECT`

The blob contains an object.

### `VT_CF`

A clipboard format.

### `VT_CLSID`

A class ID.

### `VT_VECTOR`

A simple counted array.

### `VT_ARRAY`

A SAFEARRAY pointer.

### `VT_BYREF`

A void pointer for local use.

### `VT_RESERVED`

Reserved.

### `VT_ILLEGAL`

An illegal value.

### `VT_ILLEGALMASKED`

An illegal masked value.

### `VT_TYPEMASK`

A type mask.

## Remarks

The following table shows where these values can be used.

| Value | VARIANT | TYPEDESC | Property set | Safe array |
|--|--|--|--|--|
| VT_ARRAY | X | | | |
| VT_BLOB | | | X | |
| VT_BLOB_OBJECT | | | X | |
| VT_BOOL | X | X | X | X |
| VT_BSTR | X | X | X | X |
| VT_BYREF | X | | | |
| VT_CARRAY | X | | | |
| VT_CF | | | X | |
| VT_CLSID | | | X | |
| VT_CY | X | X | X | X |
| VT_DATE | X | X | X | X |
| VT_DECIMAL | X | X | | X |
| VT_DISPATCH | X | X | | X |
| VT_EMPTY | X | | X | |
| VT_ERROR | X | X | X | X |
| VT_FILETIME | | | X | |
| VT_HRESULT | | | X | |
| VT_I1 | X | X | X | X |
| VT_I2 | X | X | X | X |
| VT_I4 | X | X | X | X |
| VT_I8 | | X | X | |
| VT_ILLEGAL | | | X | |
| VT_INT | X | X | X | X |
| VT_LPSTR | | X | X | |
| VT_LPWSTR | | X | X | |
| VT_NULL | X | | X | |
| VT_PTR | | | X | |
| VT_R4 | X | X | X | X |
| VT_R8 | X | X | X | X |
| VT_SAFEARRAY | | X | | |
| VT_STORAGE | | | X | |
| VT_STORED_OBJECT | | | X | |
| VT_STREAM | | | X | |
| VT_STREAMED_OBJECT | | | X | |
| VT_UI1 | X | X | X | X |
| VT_UI2 | X | X | X | X |
| VT_UI4 | X | X | X | X |
| VT_UI8 | | X | X | |
| VT_UINT | X | X | | X |
| VT_UNKNOWN | X | X | | X |
| VT_USERDEFINED | | | X | |
| VT_VARIANT | X | X | X | X |
| VT_VECTOR | | | X | |
| VT_VOID | | | X | |