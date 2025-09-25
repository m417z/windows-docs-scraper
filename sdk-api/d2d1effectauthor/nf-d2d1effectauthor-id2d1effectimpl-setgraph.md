# ID2D1EffectImpl::SetGraph

## Description

The renderer calls this method to provide the effect implementation with a way to specify its transform graph and transform graph changes.

The renderer calls this method when:

* When the effect is first initialized.
* If the number of inputs to the effect changes.

## Parameters

### `transformGraph`

Type: **[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)***

The graph to which the effect describes its transform topology through the SetDescription call.

## Return value

Type: **HRESULT**

An error that prevents the effect from being initialized if called as part of the CreateEffect call. If the effect fails a subsequent SetGraph call:

* The error will be returned from the property method that caused the number of inputs to the effect to change.
* The effect object will be placed into an error state, if subsequently used to render, the context will be placed into a temporary error state, that particular effect will fail to render and the failure will be returned on the next EndDraw or Flush call.

## See also

[ID2D1EffectImpl](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1effectimpl)