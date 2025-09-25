# PROTOCOL_CO_DELETE_VC callback function

## Description

The
*ProtocolCoDeleteVc* function is required. This function tears down the client's or call manager's
state for an established virtual connection that is being closed by the original creator of that VC.

**Note** You must declare the function by using the **PROTOCOL_CO_DELETE_VC** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolVcContext` [in]

Specifies the handle to the client's or call manager's per-VC context area. The protocol
originally supplied this handle from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

## Return value

*ProtocolCoDeleteVc* can return one of the following:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The protocol has released or prepared for reuse all the resources that it originally allocated for the VC. |
| **NDIS_STATUS_NOT_ACCEPTED** | The VC is still active and the protocol has outstanding operations pending on the VC so it could not be destroyed. |
| **NDIS_STATUS_*XXX*** | The protocol failed the VC deletion for a driver-determined reason. |

## Remarks

*ProtocolCoDeleteVc* is the reciprocal of the driver's
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function. In
general, it releases any dynamic resources and structures that the call manager or client previously
allocated to perform operations on the active VC.

When
*ProtocolCoDeleteVc* returns control with NDIS_STATUS_SUCCESS, the
*NdisVcHandle* that its
*ProtocolCoCreateVc* function stored in the area at
*ProtocolVcContext* becomes invalid.

*ProtocolCoDeleteVc* can return any driver-determined NDIS_STATUS_*XXX* to fail the deletion of the VC, but it
cannot return NDIS_STATUS_PENDING. Calls to
*ProtocolCoDeleteVc* are inherently synchronous in nature.

### Examples

To define a *ProtocolCoDeleteVc* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolCoDeleteVc* function that is named "MyCoDeleteVc", use the **PROTOCOL_CO_DELETE_VC** type as shown in this code example:

```
PROTOCOL_CO_DELETE_VC MyCoDeleteVc;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyCoDeleteVc(
    NDIS_HANDLE  ProtocolVcContext
    )
  {...}
```

The **PROTOCOL_CO_DELETE_VC** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CO_DELETE_VC** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingclosecall)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)