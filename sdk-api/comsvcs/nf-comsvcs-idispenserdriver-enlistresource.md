# IDispenserDriver::EnlistResource

## Description

Enlists a resource in a transaction.

## Parameters

### `ResId` [in]

The resource that the Dispenser Manager is asking to be enlisted in transaction *TransId*.

### `TransId` [in]

The transaction that the Dispenser Manager wants the Resource Dispenser to enlist resource *ResId* in. The Dispenser Manager passes 0 to indicate that the Resource Dispenser should ensure that the resource is not enlisted in any transaction.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | The resource is not enlistable (not transaction capable). |
| **E_INVALIDARG** | One of the arguments is not valid. |
| **E_FAIL** | The method failed. |

## See also

[IDispenserDriver](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-idispenserdriver)