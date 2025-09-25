# InitializeSynchronizationBarrier function

## Description

Initializes a new synchronization barrier.

## Parameters

### `lpBarrier` [out]

A pointer to the **SYNCHRONIZATION_BARRIER** structure to initialize. This is an opaque structure that should not be modified by applications.

### `lTotalThreads` [in]

The maximum number of threads that can enter this barrier. After the maximum number of threads have entered the barrier, all threads continue.

### `lSpinCount` [in]

The number of times an individual thread should spin while waiting for other threads to arrive at the barrier. If this parameter is `-1`, the thread spins 2000 times. If the thread exceeds *lSpinCount*, the thread blocks unless it called [EnterSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entersynchronizationbarrier) with **SYNCHRONIZATION_BARRIER_FLAGS_SPIN_ONLY**.

## Return value

`TRUE` if the barrier was successfully initialized. If the barrier was not successfully initialized, this function returns `FALSE`. Use [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) to get extended error information.

## See also

[DeleteSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-deletesynchronizationbarrier)

[EnterSynchronizationBarrier](https://learn.microsoft.com/windows/win32/api/synchapi/nf-synchapi-entersynchronizationbarrier)

[Synchronization Barriers](https://learn.microsoft.com/windows/win32/Sync/synchronization-barriers)

[Vertdll APIs available in VBS enclaves](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-available-in-vertdll)