# IMbnMultiCarrierEvents::OnInterfaceCapabilityChange

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

This notification method is called by the Mobile Broadband service to indicate the completion of a [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider) operation that updates the interface capabilities.

## Parameters

### `mbnInterface` [in]

An [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) object that represents the Mobile Broadband device.

## Return value

This method must return **S_OK**.

## Remarks

When a network carrier is changed due to a call to [SetHomeProvider](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbnmulticarrier-sethomeprovider), **OnInterfaceCapabilityChange** is called when the interface capabilities are updated with the capabilities of the new carrier. An application can then call the [GetInterfaceCapability](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbninterface-getinterfacecapability) method of the [IMbnInterface](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbninterface) object passed to **SetHomeProvider** to get the available capability information. The **IMbnInterface** can be retrieved by calling **QueryInterface** on the [IMbnMultiCarrier](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrier) object passed to **OnInterfaceCapabilityChange**. For a list of interface capabilities, see [MBN_INTERFACE_CAPS](https://learn.microsoft.com/windows/desktop/api/mbnapi/ns-mbnapi-mbn_interface_caps).

## See also

[IMbnMultiCarrierEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbnmulticarrierevents)