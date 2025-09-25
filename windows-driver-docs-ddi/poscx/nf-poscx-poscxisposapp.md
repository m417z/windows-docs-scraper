# PosCxIsPosApp function

## Description

PosCxIsPosApp checks if the open instance is associated with a point-of-service application.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `fileObject` [in]

A handle to a framework file object that identifies the caller, usually acquired with [WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject).

## Return value

Returns TRUE if *fileObject* is associated with a point-of-service application. Otherwise, returns FALSE.