# IWDFDeviceInitialize::GetPnpCapability

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetPnpCapability** method determines the state of the specified Plug and Play (PnP) capability.

## Parameters

### `Capability` [in]

A [WDF_PNP_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_capability)-typed value that identifies the PnP capability to retrieve status about.

## Return value

**GetPnpCapability** returns one of the following WDF_TRI_STATE-typed values that identifies the state of the PnP capability that is specified in the *Capability* parameter:

| Return code | Description |
| --- | --- |
| **WdfUseDefault (0)** | The capability is set to the default state. |
| **WdfFalse (1)** | The capability is not set. |
| **WdfTrue (2)** | The capability is set. |

## See also

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFDeviceInitialize::SetPnpCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-setpnpcapability)

[WDF_PNP_CAPABILITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_capability)