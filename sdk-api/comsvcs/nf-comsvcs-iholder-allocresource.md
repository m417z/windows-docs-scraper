# IHolder::AllocResource

## Description

Allocates a resource from the inventory.

## Parameters

### `__MIDL__IHolder0000` [in]

The type of resource to be allocated.

### `__MIDL__IHolder0001` [out]

A pointer to the location where the handle of the allocated resource is returned.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *ResTypId* is **NULL** or an empty string, or the Resource Dispenser's [IDispenserDriver::CreateResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-createresource) method generated an empty or duplicate RESID. |
| **E_FAIL** | The method failed. The *pResId* parameter has not been set. The likely cause is that the caller's transaction is aborting. |

## Remarks

The Dispenser Manager takes the following steps to locate a resource:

1. Searches the pool for a free resource of this RESTYPID, which is already enlisted in the caller's current transaction.
2. Searches the pool for a free unenlisted resource of this RESTYPID, and then enlists it in the caller's current transaction.
3. Creates the resource by calling back to the Resource Dispenser's [IDispenserDriver::CreateResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-createresource) method, and then enlists it.

If the caller does not have a current transaction, the enlistment is skipped. Or if the Resource Dispenser rejects the enlistment (meaning the resource is not transaction capable), the enlistment is skipped.

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)

[IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder)