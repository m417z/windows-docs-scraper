# ID2D1TransformGraph::SetSingleTransformNode

## Description

Sets a single transform node as being equivalent to the whole graph.

## Parameters

### `node`

Type: **[ID2D1TransformNode](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformnode)***

The node to be set.

## Return value

Type: **HRESULT**

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| HRESULT | Description |
| --- | --- |
| S_OK | No error occurred |
| E_OUTOFMEMORY | Direct2D could not allocate sufficient memory to complete the call. |

## Remarks

This equivalent to calling [ID2D1TransformGraph::Clear](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1transformgraph-clear), adding a single node, connecting all of the node inputs to the effect inputs in order, and setting the transform not as the graph output.

#### Examples

```cpp
class CMySimpleEffect : public ID2D1EffectImpl
{
public:

    IFACEMETHODIMP SetGraph(
        __in ID2D1TransformGraph   *pGraph
        )
    {
        HRESULT hr = S_OK;

        CMyTransform *pTransform = new CMyTransform();

        hr = pTransform ? S_OK : E_OUTOFMEMORY;

        if (SUCCEEDED(hr))
        {
            hr = graph->SetSingleTransformNode(pTransform);

            pTransform->Release();
        }

        return hr;
    }

private:

    class CMyTransform : public ID2D1DrawTransform
    {
        // <Snip> Implementation of transform </Snip>
    };

};

```

## See also

[ID2D1TransformGraph](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nn-d2d1effectauthor-id2d1transformgraph)