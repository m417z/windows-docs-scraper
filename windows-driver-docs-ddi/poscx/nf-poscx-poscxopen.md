# PosCxOpen function

## Description

PosCxOpen is called to create an open PosCx library instance. This function initializes all resources it needs to manage a single open instance. It should be called from the driver's [EVT_WDF_DEVICE_FILE_CREATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `fileObject` [in]

A handle to a framework file object that identifies the caller associated with the open instance.

### `deviceInterfaceTag` [in]

An identifier used to specify the caller's device interface in a multi-function device. For a single-interface device, this value should be 0.

## Return value

An appropriate NTSTATUS error code that indicates the open instance completion status.