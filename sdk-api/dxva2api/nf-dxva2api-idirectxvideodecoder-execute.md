# IDirectXVideoDecoder::Execute

## Description

Executes a decoding operation on the current frame.

## Parameters

### `pExecuteParams` [in]

Pointer to a [DXVA2_DecodeExecuteParams](https://learn.microsoft.com/windows/desktop/api/dxva2api/ns-dxva2api-dxva2_decodeexecuteparams) structure that contains the information needed for the decoding operation.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

You must call [IDirectXVideoDecoder::BeginFrame](https://learn.microsoft.com/windows/desktop/api/dxva2api/nf-dxva2api-idirectxvideodecoder-beginframe) before calling this method.

## See also

[DirectX Video Acceleration 2.0](https://learn.microsoft.com/windows/desktop/medfound/directx-video-acceleration-2-0)

[IDirectXVideoDecoder](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirectxvideodecoder)