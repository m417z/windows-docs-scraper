# WdfDeviceSetSpecialFileSupport function

## Description

[Applies to KMDF only]

The **WdfDeviceSetSpecialFileSupport** method enables or disables a function driver's support for special files, for the specified device.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `FileType` [in]

A [WDF_SPECIAL_FILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_special_file_type)-typed enumerator that identifies the type of special file that the driver supports.

### `FileTypeIsSupported` [in]

Supplies a Boolean value which, if **TRUE**, enables support for the special file type and, if **FALSE**, disables support the special file type.

## Remarks

A bug check occurs if the driver supplies an invalid object handle.

A function driver typically calls **WdfDeviceSetSpecialFileSupport** from within its [EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function.

Each driver's support for special files is initially disabled until the driver calls **WdfDeviceSetSpecialFileSupport**.

For more information, see [Supporting Special Files](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-special-files).

#### Examples

The following code example enables support for paging, hibernation, and dump files on a device.

```cpp
WdfDeviceSetSpecialFileSupport(
                               device,
                               WdfSpecialFilePaging,
                               TRUE
                               );
WdfDeviceSetSpecialFileSupport(
                               device,
                               WdfSpecialFileHibernation,
                               TRUE
                               );
WdfDeviceSetSpecialFileSupport(
                               device,
                               WdfSpecialFileDump,
                               TRUE
                               );
```

## See also

[EvtDriverDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add)

[WDF_SPECIAL_FILE_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_special_file_type)