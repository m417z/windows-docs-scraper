# NdrStubForwardingFunction function

## Description

The **NdrStubForwardingFunction** function is the entry point for server-side object methods that are defined in a base interface.

## Parameters

### `This` [in]

Pointer to an instance of the CStdStubBuffer object, implementing [IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer), for the DCOM interface.

### `pChannel` [in]

Pointer to [IRpcChannelBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcchannelbuffer) for the DCOM interface, often provided by OLE.

### `pmsg` [in, out]

Pointer to an [RPC_MESSAGE](https://learn.microsoft.com/windows/desktop/api/rpcdcep/ns-rpcdcep-rpc_message) structure that contains information about the RPC request.

### `pdwStubPhase` [out]

Pointer to a flag that tracks the current interpreter call's activity.

## Remarks

The *pdwStubPhase* parameter is used by the object interface to determine exception handling behavior. The following table describes possible values for the *pdwStubPhase* parameter.

| Value | Description |
| --- | --- |
| STUB_UNMARSHAL | The stub is in marshalling phase. |
| STUB_CALL_SERVER | The stub is calling a server manager routine. |
| STUB_MARSHAL | The stub is in unmarshalling phase. |
| STUB_CALL_SERVER_NO_HRESULT | Obsolete. For deprecated stubs only. |

For methods that are defined in a base interface, RPC needs to forward the code to the base interface implementation.

For example:

```cpp
Interface IFunctionSample: IUnknown

{

HRESULT FunctionSample();

}

Interface IOperation: IFunctionSample

{

HRESULT Operation();

}

```

In this example, where **IFunctionSample** and **IOperation** are defined in different .idl files. **IFunctionSample** is the base interface and **IOperation** is the derived interface. **IOperation** can aggregate **IOperation** without implementing **IOperation::FunctionSample**. When the client calls **IOperation::FunctionSample**, in the server side, RPC forwards the call to **IFunctionSample:FunctionSample**.