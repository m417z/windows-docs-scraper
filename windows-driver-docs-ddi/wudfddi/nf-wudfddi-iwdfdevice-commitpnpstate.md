# IWDFDevice::CommitPnpState

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CommitPnpState** method commits the state of the Plug and Play (PnP) property (that is, turns on, turns off, or sets to the default state) that the [IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate) method set.

## Remarks

The values of the [WDF_PNP_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_state) enumeration identify the state of PnP for the device.

#### Examples

For a code example of how to use the **CommitPnpState** method, see [IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate).

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate)

[WDF_PNP_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ne-wudfddi_types-_wdf_pnp_state)