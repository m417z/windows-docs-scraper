# IHolder::TrackResource

## Description

Tracks the resource.

## Parameters

### `__MIDL__IHolder0003` [in]

The handle of the resource to be tracked. The Resource Dispenser has already created this resource before calling **TrackResource**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *ResId* is not a valid resource handle. |
| **E_FAIL** | The method failed. The resource has not been tracked. The likely cause is that the caller's transaction is aborting. |

## Remarks

Some resources are not kept in inventory; they are always manufactured on demand. The Holder is used only as a mechanism to automatically free the resources left at the end of an object's lifetime.

TrackResource tells the Holder that a resource should be tracked until it is freed by calling [IHolder::UntrackResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iholder-untrackresource), or until the object that called **TrackResource** is released, at which time the Dispenser Manager automatically frees the resource.

If **TrackResource** is called from a transactional object, it calls back to the Resource Dispenser's [IDispenserDriver::EnlistResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-enlistresource) method. The **EnlistResource** method can enlist the resource in the transaction, or it can return S_FALSE, indicating that the resource is not transaction capable and has not been enlisted.

This resource is eventually destroyed after both of the following are true:

* The Resource Dispenser calls [IHolder::UntrackResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iholder-untrackresource) (most likely at the component's request), or the object's lifetime ends.
* The transaction that the resource was enlisted in (if any) is done.

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)

[IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder)