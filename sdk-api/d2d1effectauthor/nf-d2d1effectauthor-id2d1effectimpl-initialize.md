# ID2D1EffectImpl::Initialize

## Description

The effect can use this method to do one time initialization tasks. If this method is not needed, the method can just return **S_OK**.

## Parameters

### `effectContext` [in]

Type: **[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)***

An internal context interface that creates and returns effect author–centric types.

### `transformGraph` [in]

Type: **[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)***

The effect can
populate the transform graph with a topology and can update it later.

## Return value

Type: **HRESULT**

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

This moves resource creation cost to the [CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect) call, rather than during rendering.

If the implementation fails this call, the corresponding [ID2D1DeviceContext::CreateEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1devicecontext-createeffect) call also fails.

The following example shows an effect implementing an initialize method.

#### Examples

The example here shows an effect implementing an initialize method.

```cpp
class CEffectImplementation : public ID2D1EffectImpl
{
public:

    virtual ~CEffectImplementation()
    {
        if (_pContextInternal != NULL)
        {
            _pContextInternal->Release();
        }
    }

    IFACEMETHODIMP Initialize(__in ID2D1DeviceContextInternal *pContextInternal, __in ID2D1TransformGraph *pTransformGraph)
    {
        HRESULT hr = S_OK;

        _pContextInternal = pContextInternal;
        _pContextInternal->AddRef();

								_pTransformGraph = pTransformGraph;
        _pTransformGraph>AddRef();

								// Populate the transform graph.					

        return S_OK;
    }

private:

    ID2D1EffectContext *_pContextInternal;
    ID2D1TransformGraph *_pTransformGraph;
};

```

## See also

[ID2D1DeviceContext](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1devicecontext)

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)