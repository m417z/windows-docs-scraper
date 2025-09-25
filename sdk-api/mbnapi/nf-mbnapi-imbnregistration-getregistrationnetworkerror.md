# IMbnRegistration::GetRegistrationNetworkError

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the network error from a registration operation.

## Parameters

### `registrationNetworkError` [out]

A pointer to an error code returned by the last failed network registration operation. This is set to 0 if there is no error or if the error code is unknown.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For GSM devices, the error codes are defined in 3GPP specification 24.008 as "cause codes". For CDMA devices, the codes are device and network specific.

The error codes are cleared when the packet attach operation completes successfully.

Whenever there is a change in the network error value, the Mobile Broadband service will call the [OnRegisterStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnregistrationevents-onregisterstatechange) method of [IMbnRegistrationEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistrationevents).

## See also

[IMbnRegistration](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnregistration)