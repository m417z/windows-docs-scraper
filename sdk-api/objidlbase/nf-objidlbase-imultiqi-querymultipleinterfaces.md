# IMultiQI::QueryMultipleInterfaces

## Description

Retrieves pointers to multiple supported interfaces on an object.

Calling this method is equivalent to issuing a series of separate [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) calls except that you do not incur the overhead of a corresponding number of RPC calls. In multithreaded applications and distributed environments, keeping RPC calls to a minimum is essential for optimal performance.

## Parameters

### `cMQIs` [in]

The number of elements in the *pMQIs* array.

### `pMQIs` [in, out]

An array of [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures. For more information, see Remarks.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method retrieved pointers to all requested interfaces. |
| **S_FALSE** | The method retrieved pointers to some, but not all, of the requested interfaces. |
| **E_NOINTERFACE** | The method retrieved pointers to none of the requested interfaces. |

## Remarks

The **QueryMultipleInterfaces** method takes as input an array of [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structures. Each structure specifies an interface IID and contains two additional members for receiving an interface pointer and return value.

This method obtains as many requested interface pointers as possible directly from the object proxy. For each interface not implemented on the proxy, the method calls the server to obtain a pointer. Upon receiving an interface pointer from the server, the method builds a corresponding interface proxy and returns its pointer along with pointers to the interfaces it already implements.

### Notes to Callers

A caller should begin by querying the object proxy for the [IMultiQI](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imultiqi) interface. If the object proxy returns a pointer to this interface, the caller should then create a [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structure for each interface it wants to obtain. Each structure should specify an interface IID and set its **pItf** member to **NULL**. Failure to set the **pItf** member to **NULL** will cause the object proxy to ignore the structure.

On return, **QueryMultipleInterfaces** writes the requested interface pointer and a return value into each [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structure in the client's array. The **pItf** member receives the pointer; the **hr** member receives the return value.

If the value returned from a call to **QueryMultipleInterfaces** is S_OK, then pointers were returned for all requested interfaces.

If the return value is E_NOINTERFACE, then pointers were returned for none of the requested interfaces. If the return value is S_FALSE, then pointers to one or more requested interfaces were not returned. In this event, the client should check the **hr** member of each [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structure to determine which interfaces were acquired and which were not.

If a client knows ahead of time that it will be using several of an object's interfaces, it can call **QueryMultipleInterfaces** up front and then, later, if a [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) is done for one of the interfaces already acquired through **QueryMultipleInterfaces**, no RPC call will be necessary.

On return, the caller should check the **hr** member of each [MULTI_QI](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-multi_qi) structure to determine which interface pointers were and were not returned.

The client is responsible for releasing each of the acquired interfaces by calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## See also

[IMultiQI](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imultiqi)