# _D3DKMT_OPENADAPTERFROMHDC structure

## Description

The D3DKMT_OPENADAPTERFROMHDC structure describes the mapping of a device context handle (HDC) to a graphics adapter handle and monitor output.

## Members

### `hDc` [in]

The HDC for the graphics adapter and monitor output that are retrieved.

### `hAdapter` [out]

A handle to the graphics adapter for the HDC that **hDc** specifies. The adapter handle is returned from the call to the [D3DKMTOpenAdapterFromHdc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromhdc) function.

### `AdapterLuid` [out]

The locally unique identifier ([LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)) of the graphics adapter for the HDC that **hDc** specifies. The LUID is returned from the [D3DKMTOpenAdapterFromHdc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromhdc) call.

### `VidPnSourceId` [out]

The zero-based identification number of the video present source in a path of a video present network (VidPN) topology for the HDC that **hDc** specifies. The identification number is returned from the [D3DKMTOpenAdapterFromHdc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromhdc) call.

## See also

[D3DKMTOpenAdapterFromHdc](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtopenadapterfromhdc)