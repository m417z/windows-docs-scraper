# RtlRunOnceExecuteOnce function

## Description

The **RtlRunOnceExecuteOnce** performs a one-time initialization.

## Parameters

### `RunOnce` [in, out]

A pointer to the [RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) one-time initialization structure.

### `InitFn` [in]

A pointer to a [RunOnceInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-rtl_run_once_init_fn) routine.

### `Parameter` [in, out]

The value to pass as the *Parameter* parameter to the *RunOnceInitialization* routine.

### `Context` [out]

A pointer to a PVOID variable that receives the initialized data.

## Return value

**RtlRunOnceExecuteOnce** returns STATUS_SUCCESS if the operation succeeds, or the appropriate NTSTATUS error code if the operation fails.

## Syntax

```cpp
NTSYSAPI NTSTATUS RtlRunOnceExecuteOnce(
  PRTL_RUN_ONCE         RunOnce,
  PRTL_RUN_ONCE_INIT_FN InitFn,
  PVOID                 Parameter,
  PVOID                 *Context
);
```

## Remarks

For the first call to **RtlRunOnceExecuteOnce** for a particular [RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, **RtlRunOnceExecuteOnce** calls the [RunOnceInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-rtl_run_once_init_fn) routine to initialize the data. Every subsequent call to **RtlRunOnceExecuteOnce** for that structure supplies the same initialized data. The *RunOnceInitialization* routine will not be called twice for the same **RTL_RUN_ONCE** structure.

**RtlRunOnceExecuteOnce** runs with normal kernel APCs disabled. The routine should not be called within a special kernel APC unless all calls occur at APC_LEVEL.

## See also

[RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[RtlRunOnceBeginInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncebegininitialize)

[RtlRunOnceComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncecomplete)

[RtlRunOnceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceinitialize)

[RunOnceInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-rtl_run_once_init_fn)