# CoCreateFreeThreadedMarshaler function

## Description

Creates an aggregatable object capable of context-dependent marshaling.

## Parameters

### `punkOuter` [in]

A pointer to the aggregating object's controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown).

### `ppunkMarshal` [out]

Address of the pointer variable that receives the interface pointer to the aggregatable marshaler.

## Return value

This function can return the standard return value E_OUTOFMEMORY, as well as the following value.

| Return code | Description |
| --- | --- |
| **S_OK** | The marshaler was created. |

## Remarks

The **CoCreateFreeThreadedMarshaler** function enables an object to efficiently marshal interface pointers between threads in the same process. If your objects do not support interthread marshaling, you have no need to call this function. It is intended for use by free-threaded DLL servers that must be accessed directly by all threads in a process, even those threads associated with single-threaded apartments. It custom-marshals the real memory pointer over into other apartments as a bogus "proxy" and thereby gives direct access to all callers, even if they are not free-threaded.

The **CoCreateFreeThreadedMarshaler** function performs the following tasks:

1. Creates a free-threaded marshaler object.
2. Aggregates this marshaler to the object specified by the *punkOuter* parameter. This object is normally the one whose interface pointers are to be marshaled.

The aggregating object's implementation of [IMarshal](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imarshal) should delegate [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) calls for IID_IMarshal to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the free-threaded marshaler. Upon receiving a call, the free-threaded marshaler performs the following tasks:

1. Checks the destination context specified by the [CoMarshalInterface](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterface) function's *dwDestContext* parameter.
2. If the destination context is MSHCTX_INPROC, copies the interface pointer into the marshaling stream.
3. If the destination context is any other value, finds or creates an instance of COM's default (standard) marshaler and delegates marshaling to it.

Values for *dwDestContext* come from the [MSHCTX](https://learn.microsoft.com/windows/desktop/api/wtypesbase/ne-wtypesbase-mshctx) enumeration. MSHCTX_INPROC indicates that the interface pointer is to be marshaled between different threads in the same process. Because both threads have access to the same address space, the client thread can dereference the pointer directly rather than having to direct calls to a proxy. In all other cases, a proxy is required, so **CoCreateFreeThreadedMarshaler** delegates the marshaling job to COM's default implementation.

Great care should be exercised in using the **CoCreateFreeThreadedMarshaler** function. This is because the performance of objects which aggregate the free-threaded marshaler is obtained through a calculated violation of the rules of COM, with the ever-present risk of undefined behavior unless the object operates within certain restrictions. The most important restrictions are:

* A free-threaded marshaler object cannot hold direct pointers to interfaces on an object that does not aggregate the free-threaded marshaler as part of its state. If the object were to use direct references to ordinary single-threaded aggregate objects, it may break their single threaded property. If the object were to use direct references to ordinary multithreaded aggregate objects, these objects can behave in ways that show no sensitivity to the needs of direct single-threaded aggregate clients. For example, these objects can spin new threads and pass parameters to the threads that are references to ordinary single-threaded aggregate objects.
* A free-threaded marshaler object cannot hold references to proxies to objects in other apartments. Proxies are sensitive to the threading model and can return RPC_E_WRONG_THREAD if called by the wrong client.

## See also

[CoGetInterfaceAndReleaseStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetinterfaceandreleasestream)

[CoMarshalInterThreadInterfaceInStream](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-comarshalinterthreadinterfaceinstream)