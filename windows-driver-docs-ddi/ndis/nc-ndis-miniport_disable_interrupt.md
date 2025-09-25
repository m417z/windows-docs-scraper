# MINIPORT_DISABLE_INTERRUPT callback function

## Description

NDIS can call a miniport driver's
*MiniportDisableInterruptEx* handler to disable interrupts for diagnostic and troubleshooting
purposes.

**Note** You must declare the function by using the **MINIPORT_DISABLE_INTERRUPT** type. For more
information, see the following Examples section.

## Parameters

### `MiniportInterruptContext` [in]

A handle to a block of context information. The miniport driver supplied this handle in the
*MiniportInterruptContext* parameter that the miniport driver passed to the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function.

## Remarks

A miniport driver must provide a
*MiniportDisableInterruptEx* handler if the driver calls the
[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex) function
to register an interrupt.

Miniport drivers should disable and enable interrupts as explained in the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) and
[MiniportInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc) reference
pages.

NDIS calls the
[MiniportEnableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_interrupt) and
*MiniportDisableInterruptEx* functions to enable and disable interrupts for diagnostic and
troubleshooting purposes. Typically,
*MiniportEnableInterruptEx* and
*MiniportDisableInterruptEx* access miniport driver resources that are shared by the
[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr) function.
Therefore, NDIS calls these handlers at DIRQL.

### Examples

To define a *MiniportDisableInterruptEx* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportDisableInterruptEx* function that is named "MyDisableInterruptEx", use the **MINIPORT_DISABLE_INTERRUPT** type as shown in this code example:

```
MINIPORT_DISABLE_INTERRUPT MyDisableInterruptEx;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyDisableInterruptEx(
    NDIS_HANDLE  MiniportInterruptContext
    )
  {...}
```

The **MINIPORT_DISABLE_INTERRUPT** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_DISABLE_INTERRUPT** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportEnableInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_enable_interrupt)

[MiniportInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_isr)

[MiniportInterruptDPC](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_interrupt_dpc)

[NDIS_MINIPORT_INTERRUPT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_interrupt_characteristics)

[NdisMRegisterInterruptEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterinterruptex)