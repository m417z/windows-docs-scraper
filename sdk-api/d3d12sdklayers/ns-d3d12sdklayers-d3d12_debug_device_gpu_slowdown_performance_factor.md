# D3D12_DEBUG_DEVICE_GPU_SLOWDOWN_PERFORMANCE_FACTOR structure

## Description

Describes the amount of artificial slowdown inserted by the debug device to simulate lower-performance graphics adapters.

## Members

### `SlowdownFactor`

Specifies the amount of slowdown artificially applied, as a factor of the nominal time for the fence to signal. The default value is 0.

## Remarks

The SlowdownFactor is applied by artificially delaying the time it takes for a fence to signal. When SlowdownFactor is non-zero, the time taken for a fence to signal is approximately 1.0 + SlowdownFactor times the length of the nominal timing.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)