## Description

**FsRtlAllocateAePushLock** allocates and initializes an auto-expand push lock.

## Parameters

### `PoolType` [in]

The type of pool memory to allocate for the auto-expand push lock. See [**POOL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_pool_type) for a description of the available pool memory types. You can modify the **PoolType** value by bitwise-ORing it with the POOL_RAISE_IF_ALLOCATION_FAILURE flag. This flag causes an exception to be raised if the allocation request cannot be satisfied.

### `Tag` [in]

The pool tag to use for the allocated memory. Specify the pool tag as a non-zero character literal of one to four characters delimited by single quotation marks (for example, 'Tag1'). The string is usually specified in reverse order (for example, '1gaT'). Each ASCII character in the tag must be a value in the range 0x20 (space) to 0x7E (tilde). Each allocation code path should use a unique pool tag to help debuggers and verifiers identify the code path.

## Return value

**FsRtlAllocateAePushLock** returns NULL if there is insufficient memory in the free pool to satisfy the request. Otherwise, the routine returns a pointer to the allocated and initialized auto-expand push lock.

## Remarks

**FsRtlAllocateAePushLock** is used to allocate pool memory for an auto-expand push lock. See [**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header) for more information about auto-expand push locks.

The system associates the pool tag with the allocated memory. Programming tools, such as *WinDbg*, can display the pool tag associated with each allocated buffer. *Gflags*, a tool included in [Debugging Tools for Windows](https://learn.microsoft.com/windows-hardware/drivers/debugger/), turns on a system feature that requests allocation from [special pool](https://learn.microsoft.com/windows-hardware/drivers/devtest/special-pool) for a particular pool tag. [*Poolmon*](https://learn.microsoft.com/windows-hardware/drivers/devtest/poolmon), which is included in the WDK, tracks memory by pool tag.

The caller of **FsRtlAllocateAePushLock** must subsequently call [**FsRtlFreeAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeaepushlock) to free the allocated auto-expand push lock.

The system automatically sets certain standard event objects when the amount of pool (paged or nonpaged) is high or low. Drivers can wait for these events to tune their pool usage. For more information, see [Standard Event Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/standard-event-objects).

## See also

[**FSRTL_ADVANCED_FCB_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_fsrtl_advanced_fcb_header)

[**FsRtlFreeAePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlfreeaepushlock)

[**FsRtlSetupAdvancedHeaderEx2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-fsrtlsetupadvancedheaderex2)