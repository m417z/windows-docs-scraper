## Description

Defines constants that specify what should be done with the results of earlier workload instrumentation.

## Constants

### `D3D12_MEASUREMENTS_ACTION_KEEP_ALL:0`

The default setting. Specifies that all results should be kept.

### `D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS`

Specifies that the driver has seen all the data that it's ever going to, so it should stop waiting for more and go ahead compiling optimized shaders.

### `D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS_HIGH_PRIORITY`

Like **D3D12_MEASUREMENTS_ACTION_COMMIT_RESULTS**, but also specifies that your application doesn't care about glitches, so the runtime should ignore the usual idle priority rules and go ahead using as many threads as possible to get shader recompiles done fast. Available only in **Developer mode**.

### `D3D12_MEASUREMENTS_ACTION_DISCARD_PREVIOUS`

Specifies that the optimization state should be reset; hinting that whatever has previously been measured no longer applies.

## Remarks

## See also

[Core enumerations](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-enumerations)