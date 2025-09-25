# DeleteSynchronizationBarrier function

## Description

Deletes a synchronization barrier.

## Parameters

### `lpBarrier` [in, out]

A pointer to the synchronization barrier to delete.

## Return value

The **DeleteSynchronizationBarrier** function always returns `TRUE`.

## Remarks

**DeleteSynchronizationBarrier** releases a synchronization barrier when it is no longer needed. It is safe to call **DeleteSynchronizationBarrier** immediately after calling [EnterSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entersynchronizationbarrier) because that function ensures that all threads in the barrier have finished using it before allowing the barrier to be released.

If a synchronization barrier will never be deleted, threads can specify the **SYNCHRONIZATION_BARRIER_FLAGS_NO_DELETE** flag when they enter the barrier. This flag causes the function to skip the extra work required for deletion safety, which can improve performance. All threads using the barrier must specify this flag; if any thread does not, the flag is ignored. Be careful when using **SYNCHRONIZATION_BARRIER_FLAGS_NO_DELETE**, because deleting a barrier while this flag is in effect may result in an invalid handle access and cause one or more threads to become permanently blocked.

## See also

[EnterSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entersynchronizationbarrier)

[InitializeSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializesynchronizationbarrier)

[Synchronization Barriers](https://learn.microsoft.com/windows/win32/Sync/synchronization-barriers)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)