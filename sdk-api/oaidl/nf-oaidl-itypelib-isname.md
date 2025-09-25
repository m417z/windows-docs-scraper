# ITypeLib::IsName

## Description

Indicates whether a passed-in string contains the name of a type or member described in the library.

## Parameters

### `szNameBuf` [in, out]

The string to test. If this method is successful, *szNameBuf* is modified to match the case (capitalization) found in the type library.

### `lHashVal` [in]

The hash value of *szNameBuf*.

### `pfName` [out]

True if *szNameBuf* was found in the type library; otherwise false.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |

## See also

[ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib)