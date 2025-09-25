# IMbnInterfaceEvents::OnHomeProviderAvailable

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate that home provider information for the device is available.

## Parameters

### `newInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents the device whose home provider information has become available.

## Return value

This method must return **S_OK**.

## Remarks

An application can call the [GetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-gethomeprovider) method of the passed [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get the available home provider information.

## See also

[IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents)