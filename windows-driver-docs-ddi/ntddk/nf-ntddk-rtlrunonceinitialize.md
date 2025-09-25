# RtlRunOnceInitialize function

## Description

The **RtlRunOnceInitialize** routine initializes a [RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure.

## Parameters

### `RunOnce` [out]

Pointer to the **RTL_RUN_ONCE** one-time initialization structure.

## Return value

None

## See also

[RTL_RUN_ONCE](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess)

[RtlRunOnceBeginInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncebegininitialize)

[RtlRunOnceComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunoncecomplete)

[RtlRunOnceExecuteOnce](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-rtlrunonceexecuteonce)

[RunOnceInitialization](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nc-ntddk-rtl_run_once_init_fn)