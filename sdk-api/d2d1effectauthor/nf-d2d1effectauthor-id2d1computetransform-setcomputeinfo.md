# ID2D1ComputeTransform::SetComputeInfo

## Description

Sets the render information used to specify the compute shader pass.

## Parameters

### `computeInfo` [in]

Type: **[ID2D1ComputeInfo](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1computeinfo)***

The render information object to set.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

If this method fails, [ID2D1TransformGraph::AddNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transformgraph-addnode) fails.

## See also

[ID2D1ComputeTransform](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1computetransform)

[ID2D1EffectContext::LoadComputeShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-loadcomputeshader)