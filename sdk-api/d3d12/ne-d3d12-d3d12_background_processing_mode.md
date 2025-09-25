## Description

Defines constants that specify a level of dynamic optimization to apply to GPU work that's subsequently submitted.

## Constants

### `D3D12_BACKGROUND_PROCESSING_MODE_ALLOWED:0`

The default setting. Specifies that the driver may instrument workloads, and dynamically recompile shaders, in a low overhead, non-intrusive manner that avoids glitching the foreground workload.

### `D3D12_BACKGROUND_PROCESSING_MODE_ALLOW_INTRUSIVE_MEASUREMENTS`

Specifies that the driver may instrument as aggressively as possible. The understanding is that causing glitches is fine while in this mode, because the current work is being submitted specifically to train the system.

### `D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_BACKGROUND_WORK`

Specifies that background work should stop. This ensures that background shader recompilation won't consume CPU cycles. Available only in **Developer mode**.

### `D3D12_BACKGROUND_PROCESSING_MODE_DISABLE_PROFILING_BY_SYSTEM`

Specifies that all dynamic optimization should be disabled. For example, if you're doing an A/B performance comparison, then using this constant ensures that the driver doesn't change anything that might interfere with your results. Available only in **Developer mode**.

## Remarks

## See also

[Core enumerations](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-enumerations)