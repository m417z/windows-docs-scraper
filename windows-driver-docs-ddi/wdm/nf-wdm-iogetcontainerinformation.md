# IoGetContainerInformation function

## Description

The **IoGetContainerInformation** routine provides information about the current state of a user session.

## Parameters

### `InformationClass` [in]

Specifies the class of events for which the caller (driver) requests information. Set this parameter to the following [IO_CONTAINER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_container_information_class) enumeration value:

* **IoSessionStateInformation**

For more information, see the following Remarks section.

### `ContainerObject` [in, optional]

A pointer to an opaque, system object supplied by the I/O manager. For *InformationClass* = **IoSessionStateInformation**, set this parameter to the *SessionObject* parameter value that is provided by the I/O manager during the call to the driver's [IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function) function.

### `Buffer` [in, out]

A pointer to a caller-allocated buffer into which this routine writes the state information for the event class specified by *InformationClass*. For *InformationClass* = **IoSessionStateInformation**, the routine writes an [IO_SESSION_STATE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_information) structure to the buffer. The buffer must be large enough to contain this structure.

### `BufferLength` [in]

The size, in bytes, of the buffer pointed to by *Buffer*. For *InformationClass* = IoSessionStateInformation, *BufferLength* must be at least **sizeof**(**IO_SESSION_STATE_INFORMATION**).

## Return value

**IoGetContainerInformation** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER_1** | Parameter *InformationClass* is not a valid [IO_CONTAINER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_container_information_class) enumeration constant. |
| **STATUS_INVALID_PARAMETER_2** | Parameter *ContainerObject* is **NULL**. |
| **STATUS_INVALID_PARAMETER_4** | Parameter *BufferLength* is too small for the information class specified by *InformationClass*. |

## Remarks

This routine can potentially support queries for a variety of information classes. In Windows 7, this routine supports only queries for **IoSessionStateInformation** information, which is status information about user sessions.

## See also

[IO_CONTAINER_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_container_information_class)

[IO_CONTAINER_NOTIFICATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_container_notification_class)

[IO_SESSION_STATE_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_information)