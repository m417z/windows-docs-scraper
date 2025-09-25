# DXGKDDI_CALIBRATEGPUCLOCK callback function

## Description

Called by the Microsoft DirectX graphics kernel subsystem to calibrate the GPU time stamps in the [DXGK_HISTORY_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer) history buffer with the CPU clock time.

## Parameters

### `hAdapter`

A handle to the adapter object for the GPU for which timing calibration info is to be obtained.

The display miniport driver previously provided this handle to the DirectX graphics kernel subsystem in the *MiniportDeviceContext* output parameter of the [DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device) function.

### `NodeOrdinal`

An index of a node for which timing calibration info will be obtained. This node is within the physical adapter defined by the *hAdapter* parameter.

### `EngineOrdinal`

The zero-based index of the engine, within the node that *NodeOrdinal* specifies, for which timing calibration info will be obtained. For graphics adapters that are not part of a link in a linked display adapter (LDA) configuration, you should always set *EngineOrdinal* to 0.

### `pClockCalibration`

A pointer to a [DXGKARG_CALIBRATEGPUCLOCK](https://learn.microsoft.com/windows-hardware/drivers/display/) structure that provides clock counter info from the GPU and CPU.

## Return value

Returns **STATUS_SUCCESS** if it succeeds; otherwise, it returns one of the error codes defined in Ntstatus.h.

## Remarks

The DirectX graphics kernel subsystem uses the returned info in the *pClockCalibration* parameter to estimate the drift between the GPU and CPU clocks.

To minimize calibration inaccuracies, the driver should compute the values for the **GpuClockCounter**
and **CpuClockCounter** members of the [DXGKARG_CALIBRATEGPUCLOCK](https://learn.microsoft.com/windows-hardware/drivers/display/) structure as nearly simultaneously as possible.

The DirectX graphics kernel subsystem calls this function often enough, typically at least once every 30ms, to minimize the accumulated drift between the GPU and CPU clocks.

## See also

[DXGKARG_CALIBRATEGPUCLOCK](https://learn.microsoft.com/windows-hardware/drivers/display/)

[DXGK_HISTORY_BUFFER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer)

[DxgkDdiAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_add_device)