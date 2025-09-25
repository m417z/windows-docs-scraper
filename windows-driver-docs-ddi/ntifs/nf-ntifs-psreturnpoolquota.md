# PsReturnPoolQuota function

## Description

The **PsReturnPoolQuota** routine returns pool quota of the specified pool type to the specified process.

## Parameters

### `Process` [in]

Pointer to the process whose quota is to be returned.

### `PoolType` [in]

Type of pool quota to return, which can be one of the following:

* **NonPagedPool**
* **PagedPool**
* **NonPagedPoolCacheAligned**
* **PagedPoolCacheAligned**

The **NonPagedPoolMustSucceed** and **NonPagedPoolCacheAlignedMustS** pool types are obsolete and should no longer be used.

### `Amount` [in]

Number of bytes to return to the pool quota for this process.

## Remarks

If the quota return would exceed the quota for the process, **PsReturnPoolQuota** raises an exception with the status value STATUS_QUOTA_EXCEEDED. Callers are responsible for handling this exception. Thus calls to **PsReturnPoolQuota** must be wrapped within a driver-supplied exception handler.

Every successful call to **PsChargePoolQuota** must be matched by a subsequent call to **PsReturnPoolQuota**.

For more information about memory management, see [Memory Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-memory-for-drivers).

## See also

[**PsChargePoolQuota**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-pschargepoolquota)