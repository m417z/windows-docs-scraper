# IMbnPinManagerEvents::OnPinListAvailable

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method called by the Mobile Broadband service to indicate that the list of device PINs is available.

## Parameters

### `pinManager` [in]

Pointer to an [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) interface that represents the Mobile Broadband device for which the PIN list is available.

## Return value

This method must return **S_OK**.

## Remarks

This method is called by the Mobile Broadband service to notify an application when the list of supported PIN types is available or if a PIN list retrieval operation resulted in an error. The calling application can issue the [GetPinList](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnpinmanager-getpinlist) method of the passed [IMbnPinManager](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanager) to get the available list of supported PINs or error code returned in the operation.

## See also

[IMbnPinManagerEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnpinmanagerevents)