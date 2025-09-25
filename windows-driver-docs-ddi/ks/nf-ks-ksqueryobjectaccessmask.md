# KsQueryObjectAccessMask function

## Description

The **KsQueryObjectAccessMask** function returns the access originally granted to the first client that created a handle on the associated object. Access cannot be changed by duplicating handles.

## Parameters

### `Header` [in]

Points to a header previously allocated by **KsAllocateObjectHeader** whose access-granted mask pointer is to be returned.

## Return value

The **KsQueryObjectAccessMask** function returns an access mask.

## See also

[KsAllocateObjectHeader](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocateobjectheader)