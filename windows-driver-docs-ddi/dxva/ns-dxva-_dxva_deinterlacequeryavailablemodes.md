# _DXVA_DeinterlaceQueryAvailableModes structure

## Description

The DXVA_DeinterlaceQueryAvailableModes structure describes the available deinterlacing or frame-rate conversion modes for a particular input video format.

## Members

### `Size`

Indicates the size of this structure.

### `NumGuids`

Indicates the number of GUIDs that are returned in the **Guids** member for the available modes.

### `Guids`

An array of GUIDs that are returned for the available deinterlace modes.

## Remarks

The driver receives the DXVA_DeinterlaceQueryAvailableModes structure with the **Size** member assigned, assigns values to the remaining members, and returns DXVA_DeinterlaceQueryAvailableModes to the renderer.

There is a GUID for each deinterlace and frame conversion mode returned by the driver. The GUIDs should be returned in order of descending quality (that is, the highest quality mode should occupy the first element of the GUID array returned).