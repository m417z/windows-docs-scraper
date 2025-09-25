# ID2D1AnalysisTransform::ProcessAnalysisResults

## Description

Supplies the analysis data to an analysis transform.

## Parameters

### `analysisData` [in]

Type: **const BYTE***

The data that the transform will analyze.

### `analysisDataCount`

Type: **UINT**

The size of the analysis data.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

The output of the transform will be copied to CPU-accessible memory by the imaging effects system before being passed to the implementation.

 If this call fails, the corresponding [ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect) instance is placed into an error state and fails to draw.

## See also

[ID2D1AnalysisTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1analysistransform)

[ID2D1EffectContext::CreateResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createresourcetexture)