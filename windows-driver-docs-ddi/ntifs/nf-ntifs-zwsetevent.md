# ZwSetEvent function

## Description

The **ZwSetEvent** routine sets an event object to a Signaled state and attempts to satisfy as many waits as possible.

## Parameters

### `EventHandle` [in]

A handle to an event object.

### `PreviousState` [out, optional]

An optional pointer to a variable where the previous state of the event object is stored on output.

## Return value

**ZwSetEvent** returns STATUS_SUCCESS or an appropriate error status. Possible error status codes include the following:

| Return code | Description |
| --- | --- |
| **STATUS_ACCESS_DENIED** | The caller did not have the required privileges to modify the event specified by the *EventHandle* parameter. |
| **STATUS_INSUFFICIENT_RESOURCES** | Resources required by this function could not be allocated. |
| **STATUS_INVALID_HANDLE** | The supplied *EventHandle* parameter was invalid. |

## Remarks

**ZwSetEvent** sets an event object to a Signaled state and attempts to satisfy as many waits as possible.

**Note** If the call to the **ZwSetEvent** function occurs in user mode, you should use the name "[NtSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwsetevent)" instead of "**ZwSetEvent**".

For calls from kernel-mode drivers, the **Nt*Xxx*** and **Zw*Xxx*** versions of a Windows Native System Services routine can behave differently in the way that they handle and interpret input parameters. For more information about the relationship between the **Nt*Xxx*** and **Zw*Xxx*** versions of a routine, see [Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines).

## See also

[IoCreateNotificationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatenotificationevent)

[IoCreateSynchronizationEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocreatesynchronizationevent)

[KeClearEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keclearevent)

[KeResetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keresetevent)

[KeSetEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesetevent)

[KeWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kewaitforsingleobject)

[Using Nt and Zw Versions of the Native System Services Routines](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-nt-and-zw-versions-of-the-native-system-services-routines)

[ZwClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ntclose)

[ZwCreateEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwcreateevent)

[ZwWaitForSingleObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-zwwaitforsingleobject)