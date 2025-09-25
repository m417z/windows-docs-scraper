# _WDF_SPECIAL_FILE_TYPE enumeration

## Description

[Applies to KMDF only]

The **WDF_SPECIAL_FILE_TYPE** enumeration identifies special file types that a device can support.

## Constants

### `WdfSpecialFileUndefined`

For internal use only. The default value is zero.

### `WdfSpecialFilePaging`

The device supports paging files. The default value is one.

### `WdfSpecialFileHibernation`

The device supports hibernation files.

### `WdfSpecialFileDump`

The device supports dump files.

### `WdfSpecialFileBoot`

The device supports boot files. This constant is available in version 1.11 and later versions of KMDF.

### `WdfSpecialFilePostDisplay`

The device supports a POST display adapter.

### `WdfSpecialFileGuestAssigned`

The device stack is assigned to a guest setting.

### `WdfSpecialFileInlineCryptoEngine`

The device supports inline crypto engine files.

### `WdfSpecialFileMax`

For internal use only.

## Remarks

For more information, see [Supporting Special Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-special-files).

## See also

- [WdfDeviceSetSpecialFileSupport](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicesetspecialfilesupport)
- [EVT_WDF_DEVICE_USAGE_NOTIFICATION callback function](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_usage_notification)
- [DEVICE_USAGE_NOTIFICATION_TYPE enumeration](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-device_usage_notification_type)