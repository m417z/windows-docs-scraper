# IStiUSD::SetNotificationHandle

## Description

A still image minidriver's **IStiUSD::SetNotificationHandle** method specifies an event handle that the minidriver should use to inform the caller of device events.

## Parameters

### `hEvent`

Caller-supplied handle to a Win32 event, created by calling **CreateEvent**.

## Return value

If the operation succeeds, the method should return S_OK. Otherwise, it should return one of the STIERR-prefixed error codes defined in *stierr.h*.

## Remarks

If the driver (and device) supports asynchronous notification of [Still Image Device Events](https://learn.microsoft.com/windows-hardware/drivers/image/still-image-device-events), the minidriver's **IStiUSD::SetNotificationHandle** method is the means by which the event monitor requests the driver to notify it when an event occurs.

If *hEvent* is an event handle, the **IStiUSD::SetNotificationHandle** method should store the handle and use it as an input argument to **SetEvent** (described in the Microsoft Windows SDK documentation). The driver should call **SetEvent** each time a device event is detected, to notify the event monitor that an event has occurred.

If *hEvent* is **NULL**, the method should disable notification of device events.