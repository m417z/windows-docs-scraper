# IMSVidStreamBufferSource::put_BlockUnrated

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_BlockUnrated** method specifies whether to block unrated content.

## Parameters

### `bBlock` [in]

Specifies one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_FALSE | Do not block unrated content. |
| VARIANT_TRUE | Block unrated content. |

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMSVidStreamBufferSource Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidstreambuffersource)

[IMSVidStreamBufferSource::put_UnratedDelay](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidstreambuffersource-put_unrateddelay)