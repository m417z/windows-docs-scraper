# IMSVidFilePlayback2::put___SourceFilter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005 or later.

The **put___SourceFilter** method sets the CLSID of a DirectShow source filter to use for this source.

## Parameters

### `FileName` [in]

Specifies the CLSID of the source filter.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the CLSID is GUID_NULL, the [MSVidFilePlaybackDevice](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidfileplaybackdevice) object uses the default source filter for the file name given in [IMSVidFilePlayback::put_FileName](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidfileplayback-put_filename).

## See also

[IMSVidFilePlayback2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidfileplayback2)