# PosCxIsDeviceOwner function

## Description

PosCxIsDeviceOwner checks if the caller currently owns the claim on the device.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `fileObject` [in]

 A handle to a framework file object that identifies the caller, usually acquired with [WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject). If this parameter is NULL, **PosCxIsDeviceOwner** returns TRUE if the device is not currently owned.

## Return value

Returns TRUE if the caller is the device owner, or if *fileObject* is NULL and the device is not currently owned.

Otherwise, returns FALSE.