# MINIPORT_SHUTDOWN callback function

## Description

NDIS calls a miniport driver's
*MiniportShutdownEx* function when the system is shutting down. This function puts the miniport into the Shutdown state, where no other callback can occur (including [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt)). For more information about miniport driver states, see [Miniport Adapter States and Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-states-and-operations).

**Note** You must declare the function by using the **MINIPORT_SHUTDOWN** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The driver uses this context area to maintain state information for a miniport adapter.

### `ShutdownAction` [in]

The reason why NDIS called the shutdown function. The following values are valid:

#### NdisShutdownPowerOff

Indicates that NDIS called
*MiniportShutdownEx* because the system is shutting down.

#### NdisShutdownBugCheck

Indicates that NDIS called
*MiniportShutdownEx* because of a system error.

## Remarks

A driver specifies the
*MiniportShutdownEx* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

*MiniportShutdownEx* restores the miniport adapter to a known initial state (the
state before NDIS called the miniport driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function for
the miniport adapter). This makes sure that the miniport adapter is in a known state and ready to be
reinitialized when the computer is restarted after a system shutdown occurs for any reason, including an
unrecoverable system error.

*MiniportShutdownEx* can read or write to I/O ports, memory-mapped device I/O
space, or bus-specific configuration space by calling the
[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata) or
[NdisMSetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetbusdata) function to disable a DMA
engine, disable interrupts, or reset the hardware to a known state so the hardware can be restarted
safely.

If NDIS calls
*MiniportShutdownEx* because of an unrecoverable error, the
*ShutdownAction* parameter is set to
**NdisShutdownBugCheck** and
*MiniportShutdownEx* is running at a high IRQL. In this case, the miniport driver
must not call any
**Ndis*Xxx*** functions except those functions that can be called at any IRQL.

If NDIS calls
*MiniportShutdownEx* because of a user-initiated shutdown,
*MiniportShutdownEx* runs at IRQL = PASSIVE_LEVEL and the miniport driver can
call other
**Ndis*Xxx*** functions.

If NDIS calls *MiniportShutdownEx* because of an unrecoverable error, the *ShutdownAction* parameter is set to **NdisShutdownBugCheck** and *MiniportShutdownEx* is running at a high IRQL. In this case, the miniport driver must not call any **Ndis*Xxx*** functions except those functions that can be called at any IRQL. Starting with NDIS 6.30 miniports, NDIS does not call *MiniportShutdownEx* during a BugCheck unless the miniport provides the **NDIS_MINIPORT_ATTRIBUTES_REGISTER_BUGCHECK_CALLBACK** flag in its adapter registration attributes.

If the value of *ShutdownAction* is **NdisShutdownPowerOff**, the miniport driver may optionally free its resources. However, this is neither required nor encouraged, because the system shutdown makes it unnecessary.

If the value of *ShutdownAction* is **NdisShutdownBugCheck**, the miniport driver must not free its resources.

**Important** If [MiniportHaltEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_halt) causes a system error, then the miniport driver will see a nested call to *MiniportShutdownEx* with *ShutdownAction***NdisShutdownBugCheck**. In this case, *MiniportShutdownEx* should return immediately without doing any work.

### Examples

To define a *MiniportShutdownEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportShutdownEx* function that is named "MyShutdownEx", use the **MINIPORT_SHUTDOWN** type as shown in this code example:

```
MINIPORT_SHUTDOWN MyShutdownEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyShutdownEx(
    NDIS_HANDLE  MiniportAdapterContext,
    NDIS_SHUTDOWN_ACTION  ShutdownAction
    )
  {...}
```

The **MINIPORT_SHUTDOWN** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_SHUTDOWN** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[Adapter States of a Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/network/adapter-states-of-a-miniport-driver)

[Miniport Adapter Shutdown](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-shutdown)

[Miniport Adapter States and Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-states-and-operations)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisMGetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismgetbusdata)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMSetBusData](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetbusdata)