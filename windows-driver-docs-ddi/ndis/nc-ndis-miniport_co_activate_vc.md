# MINIPORT_CO_ACTIVATE_VC callback function

## Description

The
*MiniportCoActivateVc* function is required for connection-oriented miniports.
*MiniportCoActivateVc* is called by NDIS to indicate to the miniport driver that a
virtual connection is being activated.

**Note** You must declare the function by using the **MINIPORT_CO_ACTIVATE_VC** type. For more
information, see the following Examples section.

## Parameters

### `MiniportVcContext` [in]

Specifies the handle to a miniport driver-allocated context area in which the miniport driver
maintains its per-VC state. The miniport driver supplied this handle to NDIS from its
*MiniportCoCreateVc* function.

### `CallParameters` [in, out]

Specifies the call parameters, as specified by the call manager, to be established for this VC. On
output, the miniport driver returns altered call parameters if certain flags are set in the
[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85)) structure.

## Return value

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | Indicates that the VC was activated successfully. |
| **NDIS_STATUS_PENDING** | Indicates that the miniport driver will complete the request to activate a VC asynchronously. When the miniport driver has finished with its operations, it must call [NdisMCoActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcoactivatevccomplete). |
| **NDIS_STATUS_INVALID_DATA** | Indicates that the call parameters specified at *CallParameters* are invalid or illegal for the media type that this miniport driver supports. |
| **NDIS_STATUS_RESOURCES** | Indicates that the miniport driver could not activate the VC because it could not allocate all of the required resources that the miniport driver needs to maintain state information about the active VC. |

## Remarks

The miniport driver must validate the call parameters for this VC, as specified in
*CallParameters*, to verify that the adapter can support the requested call. If
the requested call parameters cannot be satisfied, the miniport driver should fail the request with
NDIS_STATUS_INVALID_DATA.

*MiniportCoActivateVc* can be called many times for a single VC in order to
change the call parameters for an already active call. At every call, the miniport driver should validate
the parameters and perform any processing as required by its adapter in order to satisfy the request.
However, if it cannot set the given call parameters,
*MiniportCoActivateVc* must leave the VC in a usable state, because the
connection-oriented client or a call manager can continue to send or receive data using the older call
parameters.

If the ROUND_UP_FLOW or ROUND_DOWN_FLOW flags are set in the call parameters structure at
*CallParameters->MediaParameters->Flags*, the miniport driver has been
requested to return the actual flow rate of the VC after the flow rate has been rounded according to the
appropriate flag that has been set. If the miniport driver does change any of the call parameters because
these flags have been set, it must return the actual call parameters in use for the VC at
*CallParameters*.

If the call parameters are acceptable,
*MiniportCoActivateVc* communicates with its adapter as necessary to prepare the
adapter to receive or transmit data across the virtual connection (in other words, programming receive
buffers).

### Examples

To define a *MiniportCoActivateVc* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportCoActivateVc* function that is named "MyCoActivateVc", use the **MINIPORT_CO_ACTIVATE_VC** type as shown in this code example:

```
MINIPORT_CO_ACTIVATE_VC MyCoActivateVc;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoActivateVc(
    NDIS_HANDLE  MiniportVcContext,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **MINIPORT_CO_ACTIVATE_VC** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_CO_ACTIVATE_VC** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[MiniportCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_create_vc)

[MiniportCoDeactivateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_co_deactivate_vc)

[NdisMCoActivateVcComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcoactivatevccomplete)