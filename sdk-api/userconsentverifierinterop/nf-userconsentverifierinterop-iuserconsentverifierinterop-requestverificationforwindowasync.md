## Description

Performs a verification using a device such as Microsoft Passport PIN, Windows Hello, or a fingerprint reader.

## Parameters

### `appWindow`

Handle to the window of the active application.

### `message`

A message to display to the user for this biometric verification request.

### `riid`

The GUID for the resource interface.

The REFIID, or GUID, of the interface to the resource can be obtained by using the __uuidof() macro. For example:

`__uuidof(IAsyncOperation)`

### `asyncOperation`

A [IAsyncOperation](https://learn.microsoft.com/uwp/api/windows.foundation.iasyncoperation-1) value that returns a value from the [UserConsentVerificationResult](https://learn.microsoft.com/uwp/api/windows.security.credentials.ui.userconsentverificationresult) enumeration.

## Return value

If this function succeeds, it returns S_OK. Otherwise, it returns an HRESULT error code.

## Remarks

## See also