# IHolder::Close

## Description

Closes the Holder.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This closes a Resource Dispenser's Holder, after which the Resource Dispenser probably released.

Before closing, any remaining inventory is destroyed by calling back to the Resource Dispenser's [IDispenserDriver::DestroyResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-destroyresource) method.

The following sequence describes how to close down a Resource Dispenser:

1. Obtain a reference to the Resource Dispenser (the object that exposes [IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)).
2. Call a method in Resource Dispenser whose implementation calls **IHolder::Close**.
3. **IHolder::Close** destroys any remaining inventory by calling back to Resource Dispenser's [IDispenserDriver::DestroyResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-destroyresource) method.
4. **IHolder::Close** calls the Dispenser Manager to remove this Holder from the Holder list. (If no Holders remain, the Dispenser Manager object deletes itself.)
5. **IHolder::Close** releases its reference to Resource Dispenser's [IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver) interface. This is the reason you need a reference in step 1; otherwise, the Resource Dispenser would delete itself prematurely before the subsequent steps can be completed.
6. **IHolder::Close** returns to the Resource Dispenser.
7. The Resource Dispenser calls [IDispenserDriver::DestroyResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-destroyresource). The Holder now deletes itself.
8. The method called in step 2 now returns.
9. Release your final reference to the Resource Dispenser, which now deletes itself.

Note that the [IDispenserManager::RegisterDispenser](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispensermanager-registerdispenser) method does not call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on its *pDispenserDriver* object, but **IHolder::Close** does perform a [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on *pDispenserDriver*. This can cause the Resource Dispenser object to be destroyed prematurely. To prevent this premature destruction, the caller of **IHolder::Close** must hold a reference to the Resource Dispenser object as described in steps 1 and 5.

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)

[IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder)