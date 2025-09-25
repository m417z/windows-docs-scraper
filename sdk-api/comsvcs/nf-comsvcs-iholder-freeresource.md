# IHolder::FreeResource

## Description

Returns a resource to the inventory.

## Parameters

### `__MIDL__IHolder0002` [in]

The handle of the resource to be freed.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *ResTypId* is not a valid resource handle. |
| **E_FAIL** | The method failed. The resource has not been freed. |

## Remarks

A resource originally returned by [IHolder::AllocResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-iholder-allocresource) is returned to the pool. This notifies the Resource Dispenser through [IDispenserDriver::ResetResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-resetresource), which is the Resource Dispenser's opportunity to prepare the resource before it is returned to the pool.

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)

[IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder)