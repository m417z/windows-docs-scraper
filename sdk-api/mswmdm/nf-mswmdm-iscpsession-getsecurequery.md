# ISCPSession::GetSecureQuery

## Description

The **GetSecureQuery** method is used to obtain a secure query object for the session.

## Parameters

### `ppSecureQuery` [out]

Pointer to a secure query object.

## Return value

If the method succeeds, it returns S_OK. If the method fails, it returns an **HRESULT** error code.

## Remarks

This method should be used to obtain a secure query object when using secure content provider sessions for efficient transfer of multiple files.

## See also

[ISCPSession Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iscpsession)