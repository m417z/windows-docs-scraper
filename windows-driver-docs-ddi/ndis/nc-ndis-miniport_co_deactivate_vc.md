# MINIPORT_CO_DEACTIVATE_VC callback function

## Description

The
*MiniportCoDeactivateVc* function is required for connection-oriented miniports.
*MiniportCoDeactivateVc* is called by NDIS to indicate that a VC is being marked as unusable.

**Note** You must declare the function by using the **MINIPORT_CO_DEACTIVATE_VC** type. For more
information, see the following Examples section.

## Parameters

### `MiniportVcContext` [in]

Specified the handle to a miniport driver-allocated context area in which the miniport driver
maintains state information per-VC. The miniport driver supplied this handle to NDIS from its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function.

## Return value

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the miniport driver successfully halted any communication across the VC and marked it as unusable. |
| **NDIS_STATUS_PENDING** | Indicates that the miniport driver will complete the request to halt the VC asynchronously. When the miniport driver has completed halting the VC, it must then call [NdisMCoDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcodeactivatevccomplete) to signal NDIS that this operation has been completed. |

## Remarks

*MiniportCoDeactivateVc* communicates with its network adapter to terminate all communication across
this VC (in other words, deprogramming receive or send buffers on the adapter). The miniport driver
should also mark the VC, it its context area, as being inactive to prevent any further communication
across the VC.

There is not a one-to-one relationship between calls to
[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc) and
*MiniportCoDeactivateVc*. While NDIS may call
*MiniportCoActivateVc* multiple times on a single VC, only one call to
*MiniportCoDeactivateVc* is made to shut down a virtual connection. For example, a VC can be reused
for different calls possibly causing multiple calls to
*MiniportCoActivateVc*.

### Examples

To define a *MiniportCoDeactivateVc* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCoDeactivateVc* function that is named "MyCoDeactivateVc", use the **MINIPORT_CO_DEACTIVATE_VC** type as shown in this code example:

```
MINIPORT_CO_DEACTIVATE_VC MyCoDeactivateVc;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoDeactivateVc(
    NDIS_HANDLE  MiniportVcContext
    )
  {...}
```

The **MINIPORT_CO_DEACTIVATE_VC** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CO_DEACTIVATE_VC** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCoActivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_activate_vc)

[NdisMCoDeactivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcodeactivatevccomplete)