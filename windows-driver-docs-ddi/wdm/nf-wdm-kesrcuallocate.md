## Description

The **KeSrcuAllocate** routine allocates and initializes a sleepable Read-Copy-Update (SRCU) partition for synchronization purposes.

## Parameters

### `Tag` [in]

A four-character tag value used to identify this SRCU instance.

## Return value

**KeSrcuAllocate** returns a pointer to the allocated SRCU instance on success, or NULL if the allocation fails.

## Remarks

**KeSrcuAllocate** creates a new SRCU synchronization domain that allows multiple readers to access shared data concurrently while ensuring safe updates. SRCU differs from regular RCU in that readers can sleep while holding the read lock.

The SRCU partition returned by this function must be freed using [**KeSrcuFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcufree) when no longer needed.

Each SRCU partition is independent and maintains its own grace periods. SRCU is designed for scenarios where readers may need to sleep or perform blocking operations.

The *Tag* parameter should be unique to help identify the instance during debugging.

### Typical Usage Pattern

* Call **KeSrcuAllocate** to create an SRCU partition.
* Use [**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock) and [**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock) for reader synchronization.
* Use [**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize) to wait for reader completion before updates.
* Call [**KeSrcuFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcufree) to clean up when done.

## See also

[**KeSrcuFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcufree)

[**KeSrcuReadLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadlock)

[**KeSrcuReadUnlock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcureadunlock)

[**KeSrcuSynchronize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kesrcusynchronize)