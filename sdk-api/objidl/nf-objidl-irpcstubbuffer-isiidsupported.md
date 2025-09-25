# IRpcStubBuffer::IsIIDSupported

## Description

Determines whether a stub is designed to handle the unmarshaling of a particular interface.

## Parameters

### `riid` [in]

The IID of the interface. This parameter cannot be IID_IUnknown.

## Return value

If the stub can handle the indicated interface, then this method returns an [IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer) pointer for that interface; otherwise, it returns **NULL**.

## Remarks

When presented with the need to remote a new IID on a given object, the RPC run time typically calls this method on all the presently-connected interface stubs in an attempt to locate one that can handle the marshaling for the request before it goes to the trouble of creating a new stub.

As in [IPSFactoryBuffer::CreateStub](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ipsfactorybuffer-createstub), if a stub is presently connected to a server object, then not only must this method verify that the stub can handle the indicated interface, but it must also verify (using [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q))) that the connected server object in fact supports the indicated interface. Depending on the IID and previous interface servicing requests, it may have already done so.

## See also

[IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer)