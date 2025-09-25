# IInternalUnknown::QueryInternalInterface

## Description

Retrieves pointers to the supported internal interfaces on an object.

## Parameters

### `riid` [in]

The identifier of the internal interface being requested.

### `ppv` [out]

The address of a pointer variable that receives the interface pointer requested in the *riid* parameter. Upon successful return, **ppv* contains the requested interface pointer to the object. If the object does not support the interface, **ppv* is set to **NULL**.

## Return value

This method returns S_OK if the interface is supported, and E_NOINTERFACE otherwise.

## Remarks

This method is similar to the [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method, except that the COM proxy manager, when aggregated, will not expose some interfaces through **QueryInterface**. Instead, those internal interfaces must be exposed through **QueryInternalInterface**.

## See also

[IInternalUnknown](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iinternalunknown)

[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q))