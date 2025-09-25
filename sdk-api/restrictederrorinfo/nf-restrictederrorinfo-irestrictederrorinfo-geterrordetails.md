# IRestrictedErrorInfo::GetErrorDetails

## Description

Returns information about an error, including the restricted error description.

## Parameters

### `description` [out]

Type: **BSTR***

The error description.

### `error` [out]

Type: **HRESULT***

The error code associated with the error condition.

### `restrictedDescription` [out]

Type: **BSTR***

The restricted error description.

### `capabilitySid`

TBD

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRestrictedErrorInfo](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo)