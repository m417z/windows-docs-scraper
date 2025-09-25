## Description

PosCxRetainDevice is called to extend the ownership of the device.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `request` [in]

A handle to a framework request object that represents the request. This request must come from a WDF IO queue. The caller must always complete the request.

## Return value

Possible return values are:

| Value | Description |
|---|---|
| **STATUS_SUCCESS** | The device was retained successfully. |
| **STATUS_ACCESS_DENIED** | The calling thread is not the owner of the device. |
| **STATUS_DEVICE_NOT_READY** | The PosCx library was not successfully initialized. |