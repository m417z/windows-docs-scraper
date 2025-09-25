# IMbnConnection::GetActivationNetworkError

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the network error returned in a Packet Data Protocol (PDP) context activation failure.

## Parameters

### `networkError` [out, retval]

The error code returned by the network from the last connection context activation operation. The value is meaningful only if the method returns **S_OK**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For GSM devices these error codes are defined in 3GPP specification 24.008 as cause codes. For CDMA devices, device and network specific error codes are used.

The error codes are cleared when the context activation operation completes successfully. When there is no network error or the error is not known, then the value is set to 0.

Whenever there is a change in the network error value, the Mobile Broadband service will call the [OnConnectStateChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnconnectionevents-onconnectstatechange) member of [IMbnConnectionEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnectionevents).

## See also

[IMbnConnection](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnconnection)