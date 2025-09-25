# _WDF_PNP_CAPABILITY enumeration

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WDF_PNP_CAPABILITY** enumeration contains values that identify Plug and Play (PnP) capabilities for a device.

## Constants

### `WdfPnpCapInvalid`

Indicates whether PnP capabilities of the device are invalid.

### `WdfPnpCapLockSupported`

Indicates whether the device can be locked in its slot to prevent ejection. (Setting this capability disables ejecting a device from its slot and does not disable ejecting media from a device.)

### `WdfPnpCapEjectSupported`

Indicates whether the device can be ejected from its slot. (Setting this capability enables ejecting a device from its slot and does not enable ejecting media from a device.)

### `WdfPnpCapRemovable`

Indicates whether the device can be removed while the computer is running. If **WdfPnpCapRemovable** is set to **WdfTrue** and **WdfPnpCapSurpriseRemovalOk** is set to **WdfFalse**, users should use the system's Unplug or Eject Hardware application.

### `WdfPnpCapDockDevice`

Indicates whether the device is a docking station.

### `WdfPnpCapSurpriseRemovalOk`

Indicates whether users can remove the device without using the computer's Unplug or Eject Hardware application.

### `WdfPnpCapNoDisplayInUI`

Indicates whether the device can be hidden (not displayed) in Device Manager.

### `WdfPnpCapMaximum`

Valid enumeration values were exceeded.

## Remarks

A UMDF driver supplies one of the values of **WDF_PNP_CAPABILITY** to the [IWDFDeviceInitialize::GetPnpCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-getpnpcapability) or [IWDFDeviceInitialize::SetPnpCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-setpnpcapability) method to identify the PnP capability to retrieve or set status for.

## See also

[IWDFDeviceInitialize::GetPnpCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-getpnpcapability)

[IWDFDeviceInitialize::SetPnpCapability](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize-setpnpcapability)