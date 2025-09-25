# IMSVidGraphSegmentContainer::get_Graph

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Graph** method returns a pointer to the Filter Graph Manager.

## Parameters

### `ppGraph` [in]

Address of a variable that receives an [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface pointer.

## Return value

Returns S_OK if successful, or an **HRESULT** error code otherwise.

## Remarks

Objects can use this method to find a specific DirectShow filter in the filter graph. It is not recommended that applications use this method. Applications should always control the filter graph using the Video Control.

The returned [IGraphBuilder](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-igraphbuilder) interface has an outstanding reference count. The caller must release the interface.

#### Examples

```cpp

CComQIPtr<IMSVidGraphSegmentContainer> pSeg(m_pVideoControl);
if (pSeg)
{
    CComPtr<IGraphBuilder> pGraph;
    hr = pSeg->get_Graph(&pGraph);
    if (SUCCEEDED(hr))
    {
        // Use IGraphBuilder::EnumFilters to enumerate the filters.
    }
}

```

## See also

[IMSVidGraphSegmentContainer Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidgraphsegmentcontainer)