# IObjectContextInfo2::GetPartitionId

## Description

Retrieves the identifier of the partition of the current object context.

## Parameters

### `pGuid` [out]

A GUID that identifies the COM+ partition.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_PARTITIONS_DISABLED** | COM+ partitions are not enabled. |

## See also

[IObjectContextInfo2](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontextinfo2)