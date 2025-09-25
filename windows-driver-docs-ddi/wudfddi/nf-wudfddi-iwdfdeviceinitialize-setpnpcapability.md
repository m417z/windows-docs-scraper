# IWDFDeviceInitialize::SetPnpCapability

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **SetPnpCapability** method sets the specified Plug and Play (PnP) capability of a device to the specified state.

## Parameters

### `Capability` [in]

A [WDF_PNP_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_capability)-typed value that identifies the PnP capability to set.

### `Value` [in]

A WDF_TRI_STATE-typed value that identifies how to set the PnP capability that is specified by *Capability*. The following table shows the possible values.

| Value | Meaning |
| --- | --- |
| **WdfUseDefault** (0) | Set the capability to the default state. |
| **WdfFalse** (1) | Do not set the capability. |
| **WdfTrue** (2) | Set the capability. |

## See also

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFDeviceInitialize::GetPnpCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-getpnpcapability)

[WDF_PNP_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_capability)