# ContextInfo2::GetPartitionId

## Description

Retrieves the GUID of the COM+ partition of the current object context.

## Parameters

### `__MIDL__ContextInfo20000` [out]

A reference to the partition identifier.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_PARTITIONS_DISABLED** | COM+ partitions are not enabled. |

## See also

[COM+ Partitions](https://learn.microsoft.com/windows/desktop/cossdk/com--partitions)

[ContextInfo2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-contextinfo2)