## Description

The **ExRegisterCallback** routine registers a given callback routine with a given callback object.

## Parameters

### `CallbackObject` [in, out]

A pointer to a callback object obtained from the [ExCreateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatecallback) routine.

### `CallbackFunction` [in]

A pointer to a driver-implemented callback routine, which must be nonpageable. The callback routine must conform to the following prototype:

```cpp
VOID
(*PCALLBACK_FUNCTION ) (
    IN PVOID CallbackContext,
    IN PVOID Argument1,
    IN PVOID Argument2
    );
```

The callback routine parameters are as follows:

#### CallbackContext

A pointer to a driver-supplied context area as specified in the *CallbackContext* parameter of **ExRegisterCallback**.

#### Argument1

A pointer to a parameter defined by the callback object.

#### Argument2

A pointer to a parameter defined by the callback object.

### `CallbackContext` [in, optional]

A pointer to a caller-defined structure of data items to be passed as the context parameter of the callback routine each time it is called. Typically the context is part of the caller's device object extension.

## Return value

**ExRegisterCallback** returns a pointer to a callback registration handle that should be treated as opaque and reserved for system use. This pointer is **NULL** if **ExRegisterCallback** completes with an error.

## Remarks

A driver calls **ExRegisterCallback** to register a callback routine with a specified callback object.

If the object allows only one registered callback routine, and such a routine is already registered, **ExRegisterCallback** returns **NULL**.

Callers of **ExRegisterCallback** must save the returned pointer for use later in a call to [ExUnregisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exunregistercallback). The pointer is required when removing the callback routine from the list of registered callback routines for the callback object.

The meanings of *Argument1* and *Argument2* of the registered callback routine depend on the callback object and are defined by the component that created it. The following are the parameters for the [system-defined callback objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-a-system-defined-callback-object):

### \Callback\SetSystemTime

#### *Argument1* (SetSystemTime)

- Not used.

#### *Argument2* (SetSystemTime)

- Not used.

### \Callback\PowerState**

#### *Argument1* (PowerState)

- A PO_CB_XXX constant value that is cast to type PVOID.

- PO_CB_AC_STATUS — Indicates that the system has changed from A/C to battery power, or vice versa.

- PO_CB_LID_SWITCH_STATE — Indicates that the lid switch has changed states.

- PO_CB_PROCESSOR_POWER_POLICY — Indicates that the system processor power policy has changed.

- PO_CB_SYSTEM_POWER_POLICY — Indicates that the system power policy has changed.

- PO_CB_SYSTEM_STATE_LOCK — Indicates that a system power state change is imminent. Drivers in the paging path can register for this callback to receive early warning of such a change, allowing them the opportunity to lock their code in memory before the power state changes.

#### *Argument2* (PowerState)

A value of **TRUE** or **FALSE** that is cast to type PVOID.

- If *Argument1* is PO_CB_AC_STATUS, *Argument2* is **TRUE** if the computer is currently using an A/C power supply, and is **FALSE** if the computer is running on battery power.

- If *Argument1* is PO_CB_LID_SWITCH_STATE, *Argument2* is **TRUE** if the lid is currently open, and is **FALSE** if the lid is closed.

- If *Argument1* is PO_CB_PROCESSOR_POWER_POLICY, *Argument2* is not used.

- If *Argument1* is PO_CB_SYSTEM_POWER_POLICY, *Argument2* is not used.

- If *Argument1* is PO_CB_SYSTEM_STATE_LOCK, *Argument2* is **FALSE** if the computer is about to exit system power state S0, and is **TRUE** if the computer has just reentered S0.

### \Callback\ProcessorAdd

#### *Argument1* (ProcessorAdd)

- A pointer to a [**KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ke_processor_change_notify_context) structure that describes the processor change notification event. This pointer is cast to type PVOID. The callback routine must not modify the contents of this structure.

#### *Argument2* (ProcessorAdd)

A pointer to a variable that contains an NTSTATUS value. This pointer is cast to type PVOID. Under certain conditions, a callback routine can write an error status value to this variable to indicate why the new processor should not be added. A device driver must not change the value of this variable unless all three of the following conditions are true:

- An error occurs during the processing of the callback routine that should prevent the new processor from being added.

- The value of the **State** member of the [**KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ke_processor_change_notify_context) structure that *Argument1* points to is **KeProcessorAddStartNotify**.

- The NSTATUS variable that *Argument2* points to contains the value STATUS_SUCCESS. That is, the callback routine must not overwrite an error status value that was previously written by another callback notification client.

Starting with Windows Vista, the **\Callback\ProcessorAdd** callback object is available to dynamically track changes in the processor population. The [KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback) routine provides similar information, but additionally supports a KE_PROCESSOR_CHANGE_ADD_EXISTING flag that a driver can use to enumerate the processors in the initial multiprocessor system configuration. For drivers that run in Windows Server 2008 and later versions of Windows, use **KeRegisterProcessorChangeCallback** instead of the **\Callback\ProcessorAdd** callback object, if possible.

For more information about callback objects, see [Callback Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/callback-objects).

The operating system calls registered callback routines at the same IRQL at which the driver that created the callback called the [ExNotifyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exnotifycallback) routine.

## See also

[ExCreateCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatecallback)

[ExNotifyCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exnotifycallback)

[ExUnregisterCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exunregistercallback)

[**KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_ke_processor_change_notify_context)

[KeRegisterProcessorChangeCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keregisterprocessorchangecallback)