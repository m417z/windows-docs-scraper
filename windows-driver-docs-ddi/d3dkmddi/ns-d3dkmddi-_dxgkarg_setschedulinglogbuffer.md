# _DXGKARG_SETSCHEDULINGLOGBUFFER structure

## Description

Arguments used in the call to [DxgkddiSetSchedulingLogBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setschedulinglogbuffer).

## Members

### `NodeOrdinal`

The node ordinal.

### `EngineOrdinal`

 The engine ordinal.

### `NumberOfEntries`

The number of entries in the log entries array.

### `LogBufferCpuVa`

Kernel mode CPU VA of the log buffer.

### `LogBufferGpuVa`

GPU VA of the log buffer.

### `InterruptEntry`

Index of entry to raise interrupt when writing to.

## See also

[DxgkddiSetSchedulingLogBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_setschedulinglogbuffer)