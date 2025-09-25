# _DXGK_HISTORY_BUFFER structure

## Description

Specifies a history buffer that stores time stamps that record GPU activity throughout the execution lifetime of a direct memory access (DMA) buffer.

## Members

### `Header`

A pointer to a [DXGK_HISTORY_BUFFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer_header) structure that contains history buffer header info.

### `DriverPrivateData`

An array that marks the beginning of the optional driver data and timestamp entries. See Remarks for more info.

## Remarks

You can calculate the address of the first time stamp in the history buffer by adding the value of [DXGK_HISTORY_BUFFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer_header).**PrivateDataSize** to the address of **DriverPrivateData**.

The beginnings of the time stamps should be aligned to a 64-bit boundary.

The first and last time stamps in the **DriverPrivateData** array must be respectively the start and end times of the DMA buffer. Time stamps that are used to log marker times begin after this end time. This is the case for both formatted and unformatted buffers.

The driver specifies the precision of time stamps with the [DXGKARG_HISTORYBUFFERPRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_historybufferprecision) structure.

## See also

[DXGKARG_HISTORYBUFFERPRECISION](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgkarg_historybufferprecision)

[DXGK_HISTORY_BUFFER_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_history_buffer_header)