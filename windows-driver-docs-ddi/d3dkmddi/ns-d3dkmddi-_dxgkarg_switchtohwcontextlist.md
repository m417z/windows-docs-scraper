# _DXGKARG_SWITCHTOHWCONTEXTLIST structure

## Description

Arguments used in the [DXGKDDI_SWITCHTOHWCONTEXTLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_switchtohwcontextlist) callback function.

## Members

### `hHwContextFirst`

Hardware context that should be executed by the GPU first. If the GPU is currently not executing this context, it needs to preempt the current work and switch to *hHwContextFirst*. May be NULL if the GPU is instructed to become idle.

### `hHwContextSecond`

Hardware context that should be executed by the GPU once all queues in *hHwContextFirst* are idle or blocked on waits. May be NULL.

### `NodeOrdinal`

Node ordinal of engine that is instructed to switch to the new context(s).

### `EngineOrdinal`

Engine ordinal of engine that is instructed to switch to the new context(s).

## Remarks

## See also