# EnterSynchronizationBarrier function

## Description

Causes the calling thread to wait at a synchronization barrier until the maximum number of threads have entered the barrier.

## Parameters

### `lpBarrier` [in, out]

A pointer to an initialized synchronization barrier. Use the [InitializeSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializesynchronizationbarrier) function to initialize the barrier. **SYNCHRONIZATION_BARRIER** is an opaque structure that should not be modified by the application.

### `dwFlags` [in]

Flags that control the behavior of threads that enter this barrier. This parameter can be one or more of the following values:

| Value | Meaning |
|-------|---------|
| **SYNCHRONIZATION_BARRIER_FLAGS_BLOCK_ONLY** | Specifies that the thread entering the barrier should block immediately until the last thread enters the barrier. For more information, see Remarks. |
| **SYNCHRONIZATION_BARRIER_FLAGS_SPIN_ONLY** | Specifies that the thread entering the barrier should spin until the last thread enters the barrier, even if the spinning thread exceeds the barrier's maximum spin count. For more information, see Remarks. |
| **SYNCHRONIZATION_BARRIER_FLAGS_NO_DELETE** | Specifies that the function can skip the work required to ensure that it is safe to delete the barrier, which can improve performance. All threads that enter this barrier must specify the flag; otherwise, the flag is ignored. This flag should be used only if the barrier will never be deleted. |

## Return value

`TRUE` for the last thread to signal the barrier. Threads that signal the barrier before the last thread signals it receive a return value of `FALSE`.

## Remarks

The default behavior for threads entering a synchronization barrier is to spin until the maximum spin count of the barrier is reached, and then block. This allows threads to resume quickly if the last thread enters the barrier in a relatively short time. However, if the last thread takes relatively longer to arrive, threads already in the barrier block so they stop consuming processor time while waiting.

A thread can override the default behavior of the barrier by specifying **SYNCHRONIZATION_BARRIER_FLAGS_BLOCK_ONLY** or **SYNCHRONIZATION_BARRIER_FLAGS_SPIN_ONLY**. However, keep in mind that using these flags can affect performance. Spinning indefinitely keeps a processor from servicing other threads, while premature blocking incurs the overhead of swapping the thread off the processor, awakening the thread when it unblocks, and swapping it back onto the processor again. In general it is better to allow the barrier to manage threads and use these flags only if performance testing indicates the application would benefit from them.

## See also

[DeleteSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletesynchronizationbarrier)

[InitializeSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-initializesynchronizationbarrier)

[Synchronization Barriers](https://learn.microsoft.com/windows/win32/Sync/synchronization-barriers)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)