# RtlRunOnceBeginInitialize function

## Description

The **RtlRunOnceBeginInitialize** routine begins a one-time initialization.

## Parameters

### `RunOnce` [in, out]

Pointer to the [RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) one-time initialization structure.

### `Flags` [in]

Drivers can optionally specify one or more of the following flags:

#### RTL_RUN_ONCE_ASYNC

Perform initialization asynchronously. The driver can perform multiple completion attempts in parallel. If this flag is used, subsequent calls to this routine will fail unless this flag is also specified.

#### RTL_RUN_ONCE_CHECK_ONLY

Do not begin initialization, but check to determine if initialization has already occurred. If **RtlRunOnceBeginInitialize** returns STATUS_SUCCESS, the initialization succeeded, and **Context* contains the initialized data.

### `Context` [out]

Specifies a pointer to a PVOID variable that receives the initialized data. The value of **Context* is valid only when the routine returns STATUS_SUCCESS.

## Return value

**RtlRunOnceBeginInitialize** returns one of the following NTSTATUS values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The one-time initialization has already completed. The initialized data is stored in the memory location that *Context* points to. |
| **STATUS_PENDING** | The caller has successfully begun one-time initialization. The caller now performs the driver-specific initialization steps and then calls [RtlRunOnceComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncecomplete) to complete the initialization. |

## Remarks

Drivers can alternatively perform one-time initialization by calling [RtlRunOnceExecuteOnce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceexecuteonce) and supplying a [RunOnceInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-rtl_run_once_init_fn) routine.

## See also

[RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[RtlRunOnceComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncecomplete)

[RtlRunOnceExecuteOnce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceexecuteonce)

[RtlRunOnceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceinitialize)

[RunOnceInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-rtl_run_once_init_fn)