## Description

This routine returns the number of active processors in the given NUMA node across all groups.

## Parameters

### `NodeNumber` [in]

A value of type USHORT that specifies the node number of the node to query.

## Return value

Returns a ULONG value specifying the number of active processors in the specified NUMA node or zero if an invalid node number was specified.

## Remarks

## See also

[**KeQueryNodeActiveAffinity2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerynodeactiveaffinity2)

[NUMA Support](https://learn.microsoft.com/windows/win32/procthread/numa-support)