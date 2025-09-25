# IHolder::TrackResourceS

## Description

Tracks the resource (string version).

## Parameters

### `__MIDL__IHolder0004` [in]

The handle of the resource to be tracked. The Resource Dispenser has already created this resource before calling **TrackResourceS**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *SResId* is not a valid resource handle. |
| **E_FAIL** | The method failed. The resource has not been tracked. The likely cause is that the caller's transaction is aborting. |

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)

[IDispenserManager](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispensermanager)

[IHolder](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iholder)