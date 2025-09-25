# _WDF_PNP_STATE enumeration

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_PNP_STATE** enumeration contains values that identify the status of Plug and Play (PnP) for a device.

## Constants

### `WdfPnpStateInvalid`

The PnP state for the device is invalid.

### `WdfPnpStateDisabled`

The device is disabled.

### `WdfPnpStateFailed`

The device is present but has failed.

### `WdfPnpStateRemoved`

The device has been removed.

### `WdfPnpStateResourcesChanged`

The device's resource requirements have changed.

### `WdfPnpStateDontDisplayInUI`

The device is hidden (not displayed) in Device Manager.

### `WdfPnpStateNotDisableable`

The device cannot be disabled.

### `WdfPnpStateMaximum`

Valid enumeration values were exceeded.

## Remarks

A UMDF driver supplies one of the values of **WDF_PNP_STATE** to the [IWDFDevice::GetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-getpnpstate) or [IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate) method to identify the PnP property to retrieve or set status for.

## See also

[IWDFDevice::GetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-getpnpstate)

[IWDFDevice::SetPnpState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-setpnpstate)