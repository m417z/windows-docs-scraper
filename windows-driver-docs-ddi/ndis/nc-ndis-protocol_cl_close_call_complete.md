# PROTOCOL_CL_CLOSE_CALL_COMPLETE callback function

## Description

The
*ProtocolClCloseCallComplete* function is used by connection-oriented NDIS clients. All
connection-oriented NDIS clients must have
*ProtocolClCloseCallComplete* functions to complete the asynchronous operations that they initiate with
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

**Note** You must declare the function by using the **PROTOCOL_CL_CLOSE_CALL_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the client's request to close this call, which can be one of the
following:

#### NDIS_STATUS_SUCCESS

The call manager has successfully closed the call that existed on the given VC and deactivated
the VC.

#### NDIS_STATUS_XXX

The call manager failed the request to close the call for some CM-determined reason, and NDIS
propagated the status returned by its
[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call) function to
the client.

### `ProtocolVcContext` [in]

Specifies the handle to the client's per-VC context area This is the handle that the client
originally passed to NDIS with
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc) or returned to NDIS from
its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

### `ProtocolPartyContext` [in, optional]

Specifies the handle to the client's per-party context area for the last remaining party on the
client-created VC representing a multipoint connection. Otherwise, this parameter is **NULL**.

## Remarks

If the given VC was created by the client and
*Status* is NDIS_STATUS_SUCCESS, the client can now do either of the following:

* Tear down its VC with
  [NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc) and release or prepare for
  reuse the context area(s) it allocated.
* Reinitialize its per-VC context area and reuse its VC to make another connection with
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).

If the VC was created by the call manager, the client should consider the
*NdisVcHandle* invalid when
*ProtocolClCloseCallComplete* is called. The client must not make any further
**NdisCl/Co*Xxx*** calls with this
*NdisVcHandle* . After
*ProtocolClCloseCallComplete* returns control, the call manager can delete its VC, thereby causing a
call to the client's
[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc) function. The
call manager can even dispatch another incoming call on the VC that it created, thereby causing a call to
the client's
[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call) function.

### Examples

To define a *ProtocolClCloseCallComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClCloseCallComplete* function that is named "MyClCloseCallComplete", use the **PROTOCOL_CL_CLOSE_CALL_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_CLOSE_CALL_COMPLETE MyClCloseCallComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClCloseCallComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolVcContext,
    NDIS_HANDLE  ProtocolPartyContext
    )
  {...}
```

The **PROTOCOL_CL_CLOSE_CALL_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_CLOSE_CALL_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmclosecallcomplete)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisMCmCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmclosecallcomplete)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolCmCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_close_call)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)