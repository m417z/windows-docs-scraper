# MIDL_STUB_DESC structure

## Description

The **MIDL_STUB_DESC** structure is a MIDL-generated structure that contains information about the interface stub regarding RPC calls between the client and server.

## Members

### `RpcInterfaceInformation`

For a nonobject RPC interface on the server-side, it points to an RPC server interface structure. On the client-side, it points to an RPC client interface structure. It is null for an object interface.

### `pfnAllocate`

Memory allocation function to be used by the stub. Set to [midl_user_allocate](https://msdn.microsoft.com/) for nonobject interface and  [NdrOleAllocate](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-ndroleallocate) for object interface.

### `pfnFree`

Memory-free function to be used by the stub. Set to [midl_user_free](https://learn.microsoft.com/windows/desktop/Midl/midl-user-free-1) for nonobject interface and  [NdrOleFree](https://learn.microsoft.com/windows/desktop/api/rpcndr/nf-rpcndr-ndrolefree) for object interface.

### `IMPLICIT_HANDLE_INFO`

The union contains one of the following handles.

### `IMPLICIT_HANDLE_INFO.pAutoHandle`

Pointer to the implicit auto handle for the RPC call.

### `IMPLICIT_HANDLE_INFO.pPrimitiveHandle`

Pointer to the implicit primitive handle for the RPC call.

### `IMPLICIT_HANDLE_INFO.pGenericBindingInfo`

Pointer to the information about the implicit generic handle.

### `apfnNdrRundownRoutines`

Array of context handle rundown functions.

### `aGenericBindingRoutinePairs`

Array of function pointers to bind and unbind function pairs for the implicit generic handle.

### `apfnExprEval`

Array of function pointers to expression evaluator functions used to evaluate MIDL complex conformance and varying descriptions. For example, [size_is](https://learn.microsoft.com/windows/desktop/Midl/size-is)(param1 + param2).

### `aXmitQuintuple`

Array of an array of function pointers for user-defined [transmit_as](https://learn.microsoft.com/windows/desktop/Midl/transmit-as) and [represent_as](https://msdn.microsoft.com/) types.

### `pFormatTypes`

Pointer to the type format description.

### `fCheckBounds`

Flag describing the user-specified [/error](https://learn.microsoft.com/windows/desktop/Midl/-error) MIDL compiler option.

### `Version`

NDR version required for the stub.

### `pMallocFreeStruct`

Pointer to the MALLOC_FREE_STRUCT structure which contains the allocate and free function pointers. Use if the [enable_allocate](https://learn.microsoft.com/windows/desktop/Midl/enable-allocate) MIDL attribute is specified.

### `MIDLVersion`

Version of the MIDL compiler used to compile the .idl file.

### `CommFaultOffsets`

Array of stack offsets for parameters with [comm_status](https://learn.microsoft.com/windows/desktop/Midl/comm-status) or [fault_status](https://msdn.microsoft.com/) attributes.

### `aUserMarshalQuadruple`

Array of an array of function pointers for user-defined [user_marshal](https://learn.microsoft.com/windows/desktop/Midl/user-marshal) and [wire_marshal](https://learn.microsoft.com/windows/desktop/Midl/wire-marshal) types.

### `NotifyRoutineTable`

Array of notification function pointers for methods with the [notify](https://learn.microsoft.com/windows/desktop/Midl/notify) or [notify_flag](https://learn.microsoft.com/windows/desktop/Midl/notify-flag) attribute specified.

### `mFlags`

Flag describing the attributes of the stub

| Value | Meaning |
| --- | --- |
| **RPCFLG_HAS_MULTI_SYNTAXES** | Set if the stub supports multiple transfer syntaxes. |
| **RPCFLG_HAS_CALLBACK** | Set if the interface contains callback functions. |
| **RPC_INTERFACE_HAS_PIPES** | Set if the interface contains a method that uses pipes. |

### `CsRoutineTables`

Unused.

### `ProxyServerInfo`

### `pExprInfo`

#### - Reserved4

Unused.

#### - Reserved5

Unused.