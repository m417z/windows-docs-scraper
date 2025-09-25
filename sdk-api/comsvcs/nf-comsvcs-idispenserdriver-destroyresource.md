# IDispenserDriver::DestroyResource

## Description

Destroys a resource.

## Parameters

### `ResId` [in]

The resource that the Dispenser Manager is asking the Resource Dispenser to destroy.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The Resource Dispenser does not support numeric RESIDs. |
| **E_FAIL** | The method failed. |

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)