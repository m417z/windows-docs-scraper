# IPSFactoryBuffer::CreateStub

## Description

Creates a stub for the remote use of the specified interface.

## Parameters

### `riid` [in]

The identifier of the interface for which a stub is to be created.

### `pUnkServer` [in]

 A controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface; used for aggregation.

### `ppStub` [out]

A pointer to an [IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer) interface pointer to control marshaling.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, E_FAIL, and S_OK.

## See also

[IPSFactoryBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipsfactorybuffer)

[IRpcStubBuffer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irpcstubbuffer)

[Stub](https://learn.microsoft.com/windows/desktop/com/stub)