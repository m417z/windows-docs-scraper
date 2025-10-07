# WPD\_OPERATION\_STATES enumeration

The **WPD\_OPERATION\_STATES** enumeration values describe the current state of an operation in progress.

## Constants

**WPD\_OPERATION\_STATE\_UNSPECIFIED**

The current operation is in an unspecified state (not set) and unknown.

**WPD\_OPERATION\_STATE\_STARTED**

The operation is started.

**WPD\_OPERATION\_STATE\_RUNNING**

The operation is running.

**WPD\_OPERATION\_STATE\_PAUSED**

The operation is paused.

**WPD\_OPERATION\_STATE\_CANCELLED**

The operation is canceled.

**WPD\_OPERATION\_STATE\_FINISHED**

The operation is finished.

**WPD\_OPERATION\_STATE\_ABORTED**

The operation is aborted.

## Remarks

These values are received in the application-defined callback ([**IPortableDeviceEventCallback**](https://learn.microsoft.com/windows/desktop/api/PortableDeviceApi/nn-portabledeviceapi-iportabledeviceeventcallback)).

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------------|
| Header<br> | PortableDevice.h |

## See also

[**Structures and Enumeration Types**](https://learn.microsoft.com/windows/win32/wpd_sdk/structures-and-enumeration-types)

