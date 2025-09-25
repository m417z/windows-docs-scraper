## Description

**ExDestroyPool** destroys a pool instance.

## Parameters

### `PoolHandle`

[in] Handle to the pool instance to be destroyed. Must be a valid handle returned by [**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool).

## Return value

None.

## Remarks

After this call, the pool handle is no longer valid and must not be used in subsequent operations.

All allocations associated with the pool must have been released before the pool is destroyed.

If the handle is invalid, a bug check may occur.

## See also

[**ExCreatePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-excreatepool)

[**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2)

[**ExFreePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepool2)