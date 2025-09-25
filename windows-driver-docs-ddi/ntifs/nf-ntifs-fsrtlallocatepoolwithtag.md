# FsRtlAllocatePoolWithTag macro

## Description

The **FsRtlAllocatePoolWithTag** routine allocates pool memory.

## Parameters

### `PoolType` [in]

Type of pool to allocate. One of the following:

* **NonPagedPool**
* **PagedPool**
* **NonPagedPoolCacheAligned**
* **PagedPoolCacheAligned**

The **NonPagedPoolMustSucceed** and **NonPagedPoolCacheAlignedMustS** pool types are obsolete and should no longer be used.

### `NumberOfBytes` [in]

Number of bytes to allocate. This parameter is required and cannot be zero.

### `Tag` [in]

Specifies the pool tag for the allocated memory. Drivers normally specify the pool tag as a string of one to four 7-bit ASCII characters, delimited by single quotation marks (for example, 'abcd'). This parameter is required and cannot be zero.

## Remarks

If a pool allocation failure occurs, **FsRtlAllocatePoolWithTag** raises a STATUS_INSUFFICIENT_RESOURCES exception. To gain control if this pool allocation failure occurs, the driver should wrap the call to **FsRtlAllocatePoolWithTag** in a *try-except* or *try-finally* statement.

The system associates the pool tag specified by the **Tag** parameter with the allocated buffer. Programming tools, such as the Windows Debugger (WinDbg), can display the pool tag associated with each allocated buffer. The value of the pool tag is normally displayed in reversed order. For example, if a caller passes 'Fred' as the value of the **Tag** parameter, this value would appear as 'derF' if pool is dumped or when tracking pool usage in the debugger.

For more information about memory management, see [Memory Management](https://learn.microsoft.com/windows-hardware/drivers/kernel/managing-memory-for-drivers).

Memory that **FsRtlAllocatePoolWithTag** allocates is uninitialized. A kernel-mode driver must first zero this memory if it is going to make it visible to user-mode software (to avoid leaking potentially privileged contents).

Callers of **FsRtlAllocatePoolWithTag** must be running at IRQL <= DISPATCH_LEVEL. A caller at DISPATCH_LEVEL must specify a **NonPaged*Xxx*** **PoolType**. Otherwise, the caller must be running at IRQL <= APC_LEVEL.

## See also

[**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[**ExFreePool**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-exfreepool)