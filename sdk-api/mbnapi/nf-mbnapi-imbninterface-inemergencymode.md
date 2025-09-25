# IMbnInterface::InEmergencyMode

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Determines whether the device is in emergency mode.

## Parameters

### `emergencyMode` [out]

Points to VARIANT_TRUE if the device is in emergency mode, and VARIANT_FALSE if it is not.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing for this information. The calling application can be notified when the data is available by registering for the [OnEmergencyModeChange](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-onemergencymodechange) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents). |

## Remarks

If a device cannot register on the network for any reason, then the device may automatically register onto a network in emergency mode. For example, a device cannot register on the network if the SIM is not inserted, user subscription validity expired, or roaming is not enabled for user. In emergency mode, device can be used in limited mode for voice calls to emergency numbers.

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)