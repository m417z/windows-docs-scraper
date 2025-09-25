# MFCreateAggregateSource function

## Description

Creates a media source that aggregates a collection of media sources.

## Parameters

### `pSourceCollection` [in]

A pointer to the [IMFCollection](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfcollection) interface of the collection object that contains a list of media sources.

### `ppAggSource` [out]

Receives a pointer to the [IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource) interface of the aggregated media source. The caller must release the interface.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *pSourceCollection* collection does not contain any elements. |

## Remarks

The aggregated media source is useful for combining streams from separate media sources. For example, you can use it to combine a video capture source and an audio capture source.

#### Examples

```cpp
HRESULT CreateAggregatedSource(
    IMFMediaSource *pSource1,
    IMFMediaSource *pSource2,
    IMFMediaSource **ppAggSource
    )
{
    *ppAggSource = NULL;

    IMFCollection *pCollection = NULL;

    HRESULT hr = MFCreateCollection(&pCollection);

    if (SUCCEEDED(hr))
    {
        hr = pCollection->AddElement(pSource1);
    }
    if (SUCCEEDED(hr))
    {
        hr = pCollection->AddElement(pSource2);
    }
    if (SUCCEEDED(hr))
    {
        hr = MFCreateAggregateSource(pCollection, ppAggSource);
    }
    SafeRelease(&pCollection);
    return hr;
}

```

## See also

[IMFMediaSource](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediasource)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)