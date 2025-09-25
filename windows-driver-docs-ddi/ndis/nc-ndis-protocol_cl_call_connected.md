# PROTOCOL_CL_CALL_CONNECTED callback function

## Description

The
*ProtocolClCallConnected* function is used by connection-oriented NDIS clients that accept incoming
calls. Such clients must have
*ProtocolClCallConnected* functions. Otherwise, such a protocol driver's registered
*ProtocolClCallConnected* function can simply return control.

**Note** You must declare the function by using the **PROTOCOL_CL_CALL_CONNECTED** type.
For more information, see the following Examples section.

## Parameters

### `ProtocolVcContext` [in]

Specifies the client's handle to its per-VC context area. The client originally returned this
handle to NDIS from its
[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc) function.

## Remarks

When
*ProtocolClCallConnected* is called, the call manager has successfully completed the final handshake
on an incoming call offer previously accepted by the client's
*ProtocolClIncomingCall* function, which already set up the call parameters for this connection at
*ProtocolVcContext* .

The call to
*ProtocolClCallConnected* indicates that data transfers, whether incoming or outgoing, now can be
done on the VC.
*ProtocolClCallConnected* should ensure that the client is ready to make or accept transfers on the
VC before it returns control.

### Examples

To define a *ProtocolClCallConnected* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *ProtocolClCallConnected* function that is named "MyClCallConnected", use the **PROTOCOL_CL_CALL_CONNECTED** type as shown in this code example:

```
PROTOCOL_CL_CALL_CONNECTED MyClCallConnected;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
VOID
 MyClCallConnected(
    NDIS_HANDLE  ProtocolVcContext
    )
  {...}
```

The **PROTOCOL_CL_CALL_CONNECTED** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **PROTOCOL_CL_CALL_CONNECTED** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[NdisCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscmdispatchcallconnected)

[NdisCoSendNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiscosendnetbufferlists)

[NdisMCmDispatchCallConnected](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismcmdispatchcallconnected)

[ProtocolClIncomingCall](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_cl_incoming_call)

[ProtocolCoCreateVc](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_create_vc)

[ProtocolCoReceiveNetBufferLists](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_co_receive_net_buffer_lists)