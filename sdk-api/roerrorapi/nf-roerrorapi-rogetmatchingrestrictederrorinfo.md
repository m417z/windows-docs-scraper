## Description

Retrieves the restricted error information for the specified HRESULT.

## Parameters

### `hrIn`

An HRESULT representing the error for which restricted error info is retrieved.

### `ppRestrictedErrorInfo`

Receives an instance of [IRestrictedErrorInfo](https://learn.microsoft.com/windows/win32/api/restrictederrorinfo/nn-restrictederrorinfo-irestrictederrorinfo) representing the details of an error, including restricted error information.

## Return value

Returns S_OK on success.

## Remarks

The function checks to see if current error info matches the *hrIn* value passed in and, if not, it originates a matching error info.

## See also