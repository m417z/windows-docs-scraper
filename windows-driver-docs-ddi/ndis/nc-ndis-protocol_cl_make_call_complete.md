# PROTOCOL_CL_MAKE_CALL_COMPLETE callback function

## Description

The
*ProtocolClMakeCallComplete* function is used by connection-oriented NDIS clients that make outgoing
calls. Such clients must have
*ProtocolClMakeCallComplete* functions to complete the asynchronous operations that they initiate with
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall). Otherwise, such a protocol
driver's registered
*ProtocolClMakeCallComplete* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_MAKE_CALL_COMPLETE** type.
For more information, see the following Examples section.

## Parameters

### `Status` [in]

Specifies the final status of the client's original call to
**NdisClMakeCall**, which can be one of the following:

#### NDIS_STATUS_SUCCESS

The client's attempt to set up a virtual connection succeeded. Consequently, the client can
proceed to make transfers on the active VC using the
*NdisVcHandle* returned by
[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc), which the client has
stored in its per-VC context area at
*ProtocolVcContext* .

#### NDIS_STATUS_RESOURCES

NDIS, the call manager, or an underlying driver could not allocate sufficient resources to set
up the connection.

#### NDIS_STATUS_XXX

The call manager or underlying miniport driver failed to establish an active connection and NDIS
propagated this driver-determined failure status to the client.

### `ProtocolVcContext` [in]

Specifies the handle to the client's per-VC context area, which the client originally supplied to
NDIS when it called
**NdisCoCreateVc** to set up the VC for its outgoing call.

### `NdisPartyHandle` [in, optional]

If
*Status* is NDIS_STATUS_SUCCESS and the client created a multipoint VC by passing an explicit
*ProtocolPartyContext* handle to
[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall), this is a valid
*NdisPartyHandle* . Otherwise, this parameter is **NULL**.

*ProtocolClMakeCallComplete* must save any valid input
*NdisPartyHandle*, usually in the client's per-party context area. The client must use this handle
if (or when) it makes a subsequent call to
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty) or
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall) that refers to this
party.

### `CallParameters` [in]

Pointer to a buffered CO_CALL_PARAMETERS structure. The client allocated this buffer and
initialized this structure with client-determined data before passing this pointer to
**NdisClMakeCall**. While processing the client's request, the call manager can modify this data to
reflect the results of its negotiation with the network or with a signaling peer.

## Remarks

A call to
*ProtocolClMakeCallComplete* indicates that the call manager has completed processing the client's
request to establish a virtual connection with
**NdisClMakeCall**.

If the client's attempt to establish an outgoing call is unsuccessful (input
*Status* is anything except NDIS_STATUS_SUCCESS),
*ProtocolClMakeCallComplete* should do the following:

* Release or prepare for reuse the
  *ProtocolPartyContext* area, if any, and the buffer at
  *CallParameters* that the client allocated.
* Tear down the client-created VC with a call to
  [NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc) and release or prepare for
  reuse the client-allocated
  *ProtocolVcContext* area.

Otherwise,
*ProtocolClMakeCallComplete* should do the following:

1. Check the
   **Flags** member of the structure at
   *CallParameters* to see whether CALL_PARAMETERS_CHANGED is set, which indicates that the call
   manager modified the client-supplied call parameters.
2. If so, examine the data at
   *CallParameters* to determine whether they are acceptable for this connection.

   For example, the client might retain the buffered call parameters for the active VC, save the
   *NdisPartyHandle* if this is a multipoint VC, and generally make the client ready for subsequent
   transfers and other operations on the active VC if it finds the given call parameters satisfactory.
3. If not, the signaling protocol determines whether the client can attempt to renegotiate for
   acceptable call parameters with the call manager.

   For example, a particular call manager might allow its clients to call
   [NdisClModifyCallQoS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmodifycallqos) one or more
   times in these circumstances.
4. If the CM-modified call parameters are unacceptable and further renegotiation is impossible,
   *ProtocolClMakeCallComplete* must tear down the call with
   [NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall).

   In this case,
   *ProtocolClMakeCallComplete* should
   not attempt to release any client-allocated resources on return from
   **NdisClCloseCall** but can simply return control. Instead, the client should release the resources
   it allocated (or prepare them for reuse) within its
   *ProtocolClCloseCallComplete* function.

### Examples

To define a *ProtocolClMakeCallComplete* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClMakeCallComplete* function that is named "MyClMakeCallComplete", use the **PROTOCOL_CL_MAKE_CALL_COMPLETE** type as shown in this code example:

```
PROTOCOL_CL_MAKE_CALL_COMPLETE MyClMakeCallComplete;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClMakeCallComplete(
    NDIS_STATUS  Status,
    NDIS_HANDLE  ProtocolVcContext,
    NDIS_HANDLE  NdisPartyHandle,
    PCO_CALL_PARAMETERS  CallParameters
    )
  {...}
```

The **PROTOCOL_CL_MAKE_CALL_COMPLETE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_MAKE_CALL_COMPLETE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[CO_CALL_PARAMETERS](https://learn.microsoft.com/previous-versions/windows/hardware/network/ff545384(v=vs.85))

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmmakecallcomplete)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisMCmMakeCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmmakecallcomplete)

[ProtocolClCloseCallComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_close_call_complete)

[ProtocolCmMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cm_make_call)