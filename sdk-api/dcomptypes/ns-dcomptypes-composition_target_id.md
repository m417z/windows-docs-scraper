## Description

Contains information about a composition render target.

## Members

### `displayAdapterLuid`

Type: **[LUID](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-luid)**

The locally unique identifier (LUID) of the display adapter to which the monitor is connected.

### `renderAdapterLuid`

Type: **[LUID](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-luid)**

The locally unique identifier (LUID) of the render adapter.

### `vidPnSourceId`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The unique ID of the video present source.

### `vidPnTargetId`

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The unique ID of the video present target.

### `uniqueId`

A unique identifier for this `COMPOSITION_TARGET_ID`.

## Remarks

## See also

[DCompositionGetStatistics](https://learn.microsoft.com/windows/win32/api/dcomp/nf-dcomp-dcompositiongetstatistics), [DCompositionGetTargetStatistics](https://github.com/MicrosoftDocs/sdk-api/blob/docs/sdk-api-src/content/dcomp/nf-dcomp-dcompositiongettargetstatistics.md)