# IContactProperties::GetBinary

## Description

Retrieves the binary data of a property using an [IStream interface [Structured Storage]](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Parameters

### `pszPropertyName` [in]

Type: **LPCWSTR**

Specifies the property to retrieve.

### `dwFlags` [in]

Type: **DWORD**

Must be CGD_DEFAULT.

### `pszContentType` [in, out]

Type: **LPWSTR**

Specifies user-allocated buffer to store the MIME content type.

### `cchContentType` [in]

Type: **DWORD**

Specifies the allocated buffer size in characters.

### `pdwcchContentTypeRequired` [in, out]

Type: **DWORD***

On failure, contains the required size for *pszContentType*.

### `ppStream` [out]

Type: **IStream****

On success, contains a new [IStream interface [Structured Storage]](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream). Use this to retrieve the binary data.

## Return value

Type: **HRESULT**

Returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | *ppStream* contains an [IStream interface [Structured Storage]](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream). Caller must release the reference. |
| **S_FALSE** | No data for this value. Either the property has been present in the past but its value has been removed or the property is a container of other properties (toplevel/secondlevel[3]). The buffer at *pszContentType* has been zeroed. |
| **ERROR_PATH_NOT_FOUND** | No data found for this property name. |
| **ERROR_INVALID_DATATYPE** | Unable to get value for this property due to schema. |
| **ERROR_INSUFFICIENT_BUFFER** | *pszContentType* was not large enough to store the value. The required buffer size is stored in *pdwcchContentTypeRequired*. |

## Remarks

To retrieve a single level property, set *pszPropertyName* to the property name.

To retrieve a value from a multi-value (hierarchical) property, include the desired index as part of *pszPropertyName* using the form: toplevel/secondlevel[1]/thirdlevel. NOTE: the first element of a set is index 1, so index [0] is invalid.

For deleted properties, this method returns S_OK and an [IStream interface [Structured Storage]](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) of zero length. NOTE: For properties not of binary type, this method may return incorrect data in the IStream.