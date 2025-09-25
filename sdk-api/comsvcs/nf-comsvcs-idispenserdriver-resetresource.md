# IDispenserDriver::ResetResource

## Description

Prepares the resource to be put back into general or enlisted inventory.

## Parameters

### `ResId` [in]

The resource to be reset.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | *ResId* is not a valid resource handle. |
| **E_FAIL** | The method failed. |

## Remarks

The resource may still be enlisted at this time, so **ResetResource** cannot disrupt the enlistment.

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)