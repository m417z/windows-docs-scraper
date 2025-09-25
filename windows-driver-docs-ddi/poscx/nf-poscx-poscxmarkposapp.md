## Description

PosCxMarkPosApp marks the open instance as associated or not associated with a point-of-service application.

This optional method provides value if the driver implements multiple device interfaces. It helps to identify which interface is currently in use.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `fileObject` [in]

A handle to a framework file object that identifies the caller, usually acquired with [WdfRequestGetFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfrequest/nf-wdfrequest-wdfrequestgetfileobject).

### `isPosApp` [in]

Specifies if the open instance is associated with a point-of-service application. Set to TRUE if it is associated with a point-of-service application. Otherwise, set to FALSE.

## Return value

Possible return values are:

| Value | Description |
|---|---|
| **STATUS_SUCCESS** | Completed successfully. |
| **INVALID_PARAMETER** | The specified *fileObject* is invalid. |