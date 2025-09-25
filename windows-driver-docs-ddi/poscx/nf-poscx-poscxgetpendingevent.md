# PosCxGetPendingEvent function

## Description

PosCxGetPendingEvent is called either from the device read callback, or when a new event arrives. The function searches the pending events database for events that are waiting for the caller that issued the request.

It first searches the control pending events database, and then the data pending event database.

## Parameters

### `device` [in]

A handle to a framework device object that represents the device.

### `request` [in]

A handle to a framework request object that represents the read request if **PosCxGetPendingEvent** is called from the device read callback.

## Return value

Possible return values are:

| Return value | Description |
| --- | --- |
| STATUS_SUCCESS | The request was completed by PosCx. The caller must not complete the request in this case. |
| STATUS_PENDING | No events are currently available for the caller. The request will be completed by PosCx in the future. The caller must not complete the request in this case. |
| STATUS_DEVICE_NOT_READY | The PosCx library was not successfully initialized. The caller should complete the request. |
| Other errors | Other appropriate failure error codes. The caller should complete the request. |