## Description

The **ZwOpenEvent** routine opens a handle to an existing named event object with the specified desired access.

## Parameters

### `EventHandle` [out]

A pointer to a variable that will receive the event object handle. The handle includes bookkeeping information, such as a reference count and security context.

### `DesiredAccess` [in]

The [ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask) value that represents the desired types of access for the event object. The following table contains the event-specific ACCESS_MASK values.

| Value | Desired access |
|---|---|
| EVENT_QUERY_STATE | Query the state of the event object. |
| EVENT_MODIFY_STATE | Modify the state of the event object. |
| EVENT_ALL_ACCESS | All possible access rights to the event object. |

### `ObjectAttributes` [in]

A pointer to the object attributes structure that the caller supplied to be used for the specified object. These attributes would include the **ObjectName** and the handle attributes, for example. This parameter is initialized by calling the [InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes) macro.

## Return value

**ZwOpenEvent** returns STATUS_SUCCESS or an appropriate error status. This routine might return one of the following error status codes:

| Return code | Description |
|---|---|
| **STATUS_INSUFFICIENT_RESOURCES** | Resources that this function requires could not be allocated. |
| **STATUS_INVALID_PARAMETER** | The *ObjectAttributes* structure was not supplied or contained an invalid parameter value. |
| **STATUS_OBJECT_NAME_INVALID** | The *ObjectAttributes* parameter contained an **ObjectName** in the [OBJECT_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/ntdef/ns-ntdef-_object_attributes) structure that was invalid. |
| **STATUS_OBJECT_PATH_SYNTAX_BAD** | The object path contained incorrect syntax. For example, the *ObjectAttributes* parameter does not contain a **RootDirectory** member, but the **ObjectName** member in the **OBJECT_ATTRIBUTES** structure is an empty string or does not start with an OBJECT_NAME_PATH_SEPARATOR character. |
| **STATUS_OBJECT_PATH_NOT_FOUND** | The path to the object was not found, indicating that it does not exist. |
| **STATUS_OBJECT_NAME_NOT_FOUND** | The object name was not found, indicating that the object does not exist. |
| **STATUS_PRIVILEGE_NOT_HELD** | The caller did not have the required privilege to create a handle with the access specified in the *DesiredAccess* parameter. |

## Remarks

**ZwOpenEvent** opens an existing named event object and creates a handle to the object with the specified desired access.

**ZwOpenEvent** can open either notification or synchronization events.

Events are used to coordinate execution. File system drivers can use events to enable a caller to wait for completion of the requested operation until the given event is set to the Signaled state.

Notification events can be used to notify one or more threads of execution that an event has occurred. Synchronization events can be used in the serialization of access to hardware between two otherwise unrelated drivers.

If the call to the **ZwOpenEvent** function occurs in user mode, you should use the name "**NtOpenEvent**" instead of "**ZwOpenEvent**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[ACCESS_MASK](https://learn.microsoft.com/windows-hardware/drivers/kernel/access-mask)

[InitializeObjectAttributes](https://learn.microsoft.com/windows/win32/api/ntdef/nf-ntdef-initializeobjectattributes)

[IoCreateNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatenotificationevent)

[IoCreateSynchronizationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesynchronizationevent)

[KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwcreateevent)

[ZwSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetevent)

[ZwWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwwaitforsingleobject)