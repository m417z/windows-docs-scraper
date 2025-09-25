# IHolder::UntrackResourceS

## Description

Stops tracking a resource (string version).

## Parameters

### `__MIDL__IHolder0007` [in]

The handle of the resource to stop tracking.

### `__MIDL__IHolder0008` [in]

If **TRUE**, caller is requesting that the resource be destroyed, by calling [IDispenserDriver::DestroyResource](https://learn.microsoft.com/windows/desktop/api/comsvcs/nf-comsvcs-idispenserdriver-destroyresource). If **FALSE**, caller destroys the resource.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *SResId* is not a valid resource handle. |
| **E_FAIL** | The method failed. |

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)

[IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder)