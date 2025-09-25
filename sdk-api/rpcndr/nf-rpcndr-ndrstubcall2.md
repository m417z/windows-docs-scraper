# NdrStubCall2 function

## Description

The **NdrStubCall2** function is the server-side entry point for [/Oicf](https://learn.microsoft.com/windows/desktop/Midl/-oi) mode stubs.

## Parameters

### `pThis` [in]

Pointer to an instance of the CStdStubBuffer object, implementing [IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer), for the DCOM interface. Set to **NULL** for nonobject RPC interfaces.

### `pChannel` [in]

Pointer to [IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer) for the DCOM interface, often provided by OLE. Set to **NULL** for nonobject interfaces.

### `pRpcMsg` [in, out]

Pointer to an [RPC_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcdcep/ns-rpcdcep-rpc_message) structure that contains information about the RPC request. In nonobject interfaces, *pRpcMsg* also contains information about the remoting method.

### `pdwStubPhase` [out]

Pointer to a flag that tracks the current interpreter call's activity.

## Return value

Returns S_OK upon success. Raises an exception upon error.

## Remarks

The RPC run-time or OLE run-time calls **NdrStubCall2** to invoke the server manager routine. The [out] parameters are marshalled and returned to RPC run-time or OLE run-time to send back to the client.

The *pdwStubPhase* parameter is used by the object interface to determine exception handling behavior. The following table describes possible values for the *pdwStubPhase* parameter.

| Value | Description |
| --- | --- |
| STUB_UNMARSHAL | The stub is in marshalling phase. |
| STUB_CALL_SERVER | The stub is calling a server manager routine. |
| STUB_MARSHAL | The stub is in unmarshalling phase. |
| STUB_CALL_SERVER_NO_HRESULT | Obsolete. For deprecated stubs only. |