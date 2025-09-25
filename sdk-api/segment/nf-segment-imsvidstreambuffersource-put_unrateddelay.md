# IMSVidStreamBufferSource::put_UnratedDelay

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_UnratedDelay** method specifies how long the Video Control will play unrated content before blocking it. The value is ignored until the [put_BlockUnrated](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidstreambuffersource-put_blockunrated) method is called with the value VARIANT_TRUE.

## Parameters

### `dwDelay` [in]

Specifies the delay before blocking unrated content, in milliseconds.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferSource Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersource)

[IMSVidStreamBufferSource::put_BlockUnrated](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidstreambuffersource-put_blockunrated)