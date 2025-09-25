# MFCreateSequencerSegmentOffset function

## Description

Creates a **PROPVARIANT** that can be used to seek within a sequencer source presentation.

## Parameters

### `dwId` [in]

Sequencer element identifier. This value specifies the segment in which to begin playback. The element identifier is returned in the [IMFSequencerSource::AppendTopology](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfsequencersource-appendtopology) method.

### `hnsOffset` [in]

Starting position within the segment, in 100-nanosecond units.

### `pvarSegmentOffset` [out]

Pointer to a **PROPVARIANT**. The method fills in the **PROPVARIANT** with the information needed for performing a seek operation. The caller must free the **PROPVARIANT** by calling **PropVariantClear**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The **PROPVARIANT** returned in *pvarSegmentOffset* can be used for the *pvarStartPosition* parameter in the [IMFMediaSession::Start](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasession-start) method. Use the time format **GUID MF_TIME_FORMAT_SEGMENT_OFFSET**.

#### Examples

```cpp
// Skips to the specified segment in the sequencer source

HRESULT CPlaylist::SkipTo(DWORD index)
{
    if (index >= m_count)
    {
        return E_INVALIDARG;
    }

    MFSequencerElementId ID = m_segments[index].SegmentID;

    PROPVARIANT var;

    HRESULT hr = MFCreateSequencerSegmentOffset(ID, NULL, &var);

    if (SUCCEEDED(hr))
    {
        hr = m_pSession->Start(&MF_TIME_FORMAT_SEGMENT_OFFSET, &var);
        PropVariantClear(&var);
    }
    return hr;
}

```

## See also

[MFTIME](https://learn.microsoft.com/windows/desktop/medfound/mftime)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/sequencer-source)

[Using the Sequencer Source](https://learn.microsoft.com/windows/desktop/medfound/using-the-sequencer-source)