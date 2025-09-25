# IMbnInterfaceEvents::OnSubscriberInformationChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate that the subscriber information for the device has changed.

## Parameters

### `newInterface` [in]

An [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) that represents a device on which the subscriber information has changed.

## Return value

This method must return **S_OK**.

## Remarks

The application can call the [GetSubscriberInformation](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getsubscriberinformation) method of the passed [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) to get new subscriber information.

## See also

[IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents)