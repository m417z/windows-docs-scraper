# PsChargePoolQuota function

## Description

The **PsChargePoolQuota** routine charges pool quota of the specified pool type to the specified process.

## Parameters

### `Process` [in]

Pointer to the process whose quota is to be charged.

### `PoolType` [in]

Type of pool quota to charge, which can be one of the following:

* **NonPagedPool**
* **PagedPool**
* **NonPagedPoolCacheAligned**
* **PagedPoolCacheAligned**

The **NonPagedPoolMustSucceed** and **NonPagedPoolCacheAlignedMustS** pool types are obsolete and should no longer be used.

### `Amount` [in]

Number of bytes to charge against the pool quota for this process.

## Remarks

If insufficient quota exists for the process, quota is not charged, and **PsChargePoolQuota** raises an exception with the status value STATUS_QUOTA_EXCEEDED. Callers are responsible for handling this exception. Thus calls to **PsChargePoolQuota** must be wrapped within a driver-supplied exception handler.

Every successful call to **PsChargePoolQuota** must be matched by a subsequent call to **PsReturnPoolQuota**.

For more information about memory management, see [Memory Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-memory-for-drivers).

## See also

[**PsReturnPoolQuota**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-psreturnpoolquota)