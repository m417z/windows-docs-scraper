# IMbnInterface::GetInterfaceCapability

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the capabilities of the device.

## Parameters

### `interfaceCaps` [out, retval]

A pointer to an [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps) structure that contains the interface capabilities. If this method returns any value other than **S_OK**, this parameter is **NULL**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. *interfaceCaps* contains valid values. |
| **E_PENDING** | The information is not available. The Mobile Broadband service is currently probing for the device capabilities. The calling application can get notified when the device capabilities are available by registering for the [OnInterfaceCapabilityAvailable](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterfaceevents-oninterfacecapabilityavailable) method of [IMbnInterfaceEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterfaceevents). |

## Remarks

The **GetInterfaceCapability** method returns the interface capabilities, including the cellular technology type, the type of support for voice calls, the type of SIM used, the frequency bands supported, and the availability of SMS support. It also returns the device manufacturer name, model, and firmware name, though these are optional and may not be filled for some of the devices. For more information, see [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps).

## See also

[IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface)