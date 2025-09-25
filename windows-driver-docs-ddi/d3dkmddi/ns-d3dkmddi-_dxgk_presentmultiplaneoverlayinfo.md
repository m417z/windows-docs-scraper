# _DXGK_PRESENTMULTIPLANEOVERLAYINFO structure

## Description

Specifies info on a VidPN input and an overlay plane to display.

## Members

### `VidPnSourceId` [in]

The zero-based video present network (VidPN) source identification number of the input that is to be displayed.

### `PlaneListCount` [in]

The number of overlay planes that are available to display.

### `pPlaneList` [in]

A pointer to a structure of type [DXGK_PRESENTMULTIPLANEOVERLAYLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentmultiplaneoverlaylist) that describes the overlay plane to display.

## See also

[DXGK_PRESENTMULTIPLANEOVERLAYLIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_presentmultiplaneoverlaylist)