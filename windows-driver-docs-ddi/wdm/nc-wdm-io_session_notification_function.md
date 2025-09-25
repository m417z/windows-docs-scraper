## Description

The IO_SESSION_NOTIFICATION_FUNCTION function type defines a callback routine through which a driver receives notifications of changes in the state of user sessions that the driver is interested in.

## Parameters

### `SessionObject` [in]

Pointer to an opaque, system object that contains information about the user session. The driver can pass this pointer value to the [IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation) routine as the *ContainerObject* parameter value.

### `IoObject` [in]

Pointer to an I/O object owned by the driver. This parameter is the I/O object pointer that the driver supplied to the [IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification) routine when the driver previously registered to receive notifications of session events. The **IoRegisterContainerNotification** routine's *NotificationInformation* parameter points to an [**IO_SESSION_STATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_notification) structure whose **IoObject** member points to the I/O object.

### `Event` [in]

An [IO_SESSION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_event) enumeration constant that indicates which session event caused the notification callback.

### `Context` [in]

The context value that the driver previously supplied to the **IoRegisterContainerNotification** routine when the driver registered to receive notifications of session events. In the **IoRegisterContainerNotification** call, the driver supplied a pointer to an **IO_SESSION_STATE_NOTIFICATION** structure whose **Context** member contains the context value.

### `NotificationPayload` [in]

Pointer to a payload buffer that contains an [**IO_SESSION_CONNECT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_connect_info) structure.

### `PayloadLength` [in]

The size, in bytes, of the buffer pointed to by *NotificationPayload*. The buffer size never needs exceeds the constant value IO_SESSION_MAX_PAYLOAD_SIZE, which is defined in the Wdm.h header file.

## Return value

If the routine succeeds, it must return STATUS_SUCCESS. Otherwise, it must return one of the error status values defined in the Ntstatus.h header file.

## Remarks

A kernel-mode driver implements this routine. The I/O manager calls this routine to notify the driver of session events.

To receive notifications of session events, a driver calls the **IoRegisterContainerNotification** routine and sets this routine's *CallbackFunction* parameter to point to the driver's IO_SESSION_NOTIFICATION_FUNCTION routine. The I/O object that the driver passes to **IoRegisterContainerNotification** determines whether the driver will receive notifications of events in a particular user session or of events in all sessions. For more information, see [IO_SESSION_STATE_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_notification).

### Examples

To define an I/O-session notification routine, you must first provide a function declaration that identifies the type of callback routine you're defining. Windows provides a set of callback function types for drivers. Declaring a function using the callback function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define an I/O-session notification routine that is named `MyIoSessionNotification`, use the IO_SESSION_NOTIFICATION_FUNCTION type as shown in this code example:

```cpp
IO_SESSION_NOTIFICATION_FUNCTION MyIoSessionNotification;
```

Then, implement your callback routine as follows:

```cpp
_Use_decl_annotations_
NTSTATUS
  MyIoSessionNotification(
    PVOID  SessionObject,
    PVOID  IoObject,
    ULONG  Event,
    PVOID  Context,
    PVOID  NotificationPayload,
    ULONG  PayloadLength
    )
  {
      // Function body
  }
```

The IO_SESSION_NOTIFICATION_FUNCTION function type is defined in the Wdm.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the `_Use_decl_annotations_` annotation to your function definition. The `_Use_decl_annotations_` annotation ensures that the annotations that are applied to the IO_SESSION_NOTIFICATION_FUNCTION function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for WDM Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-using-function-role-types-for-wdm-drivers). For information about `_Use_decl_annotations_`, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[**IO_SESSION_CONNECT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_connect_info)

[IO_SESSION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_session_event)

[**IO_SESSION_STATE_NOTIFICATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_session_state_notification)

[IoGetContainerInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iogetcontainerinformation)

[IoRegisterContainerNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioregistercontainernotification)