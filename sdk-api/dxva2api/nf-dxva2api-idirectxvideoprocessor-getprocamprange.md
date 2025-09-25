# IDirectXVideoProcessor::GetProcAmpRange

## Description

Retrieves the range of values for a video processor (ProcAmp) setting on this video processor device.

## Parameters

### `ProcAmpCap` [in]

The ProcAmp setting to query. See [ProcAmp Settings](https://learn.microsoft.com/windows/desktop/medfound/procamp-settings).

### `pRange` [out]

Pointer to a [DXVA2_ValueRange](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_valuerange) structure that receives the range of values for the setting specified in *ProcAmpCaps*.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[DXVA Video Processing](https://learn.microsoft.com/windows/desktop/medfound/dxva-video-processing)

[IDirectXVideoProcessor](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideoprocessor)