# IContactProperties::SetBinary

## Description

Sets the binary data at a specified property to the contents of a specified [IStream interface [Structured Storage]](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream),
which contains a null-terminated string (as MIME type) data.

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Specifies the property to set.

### `dwFlags` [in]

Type: **DWORD**

CGD_DEFAULT can be used to create or overwrite the value at *pszPropertyName*.

### `pszContentType` [in]

Type: **LPWSTR**

Specifies null-terminated string representing MIME type to store when CGD_DEFAULT.

### `pStream` [in]

Type: **IStream***

Pointer to [IStream interface [Structured Storage]](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) object containing data to place at this node.
NOTE: IStream::Read is called for the data until it succeeds with a zero-length read.
Any other return value results in a failure and no change.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | Value is set successfully. |
| **ERROR_PATH_NOT_FOUND** | Property name is invalid for set, or property name doesn't exist for delete. |
| **ERROR_INVALID_DATATYPE** | Unable to set the value for this property due to schema. |

## Remarks

To set a single-level property, set *pszPropertyName* to the property name.

To set a property from a multi-value property, set *pszPropertyName*
to the form: toplevel/secondlevel[4]/thirdlevel.