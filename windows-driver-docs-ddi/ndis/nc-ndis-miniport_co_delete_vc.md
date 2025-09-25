# MINIPORT_CO_DELETE_VC callback function

## Description

The
*MiniportCoDeleteVc* function is required for connection-oriented miniports.
*MiniportCoDeleteVc* indicates that a VC is being torn down and deleted by NDIS.

**Note** You must declare the function by using the **MINIPORT_CO_DELETE_VC** type. For more
information, see the following Examples section.

## Parameters

### `MiniportVcContext` [in]

Specifies the handle to a miniport driver-allocated context area in which the miniport driver
maintains its per-VC state. The miniport driver supplied this handle to NDIS from its
[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc) function.

## Return value

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the miniport driver successfully freed all resources allocated for this VC. |

## Remarks

*MiniportCoDeleteVcmust* be written as a synchronous function and cannot, under any circumstances,
return NDIS_STATUS_PENDING without causing a system-wide failure.

*MiniportCoDeleteVc* frees any resources allocated on a per-VC basis and stored in the context area
*MiniportVcContext* . The miniport driver must also free the
*MiniportVcContext* that is allocated in its
*MiniportCoCreateVc* function.

### Examples

To define a *MiniportCoDeleteVc* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCoDeleteVc* function that is named "MyCoDeleteVc", use the **MINIPORT_CO_DELETE_VC** type as shown in this code example:

```
MINIPORT_CO_DELETE_VC MyCoDeleteVc;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoDeleteVc(
    NDIS_HANDLE  MiniportVcContext
    )
  {...}
```

The **MINIPORT_CO_DELETE_VC** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CO_DELETE_VC** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)