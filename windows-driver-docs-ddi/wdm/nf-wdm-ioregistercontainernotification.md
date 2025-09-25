## Description

The **IoRegisterContainerNotification** routine registers a kernel-mode driver to receive notifications about a specified class of events.

## Syntax

```cpp
NTSTATUS
IoRegisterContainerNotification(
    _In_ IO_CONTAINER_NOTIFICATION_CLASS NotificationClass,
    _In_ PIO_CONTAINER_NOTIFICATION_FUNCTION CallbackFunction,
    _In_reads_bytes_opt_(NotificationInformationLength) PVOID NotificationInformation,
    _In_ ULONG NotificationInformationLength,
    _Out_ PVOID * CallbackRegistration
    );
```

## Parameters

### `NotificationClass` [in]

Specifies the class of events for which the caller (driver) requests notifications. Set this parameter to the following [IO_CONTAINER_NOTIFICATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_container_notification_class) enumeration value:

- **IoSessionStateNotification**

For more information, see the following Remarks section.

### `CallbackFunction` [in]

A pointer to a callback function that is implemented by the caller (driver). The I/O manager calls this function to notify the caller when an event of the class indicated by *NotificationClass* occurs. For *NotificationClass* = **IoSessionStateNotification**, this parameter is a pointer to a caller-supplied [IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function) function. However, the caller should cast this function pointer to type PIO_CONTAINER_NOTIFICATION_FUNCTION to match the parameter type. For more information, see the following Remarks section.

### `NotificationInformation` [in, optional]

A pointer to a caller-allocated buffer that contains the notification information structure for an event of the class specified by *NotificationClass*. For *NotificationClass* = **IoSessionStateNotification**, *NotificationInformation* points to an [**IO_SESSION_STATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_notification) structure. The caller must fill out this structure before it calls **IoRegisterContainerNotification**. During this call, **IoRegisterContainerNotification** copies the data from this structure, and the I/O manager does not access the driver's copy of the structure after the call returns.

### `NotificationInformationLength` [in]

The size, in bytes, of the notification information structure contained in the buffer that is pointed to by *NotificationInformation*. For *NotificationClass* = **IoSessionStateNotification**, set this parameter to **sizeof**(**IO_SESSION_STATE_NOTIFICATION**).

### `CallbackRegistration` [out]

A pointer to a location into which this routine writes the address of a container notification registration object. This object is an opaque, system object in which the I/O manager stores information about the caller's container notification registration. When notifications are no longer required, the caller cancels the registration by passing this object pointer to the [IoUnregisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregistercontainernotification) routine.

## Return value

**IoRegisterContainerNotification** returns STATUS_SUCCESS if the call is successful. Possible error return values include the following:

| Return code | Description |
|---|---|
| **STATUS_INVALID_PARAMETER_1** | Parameter *NotificationClass* is not a valid **IO_CONTAINER_NOTIFICATION_CLASS** enumeration constant. |
| **STATUS_INVALID_PARAMETER_3** | The information in the structure that is pointed to by *NotificationInformation* is incorrect. |
| **STATUS_INVALID_PARAMETER_4** | Parameter *NotificationInformationLength* does not equal the size of the notification information structure that is required for use with the specified *NotificationClass* parameter value. |
| **STATUS_ALREADY_COMMITTED** | The driver is already registered to receive *NotificationClass* notifications of events that are associated with the specified I/O object. |
| **STATUS_INSUFFICIENT_RESOURCES** | The operating system has insufficient resources to create the requested registration. |

## Remarks

This routine can potentially support notifications of events in a variety of event classes. In Windows 7, this routine supports only **IoSessionStateNotification** notifications, which notify a kernel-mode driver of changes in the status of user sessions that the driver is interested in. For user-mode applications, the [WTSRegisterSessionNotification](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotification) function fills a similar role.

The function pointer type for the *CallbackFunction* parameter is defined as follows:

```cpp
typedef NTSTATUS
  (*PIO_CONTAINER_NOTIFICATION_FUNCTION)(
    );
```

The caller should cast the callback function pointer to this type to match the *CallbackFunction* parameter type. **IoRegisterContainerNotification** determines the actual type of the callback function pointer from the *NotificationClass* parameter. For *NotificationClass* = **IoSessionStateNotification**, *CallbackFunction* points to an [IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function) function.

## See also

[IO_CONTAINER_NOTIFICATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_container_notification_class)

[IO_SESSION_NOTIFICATION_FUNCTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_session_notification_function)

[**IO_SESSION_STATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_notification)

[IoUnregisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iounregistercontainernotification)

[WTSRegisterSessionNotification](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtsregistersessionnotification)