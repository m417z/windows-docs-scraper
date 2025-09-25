# IWDFDevice2::GetDeviceStackIoTypePreference

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetDeviceStackIoTypePreference** method retrieves the buffer access methods that the framework is using for a device.

## Parameters

### `ReadWritePreference` [out]

A pointer to a driver-allocated location that receives a [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed value. This value identifies the buffer access method that the framework is using for a device's read and write requests.

### `IoControlPreference` [out]

A pointer to a driver-allocated location that receives a [WDF_DEVICE_IO_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_device_io_type)-typed value. This value that identifies the buffer access method that the framework is using for a device's I/O control requests.

## Remarks

If your driver calls **GetDeviceStackIoTypePreference** before the PnP manager has loaded all of the device's drivers, the values that **GetDeviceStackIoTypePreference** retrieves might not be the values that it actually uses.

For more information about how the framework chooses a buffer access method, see [How UMDF Chooses a Buffer Access Method for an I/O Request](https://learn.microsoft.com/windows-hardware/drivers/wdf/accessing-data-buffers-in-wdf-drivers).

#### Examples

The following code example retrieves the buffer access methods that the framework is using for a device.

```
WDF_DEVICE_IO_TYPE ReadWriteAccessMethod;
WDF_DEVICE_IO_TYPE IoControlAccessMethod;

Device2->GetDeviceStackIoTypePreference(&ReadWriteAccessMethod,
                                        &IoControlAccessMethod);
```

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFDeviceInitialize2::SetIoTypePreference](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdeviceinitialize2-setiotypepreference)