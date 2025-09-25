# MINIPORT_CHECK_FOR_HANG callback function

## Description

> [!WARNING]
> The *MiniportCheckForHangEx* and [*MiniportResetEx*](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) callback functions are discouraged for all NDIS 6.83 and later drivers. For more information, see [Check-for-Hang and Reset operations in NDIS 6.83 and later](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations#check-for-hang-and-reset-operations-in-ndis-683-and-later).

NDIS calls a miniport driver's
*MiniportCheckForHangEx* function to check the operational state of the miniport adapter that represents a network interface card (NIC).

**Note** A miniport driver may declare this function by using the **MINIPORT_CHECK_FOR_HANG** type.

**Note** Starting with NDIS 6.30, this function must not be registered for drivers running on low power SoC platforms to avoid negative power impact caused by the periodic [Check-for-Hang](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations) activity.

## Parameters

### `MiniportAdapterContext` [in]

A handle to a context area that the miniport driver allocated in its
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.
The miniport driver uses this context area to maintain state information for a miniport adapter.

## Return value

*MiniportCheckForHangEx* returns **TRUE** if the driver determines that a NIC is not
operating and NDIS should call the driver's [MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function. For more information, see the Remarks section.

## Remarks

A miniport driver specifies the
*MiniportCheckForHangEx* entry point when it calls the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

*MiniportCheckForHangEx* is not required for intermediate drivers.

*MiniportCheckForHangEx* does nothing more than check the internal state of the
NIC and return **TRUE** if it detects that the NIC is not operating correctly.

By default, NDIS calls
*MiniportCheckForHangEx* approximately every two seconds. For this reason, your miniport driver's *MiniportCheckForHangEx* function should return as quickly as possible.

**Note** Starting with NDIS 6.30, a coalescable timer with high tolerance is used for measuring intervals between calls to MiniportCheckForHangEx. Therefore this routine should not be used for any time sensitive operations.

If
*MiniportCheckForHangEx* returns **TRUE**, NDIS calls the miniport driver's
[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function.

If a miniport driver does not complete an OID request within two successive calls to
*MiniportCheckForHangEx*, NDIS can call the driver's
[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset) function. However, to
avoid unnecessary resets, the driver's
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function can extend the check-for-hang time-out interval
by setting an appropriate **CheckForHangTimeInSeconds** value when it calls the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function.

For more information about setting the **CheckForHangTimeInSeconds** time-out value, see [Miniport Adapter Check-for-Hang and Reset Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations).

**Note** Starting with NDIS 6.30, *MiniportCheckForHangEx* must return **TRUE** if the miniport driver detects that the NIC has not completed a pending send request before a time-out period expired. The time-out period is driver-specific, but we recommend using a timeout period of 2 seconds.

*MiniportCheckForHangEx* can be preempted by an interrupt.

NDIS calls
*MiniportCheckForHangEx* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportCheckForHangEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCheckForHangEx* function that is named "MyCheckForHangEx", use the **MINIPORT_CHECK_FOR_HANG** type as shown in this code example:

```
MINIPORT_CHECK_FOR_HANG MyCheckForHangEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
BOOLEAN
 MyCheckForHangEx(
    NDIS_HANDLE  MiniportAdapterContext
    )
  {...}
```

The **MINIPORT_CHECK_FOR_HANG** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CHECK_FOR_HANG** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[Miniport Adapter Check-for-Hang and Reset Operations](https://learn.microsoft.com/windows-hardware/drivers/network/miniport-adapter-check-for-hang-and-reset-operations)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)