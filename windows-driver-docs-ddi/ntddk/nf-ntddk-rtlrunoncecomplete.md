# RtlRunOnceComplete function

## Description

The **RtlRunOnceComplete** routine completes the one-time initialization began by [RtlRunOnceBeginInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncebegininitialize).

## Parameters

### `RunOnce` [in, out]

Pointer to the [RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) one-time initialization structure.

### `Flags` [in]

Drivers can optionally specify one or more of the following flags:

#### RTL_RUN_ONCE_ASYNC

Operate in asynchronous mode. This mode enables multiple completion attempts to execute in parallel. If this flag is used, subsequent calls to the **RtlRunOnceComplete** routine will fail unless this flag is also specified.

#### RTL_RUN_ONCE_INIT_FAILED

The initialization attempt failed.

### `Context` [in, optional]

Specifies the initialized data.

## Return value

**RtlRunOnceComplete** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_UNSUCCESSFUL** | The operation could not be completed. If the caller specified RTL_RUN_ONCE_ASYNC in the *Flags* parameter, this value can indicate that another thread completed the initialization. |

## Remarks

If **RtlRunOnceComplete** returns STATUS_SUCCESS, any subsequent call to [RtlRunOnceBeginInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncebegininitialize) for the same [RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure supplies *Context* as the initialized data.

If the caller specified RTL_RUN_ONCE_ASYNC in the *Flags* parameter and **RtlRunOnceComplete** returns any value other than STATUS_SUCCESS, the caller must clean up any initialization that it attempted.

## See also

[RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[RtlRunOnceBeginInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncebegininitialize)

[RtlRunOnceExecuteOnce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceexecuteonce)

[RtlRunOnceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceinitialize)

[RunOnceInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-rtl_run_once_init_fn)