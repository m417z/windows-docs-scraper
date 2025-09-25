# PROTOCOL_CL_INCOMING_CLOSE_CALL callback function

## Description

The
*ProtocolClIncomingCloseCall* function is used by all connection-oriented NDIS clients. All such
clients must have fully functional
*ProtocolClIncomingCloseCall* functions.

**Note** You must declare the function by using the **PROTOCOL_CL_INCOMING_CLOSE_CALL** type.
For more information, see the following Examples section.

## Parameters

### `CloseStatus` [in]

Specifies the status that indicates the cause of the connection teardown, which is usually
NDIS_STATUS_SUCCESS to indicate that the remote party to the call requested that the connection be
closed. Any other value indicates that problems on the network caused the call manager to terminate the
connection.

### `ProtocolVcContext` [in]

Specifies the handle to the client's per-VC context area for the VC on which the connection is
being closed. Whatever the value of
*CloseStatus*, the client can neither send nor receive data on the VC designated by the
*NdisVcHandle* that it stored in this context area.

### `CloseData` [in]

Pointer to a buffer containing a protocol-specific close message, possibly one supplied by the
remote client that the call manager received over the network, or this parameter can be **NULL**.

When
*CloseStatus* is NDIS_STATUS_SUCCESS, this parameter is **NULL** if the underlying network medium does
not support transfers of data when closing a connection. However, any particular call manager might
define a structure to pass additional diagnostic information to its clients on call teardowns caused by
problems on the network.

### `Size` [in]

Specifies the size in bytes of the buffer at
*CloseData*, zero if
*CloseData* is **NULL**.

## Remarks

A call to
*ProtocolClIncomingCloseCall* indicates that the one of the following has occurred:

* The call manager has received a request over the network to close an established connection,
  identified by the
  *NdisVcHandle* that the client stored in its per-VC context area at
  *ProtocolVcContext* .
* The call manager has detected that network problems will prevent further data transfers on the
  established connection.

In either case,
*ProtocolClIncomingCloseCall* should carry out any protocol-determined operations, such as notifying
the client's own client(s) that the connection is being broken. For example, if the call to be closed is
a multipoint VC created by the client,
*ProtocolClIncomingCloseCall* must call
[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty) one or more times until
only a single party remains on its multipoint VC.

Whether the given VC is a single-point or multipoint connection,
*ProtocolClIncomingCloseCall* must call
[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall) to acknowledge that the
client will neither attempt to send nor expect to receive data on this particular VC. If the call manager
created this VC,
*ProtocolClIncomingCloseCall* should return control after it calls
**NdisClCloseCall**. It is the responsibility of the call manager to destroy or reuse any VC that it
created.

If the client originally created this VC for an outgoing call,
*ProtocolClIncomingCloseCall* can do one of the following after it calls
**NdisClDropParty** as many times as necessary, if any, and
**NdisClCloseCall**:

* If
  *CloseStatus* is NDIS_STATUS_SUCCESS, tear down the VC with
  [NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc) and either release the
  client's per-VC context area or prepare it for reuse in a subsequent call to
  [NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc).
* If
  *CloseStatus* is NDIS_STATUS_SUCCESS, retain the VC that the client created and prepare its per-VC
  context area for reuse in a subsequent call to
  [NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall).
* Otherwise, tear down the VC with
  **NdisCoDeleteVc** and release its per-VC context area if the call manager indicated that the network
  has become inoperative.

### Examples

To define a *ProtocolClIncomingCloseCall* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClIncomingCloseCall* function that is named "MyClIncomingCloseCall", use the **PROTOCOL_CL_INCOMING_CLOSE_CALL** type as shown in this code example:

```
PROTOCOL_CL_INCOMING_CLOSE_CALL MyClIncomingCloseCall;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClIncomingCloseCall(
    NDIS_STATUS  CloseStatus,
    NDIS_HANDLE  ProtocolVcContext,
    PVOID  CloseData,
    UINT  Size
    )
  {...}
```

The **PROTOCOL_CL_INCOMING_CLOSE_CALL** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_INCOMING_CLOSE_CALL** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisClCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclclosecall)

[NdisClDropParty](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscldropparty)

[NdisClMakeCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisclmakecall)

[NdisCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchincomingclosecall)

[NdisCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscocreatevc)

[NdisCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscodeletevc)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisFreeToNPagedLookasideList](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreetonpagedlookasidelist)

[NdisMCmDispatchIncomingCloseCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchincomingclosecall)

[ProtocolClDropPartyComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_drop_party_complete)

[ProtocolCoDeleteVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_delete_vc)