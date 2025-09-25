# ZwCreateEvent function

## Description

The **ZwCreateEvent** routine creates an event object, sets the initial state of the event to the specified value, and opens a handle to the object with the specified desired access.

## Parameters

### `EventHandle` [out]

A pointer to a variable that will receive the event object handle. The handle includes bookkeeping information, such as a reference count and security context.

### `DesiredAccess` [in]

The [**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the desired types of access for the event object. The following table contains the event-specific ACCESS_MASK values.

| Value | Desired access |
| ----- | -------------- |
| EVENT_QUERY_STATE | Query the state of the event object. |
| EVENT_MODIFY_STATE | Modify the state of the event object. |
| EVENT_ALL_ACCESS | All possible access rights to the event object. |

### `ObjectAttributes` [in, optional]

A pointer to the object attributes structure supplied by the caller to be used for the specified object. These attributes would include the **ObjectName** and the [**SECURITY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_security_descriptor), for example. This parameter is initialized by calling the [**InitializeObjectAttributes**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro.

### `EventType` [in]

The type of the event, which can be **SynchronizationEvent** or a **NotificationEvent**. These values belong to the **EVENT_TYPE** enumeration, which is defined in the *ntdef.h* header file.

### `InitialState` [in]

The initial state of the event object. Set to **TRUE** to initialize the event object to the Signaled state. Set to **FALSE** to initialize the event object to the not-Signaled state.

## Return value

**ZwCreateEvent** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| ----------- | ----------- |
| **STATUS_INSUFFICIENT_RESOURCES** | Resources required by this function could not be allocated. |
| **STATUS_INVALID_PARAMETER** | The supplied *ObjectAttributes* structure contained an invalid parameter value. |
| **STATUS_INVALID_PARAMETER_4** | The specified *EventType* parameter was invalid. |
| **STATUS_OBJECT_NAME_INVALID** | The *ObjectAttributes* parameter contained an **ObjectName** in the [**OBJECT_ATTRIBUTES**](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that was invalid. |
| **STATUS_OBJECT_PATH_SYNTAX_BAD** | The *ObjectAttributes* parameter did not contain a **RootDirectory** member, but the **ObjectName** member in the **OBJECT_ATTRIBUTES** structure was an empty string or did not contain an OBJECT_NAME_PATH_SEPARATOR character. This indicates incorrect syntax for the object path. |
| **STATUS_PRIVILEGE_NOT_HELD** | The caller did not have the required privilege to create a handle with the access specified in the *DesiredAccess* parameter. |

## Remarks

**ZwCreateEvent** creates an event object, sets its initial state to the specified value, and opens a handle to the object with the specified desired access.

Events are used to coordinate execution. Events can be used by file system drivers to allow a caller to wait for completion of the requested operation until the given event is set to the Signaled state.

**ZwCreateEvent** can create either notification or synchronization events:

- Notification events can be used to notify one or more threads of execution that an event has occurred.
- Synchronization events can be used in the serialization of access to hardware between two otherwise unrelated drivers.

A synchronization event is auto-resetting. When a synchronization event is set to the Signaled state, a single thread of execution that was waiting for the event to be signaled is released, and the event is automatically reset to the Not-Signaled state.

Unlike a synchronization event, a notification event is not auto-resetting. Once a notification event is in the Signaled state, it remains in that state until it is explicitly reset.

To synchronize on a notification event:

1. Create the notification event with **ZwCreateEvent** with the *EventType* parameter set to **NotificationEvent**.

2. Wait for the event to be signaled by calling [**ZwWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwwaitforsingleobject) with the *EventHandle* returned by **ZwCreateEvent**. More than one thread of execution can wait for a given notification event to be signaled. To poll instead of stall, specify a *Timeout* of zero to **ZwWaitForSingleObject**.

3. Close the handle to the notification event with [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) when access to the event is no longer needed.

The **ZwCreateEvent** function is called after the **InitializeObjectAttributes** macro is used to set attributes in the **OBJECT_ATTRIBUTES** structure for the object.

There are two alternate ways to specify the name of the object passed to **ZwCreateEvent**:

- As a fully qualified pathname, supplied in the **ObjectName** member of the input *ObjectAttributes*.

- As pathname relative to the directory represented by the handle in the **RootDirectory** member of the input *ObjectAttributes*.

To release the event, a driver calls [**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose) with the event handle.

For more information about events, see [**Event Objects**](https://learn.microsoft.com/windows-hardware/drivers/kernel/event-objects).

> [!NOTE]
>
> If the call to the **ZwCreateEvent** routine occurs in user mode, you should use the name "**NtCreateEvent**" instead of "**ZwCreateEvent**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[**ACCESS_MASK**](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[**InitializeObjectAttributes**](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[**IoCreateNotificationEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatenotificationevent)

[**IoCreateSynchronizationEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesynchronizationevent)

[**KeClearEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[**KeResetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[**KeSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[**KeWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[**ZwClose**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[**ZwSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetevent)

[**ZwWaitForSingleObject**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwwaitforsingleobject)