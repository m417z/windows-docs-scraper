# CoRegisterMallocSpy function

## Description

Registers an implementation of the [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) interface, thereafter requiring OLE to call its wrapper methods around every call to the corresponding [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) method.

## Parameters

### `pMallocSpy` [in]

A pointer to an instance of the [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) implementation.

## Return value

This function can return the standard return value E_INVALIDARG, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was successfully registered. |
| **CO_E_OBJISREG** | The object is already registered. |

## Remarks

The **CoRegisterMallocSpy** function registers the [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) object, which is used to debug calls to [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) methods. The function calls [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the pointer *pMallocSpy* for the interface IID_IMallocSpy. This is to ensure that *pMallocSpy* really points to an implementation of **IMallocSpy**. By the rules of OLE, it is expected that a successful call to **QueryInterface** has added a reference (through the [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) method) to the **IMallocSpy** object. That is, **CoRegisterMallocSpy** does not directly call **AddRef** on *pMallocSpy*, but fully expects that the **QueryInterface** call will.

When the [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) object is registered, whenever there is a call to one of the [IMalloc](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imalloc) methods, OLE first calls the corresponding **IMallocSpy** pre-method. Then, after executing the **IMalloc** method, OLE calls the corresponding **IMallocSpy** post-method. For example, whenever there is a call to [IMalloc::Alloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imalloc-alloc), from whatever source, OLE calls [IMallocSpy::PreAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prealloc), calls **Alloc**, and after that allocation is completed, calls [IMallocSpy::PostAlloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-postalloc).

## See also

[CoGetMalloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetmalloc)

[CoRevokeMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-corevokemallocspy)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)