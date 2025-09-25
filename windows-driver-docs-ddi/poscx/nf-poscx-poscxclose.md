# PosCxClose function

## Description

PosCxClose is called to delete an opened PosCx library instance. This function releases the device if the caller is the owner, and cancels pending requests. It should be called from the driver's [EVT_WDF_FILE_CLOSE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `fileObject` [in]

A handle to a framework file object that identifies the caller associated with the open instance.

## Return value

An appropriate NTSTATUS error code that indicates the close instance completion status.