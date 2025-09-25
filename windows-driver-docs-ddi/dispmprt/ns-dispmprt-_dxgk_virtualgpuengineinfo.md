# _DXGK_VIRTUALGPUENGINEINFO structure

## Description

The virtual GPU engine info.

## Members

### `MinPartitionUnits`

Minimum engine partition units, which should be used with the engine.

### `MaxPartitionUnits`

Maximum engine partition units, which should be used with the engine.

### `EngineId`

An index to the engine array.

## Remarks

When a vGPU is created successfully, all resources must be allocated, but hardware register are not mapped yet. The vGPU will be switched to the running state when DxgkDdiSetVirtualFunctionPowerState is called with the D0 state. This data structure is deprecated and should be zero if used.

## See also