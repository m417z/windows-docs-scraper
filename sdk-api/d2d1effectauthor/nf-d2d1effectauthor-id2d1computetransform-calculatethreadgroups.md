# ID2D1ComputeTransform::CalculateThreadgroups

## Description

This method allows a compute-shader–based transform to select the number of thread groups to execute based on the number of output pixels it needs to fill.

## Parameters

### `outputRect` [in]

Type: **const [D2D1_RECT_L](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh847950(v=vs.85))***

The output rectangle that will be filled by the compute transform.

### `dimensionX` [out]

Type: **UINT32***

The number of threads in the x dimension.

### `dimensionY` [out]

Type: **UINT32***

The number of threads in the y dimension.

### `dimensionZ` [out]

Type: **UINT32***

The number of threads in the z dimension.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

If this call fails, the corresponding [ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect) instance is placed into an error state and fails to draw.

## See also

[ID2D1ComputeTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1computetransform)

[ID2D1EffectContext::LoadComputeShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-loadcomputeshader)