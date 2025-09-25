# ID2D1EffectContext::CreateTransformNodeFromEffect

## Description

Wraps an effect graph into a single transform node and then inserted into a transform graph. This allows an effect to aggregate other effects. This will typically be done in order to allow the effect properties to be re-expressed with a different contract, or to allow different components to integrate each-other’s effects.

## Parameters

### `effect` [in]

Type: **[ID2D1Effect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1effect)***

The effect to be wrapped in a transform node.

### `transformNode` [out]

Type: **[ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode)****

The returned transform node that encapsulates the effect graph.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred. |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |
| E_INVALIDARG | An invalid parameter was passed to the returning function. |

## See also

[ID2D1EffectContext](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectcontext)