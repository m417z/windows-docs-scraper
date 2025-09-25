# CoRevokeMallocSpy function

## Description

Revokes a registered [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) object.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The object was revoked successfully. |
| **CO_E_OBJNOTREG** | No spy is currently registered. |
| **E_ACCESSDENIED** | A spy is registered but there are outstanding allocations (not yet freed) made while this spy was active. |

## Remarks

The [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) object is released when it is revoked. This release corresponds to the call to [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) in the implementation of the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) function by the [CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy) function. The implementation of the **IMallocSpy** interface should then do any appropriate cleanup.

If the return code is E_ACCESSDENIED, there are still outstanding allocations that were made while the spy was active. In this case, the registered spy cannot be revoked at this time because it may have attached arbitrary headers and/or trailers to these allocations that only the spy knows about. Only the spy's [PreFree](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prefree) (or [PreRealloc](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imallocspy-prerealloc)) method knows how to account for these headers and trailers. Before returning E_ACCESSDENIED, **CoRevokeMallocSpy** notes internally that a revoke is pending. When the outstanding allocations have been freed, the revoke proceeds automatically, releasing the [IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy) object. Thus, it is necessary to call **CoRevokeMallocSpy** only once for each call to [CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy), even if E_ACCESSDENIED is returned.

## See also

[CoRegisterMallocSpy](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coregistermallocspy)

[IMallocSpy](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imallocspy)