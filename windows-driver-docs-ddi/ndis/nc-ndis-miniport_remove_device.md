# MINIPORT_REMOVE_DEVICE callback function

## Description

The
*MiniportRemoveDevice* function releases resources that the
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function
allocated.

**Note** You must declare the function by using the **MINIPORT_REMOVE_DEVICE** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAddDeviceContext` [in]

A handle for a driver-allocated context area that the miniport driver registered with NDIS in the
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function.

## Remarks

The
*MiniportRemoveDevice* function is an optional function. Miniport drivers that
support MSI-X should specify an entry point for this function in the
[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics) structure.

When NDIS receives a request from the Plug and Play (PnP) manager to remove a device, NDIS calls the
*MiniportRemoveDevice* function.
*MiniportRemoveDevice* should then undo the operations that the
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function
performed.

Miniport adapters might be halted and initialized several times before NDIS calls
*MiniportRemoveDevice*. If NDIS called
*MiniportAddDevice* and it returned NDIS_STATUS_SUCCESS, NDIS will not call
*MiniportAddDevice* for the same miniport adapter before calling
*MiniportRemoveDevice* for that adapter.

NDIS calls
*MiniportRemoveDevice* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportRemoveDevice* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportRemoveDevice* function that is named "MyRemoveDevice", use the **MINIPORT_REMOVE_DEVICE** type as shown in this code example:

```
MINIPORT_REMOVE_DEVICE MyRemoveDevice;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyRemoveDevice(
    NDIS_HANDLE  MiniportAddDeviceContext
    )
  {...}
```

The **MINIPORT_REMOVE_DEVICE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_REMOVE_DEVICE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics)