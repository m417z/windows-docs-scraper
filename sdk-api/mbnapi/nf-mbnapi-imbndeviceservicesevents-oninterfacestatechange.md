# IMbnDeviceServicesEvents::OnInterfaceStateChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Notification method that signals a change in the state of device services on the system.

## Parameters

### `interfaceID` [in]

The [InterfaceID](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-get_interfaceid) of the device for which the device services state change notification is sent.

### `stateChange` [in]

A [MBN_DEVICE_SERVICES_INTERFACE_STATE](https://learn.microsoft.com/windows/desktop/api/mbnapi/ne-mbnapi-mbn_device_services_interface_state) enumeration that specifies whether the device service capable device is available or unavailable.

## Return value

The method must return the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |

## See also

[IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents)