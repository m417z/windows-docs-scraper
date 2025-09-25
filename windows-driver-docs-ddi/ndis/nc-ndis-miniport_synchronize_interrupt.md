# MINIPORT_SYNCHRONIZE_INTERRUPT callback function

## Description

A miniport driver must provide a
*MiniportSynchronizeInterrupt* handler if any driver function that runs at less than DIRQL shares
resources with the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function.

For message signaled interrupts, the miniport driver provides a *MiniportSynchronizeMessageInterrupt* handler if any driver function that runs at less than DIRQL shares resources for a message signaled interrupt with the [MiniportMessageInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_message_interrupt) function.

**Note** You must declare this function by using either the **MINIPORT_SYNCHRONIZE_INTERRUPT** type for non-message signaled interrupts, or by using the **MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT** type for message signaled interrupts. For
more information, see the following Examples section.

## Parameters

### `SynchronizeContext` [in]

A handle to a context area that is supplied when the miniport driver's
*MiniportXxx* or internal function called the
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) function.

## Return value

*MiniportSynchronizeInterrupt* returns a Boolean value with a driver-determined meaning. NDIS
returns the same value when NDIS returns from
**NdisMSynchronizeWithInterruptEx**.

## Remarks

**Note** The information in this section can also apply to message signaled interrupts by substituting "MiniportInterrupt" for "MiniportMessageInterrupt," and by substituting "MiniportSynchronizeInterrupt" for "MiniportSynchronizeMessageInterrupt."

If any miniport driver function that runs at less than DIRQL shares resources, such as NIC registers,
with the driver's
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function, that
driver cannot access those resources directly. If such a lower priority function attempts to access the
shared resources directly, it might be preempted by
*MiniportInterrupt*, which could override the state changes of the lower priority driver function.

To synchronize access to shared resources with
*MiniportInterrupt*, lower priority driver functions must call the
[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex) function. The driver's
*MiniportSynchronizeInterrupt* function accesses the shared resources at DIRQL. Calling
**NdisMSynchronizeWithInterruptEx** prevents race conditions and deadlocks in such a miniport
driver.

Any lower priority driver functions that share resources among themselves (but not with any function
that runs at DIRQL) should use a spin lock to protect those shared resources.

*MiniportSynchronizeInterrupt* runs at the DIRQL assigned when the driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
calls the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function. Like any driver function that runs at DIRQL,
*MiniportSynchronizeInterrupt* should return control back to the caller as quickly as possible, and
it can call only those
**Ndis*Xxx*** functions that are safe to call at any IRQL.

### Examples

To define a *MiniportSynchronizeInterrupt* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportSynchronizeInterrupt* function that is named "MySynchronizeInterrupt", use the **MINIPORT_SYNCHRONIZE_INTERRUPT** type as shown in this code example:

```
MINIPORT_SYNCHRONIZE_INTERRUPT MySynchronizeInterrupt;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
BOOLEAN
 MySynchronizeInterrupt(
    NDIS_HANDLE  SynchronizeContext
    )
  {...}
```

To define a *MiniportSynchronizeMessageInterrupt* function for message signaled interrupts, use the **MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT** type as shown in this code example:

```
MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT MySynchronizeMessageInterrupt;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
BOOLEAN
 MySynchronizeMessageInterrupt(
    NDIS_HANDLE  SynchronizeContext
    )
  {...}
```

The **MINIPORT_SYNCHRONIZE_INTERRUPT** and **MINIPORT_SYNCHRONIZE_MESSAGE_INTERRUPT** function types are defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definitions. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportInetrrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)

[NdisMSynchronizeWithInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsynchronizewithinterruptex)