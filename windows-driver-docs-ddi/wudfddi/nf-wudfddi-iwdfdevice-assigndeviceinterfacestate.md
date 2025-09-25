# IWDFDevice::AssignDeviceInterfaceState

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **AssignDeviceInterfaceState** method enables or disables the specified device interface instance for a device.

## Parameters

### `pDeviceInterfaceGuid` [in]

A pointer to the GUID for a device interface class.

### `pReferenceString` [in, optional]

A pointer to a **NULL**-terminated string that contains the name of the instance of the device interface. This parameter is optional. The driver can pass **NULL** if the driver does not have to supply a name. If the driver must supply a name, the string that the driver passes must not contain any path separator characters ("/" or "\\").

### `Enable` [in]

A BOOL value that specifies whether the device interface instance should be enabled or disabled. **TRUE** indicates to enable; **FALSE** indicates to disable.

## Return value

**AssignDeviceInterfaceState** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

If [IWDFDevice::CreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface) succeeds, the framework automatically enables and disables the interface based on the device's PnP state.

Use the **AssignDeviceInterfaceState** method to disable and re-enable a device interface manually.

For more information about device interfaces, see [Using Device Interfaces in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

#### Examples

For a code example of how to use the **AssignDeviceInterfaceState** method, see [IWDFDevice::CreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface).

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDevice::CreateDeviceInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-createdeviceinterface)