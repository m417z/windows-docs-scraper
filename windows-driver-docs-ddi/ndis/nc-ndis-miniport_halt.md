# MINIPORT_HALT callback function

## Description

NDIS calls a miniport driver's
*MiniportHaltEx* function to free resources when a miniport adapter is
removed, and to stop the hardware. This function puts the miniport into the Halted state, where no other callback can occur (including [MiniportShutdownEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_shutdown)). For more information about miniport driver states, see [Miniport Adapter States and Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-states-and-operations).

**Note** You must declare the function by using the **MINIPORT_HALT** type. For more information,
see the following Examples section.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

### `HaltAction` [in]

The reason for halting the miniport adapter. It can be one of the following values:

#### NdisHaltDeviceDisabled

NDIS is halting the miniport adapter in response to a Plug and Play (PnP) remove message.

#### NdisHaltDeviceInstanceDeInitialized

NDIS is halting the miniport adapter in response to an intermediate driver calling the
[NdisIMDeInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimdeinitializedeviceinstance) function.

#### NdisHaltDevicePoweredDown

NDIS is halting the miniport adapter because the system is going to a sleeping state.

#### NdisHaltDeviceSurpriseRemoved

The miniport adapter has been surprise removed and the hardware is not present.

#### NdisHaltDeviceFailed

The miniport adapter is being removed because of a hardware failure. Either the miniport driver
called the
[NdisMRemoveMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismremoveminiport) function or a
bus driver did not power up the NIC on resume.

#### NdisHaltDeviceInitializationFailed

NDIS could not initialize the miniport adapter for an unknown reason after the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function completed successfully.

#### NdisHaltDeviceStopped

NDIS is halting the miniport adapter in response to a PnP stop device message.

## Remarks

A driver specifies the
*MiniportHaltEx* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

NDIS can call
*MiniportHaltEx* at any time after a driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
returns successfully. If the driver controls a physical NIC,
*MiniportHaltEx* should stop the NIC. If an NDIS intermediate driver calls the
[NdisIMDeInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimdeinitializedeviceinstance) function, NDIS calls the
*MiniportHaltEx* function for the driver's virtual device.

*MiniportHaltEx* must free all resources that were allocated in
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) for a device.
*MiniportHaltEx* also frees any other resources that the driver allocated in
subsequent operations for that device. The driver must call the reciprocals of the
**Ndis*Xxx*** functions with which it originally allocated the resources. As a general
rule, a
*MiniportHaltEx* function should call the reciprocal
**Ndis*Xxx*** functions in reverse order to the calls the driver made from
*MiniportInitializeEx*.

If a NIC generates interrupts, a miniport driver's
*MiniportHaltEx* function can be preempted by the driver's
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function until the
*MiniportHaltEx* call to the
[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex) function returns. Such a driver's
*MiniportHaltEx* function should disable interrupts, and call
**NdisMDeregisterInterruptEx** as soon as possible. Note that a driver can keep getting interrupts
until
**NdisMDeregisterInterruptEx** returns.
**NdisMDeregisterInterruptEx** does not return until the driver finishes all the scheduled DPCs (see
the
[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) function for
more information).

If the driver has a
[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function) function that is
associated with a timer object that could be in the system timer queue,
*MiniportHaltEx* should call the
[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject) function. If
**NdisCancelTimerObject** fails, the timer could have already fired. In this case, the driver should
wait for the timer function to complete before the driver returns from
*MiniportHaltEx*.

NDIS does not call
*MiniportHaltEx* if there are outstanding OID requests or send requests. NDIS
submits no further requests for the affected device after NDIS calls
*MiniportHaltEx*.

If the driver must wait for any operation to complete,
*MiniportHaltEx* can use the
[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent) function or the
[NdisMSleep](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsleep) function.

NDIS calls
*MiniportHaltEx* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportHaltEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportHaltEx* function that is named "MyHaltEx", use the **MINIPORT_HALT** type as shown in this code example:

```
MINIPORT_HALT MyHaltEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyHaltEx(
    NDIS_HANDLE  MiniportAdapterContext,
    NDIS_HALT_ACTION  HaltAction
    )
  {...}
```

The **MINIPORT_HALT** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_HALT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[Adapter States of a Miniport Driver](https://learn.microsoft.com/windows-hardware/drivers/network/adapter-states-of-a-miniport-driver)

[Halting a Miniport Adapter](https://learn.microsoft.com/windows-hardware/drivers/network/halting-a-miniport-adapter)

[Miniport Adapter States and Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-states-and-operations)

[Miniport Driver Reset and Halt Functions](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff564064(v=vs.85))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[MiniportReturnNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_return_net_buffer_lists)

[NdisCancelTimerObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscanceltimerobject)

[NdisIMDeInitializeDeviceInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisimdeinitializedeviceinstance)

[NdisMDeregisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismderegisterinterruptex)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMRemoveMiniport](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismremoveminiport)

[NdisMSleep](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsleep)

[NdisWaitEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswaitevent)

[NetTimerCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-ndis_timer_function)