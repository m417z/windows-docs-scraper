# _DXGK_QUERYGPUMMUCAPSIN structure

## Description

The **DXGK_QUERYGPUMMUCAPSIN** structure holds the index of the adapter being queried.

## Members

### `PhysicalAdapterIndex`

A zero-based physical adapter index (engine ordinal) for which the data is queried.

## Remarks

To get GpuMmu caps Dxgkrnl calls [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) with the following parameters:

```
DXGKARG_QUERYADAPTERINFO::Type = DXGKQAITYPE_GPUMMUCAPS;
DXGKARG_QUERYADAPTERINFO::pInputData = buffer of DXGK_QUERYGPUMMUCAPSIN type
DXGKARG_QUERYADAPTERINFO::InputDataSize = sizeof(DXGK_QUERYGPUMMUCAPSIN);
DXGKARG_QUERYADAPTERINFO::pOutputData = pointer to DXGK_GPUMMUCAPS
DXGKARG_QUERYADAPTERINFO::OutputDataSize = sizeof(DXGK_GPUMMUCAPS);
```