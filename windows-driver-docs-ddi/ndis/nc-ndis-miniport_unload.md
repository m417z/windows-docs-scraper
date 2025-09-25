# MINIPORT_UNLOAD callback function

## Description

NDIS calls a miniport driver's
*MiniportDriverUnload* function to request the driver to release resources before the system completes
a driver unload operation.

**Note** You must declare the function by using the **MINIPORT_UNLOAD** type. For more
information, see the following Examples section.

## Parameters

### `DriverObject` [in]

A pointer to a
[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object) structure that is the driver's
driver object.

## Remarks

A driver specifies the
*MiniportDriverUnload* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

The driver object that is associated with an NDIS miniport driver specifies an
[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload) routine. The operating system calls the
**Unload** routine when all the devices the miniport driver services have been removed. NDIS provides
the
**Unload** routine for NDIS drivers. NDIS calls a miniport driver's
*MiniportDriverUnload* function from the
**Unload** routine.

The functionality of the
**Unload** routine is driver-specific. As a general rule,
*MiniportDriverUnload* should undo the operations that were performed in the driver's
**DriverEntry** routine.

A miniport driver calls the
[NdisMDeregisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterminiportdriver) function from
*MiniportDriverUnload*.

In addition to
**NdisMDeregisterMiniportDriver**, an intermediate driver also calls the
[NdisDeregisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocoldriver) function to deregister the protocol interface of the driver.
*MiniportDriverUnload* should also perform any necessary cleanup operations, such as deallocating any
protocol driver interface resources.

If a miniport driver manages more than one device instance, such as a load-balancing driver, NDIS will
not call
*MiniportDriverUnload* until after NDIS calls the
[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) function one time for
each device instance.

NDIS calls
*MiniportDriverUnload* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportDriverUnload* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportDriverUnload* function that is named "MyDriverUnload", use the **MINIPORT_UNLOAD** type as shown in this code example:

```
MINIPORT_UNLOAD MyDriverUnload;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyDriverUnload(
    PDRIVER_OBJECT  DriverObject
    )
  {...}
```

The **MINIPORT_UNLOAD** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_UNLOAD** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[DRIVER_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_driver_object)

[MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)

[NdisDeregisterProtocolDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisderegisterprotocoldriver)

[NdisMDeregisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterminiportdriver)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[Unload](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-driver_unload)