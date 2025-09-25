# NdisInterlockedAddUlong macro

## Description

The
**NdisInterlockedAddUlong** function adds an unsigned long value to a given unsigned integer as an atomic
operation, using a caller-supplied spin lock to synchronize access to the integer variable.

## Parameters

### `_Addend` [in]

A pointer to the variable for which the value is to be adjusted by the given
*Increment* .

### `_Increment` [in]

The value to be added to that at
*Addend* .

### `_SpinLock` [in]

A pointer to a caller-initialized spin lock.

## Remarks

The caller of
**NdisInterlockedAddUlong** must provide resident storage for the spin lock, which must be initialized
with the
[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock) function before
the initial call to
**NdisInterlockedAddUlong**.

The
*SpinLock* value that is passed to the
**NdisInterlockedAddUlong** function
is used to assure that the addition to the variable at the
*Addend* parameter is atomic with respect to any other operations on the same variable that
synchronize with the same spin lock.

**NdisInterlockedAddUlong** raises the IRQL to DISPATCH_LEVEL when it acquires the given spin lock and
restores the original IRQL before it returns control. Consequently, any driver function that calls
**NdisInterlockedAddUlong** cannot be pageable code.

## See also

[NdisAcquireSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisacquirespinlock)

[NdisAllocateSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatespinlock)

[NdisReleaseSpinLock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreleasespinlock)

[NdisRetrieveUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisretrieveulong)

[NdisStoreUlong](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisstoreulong)