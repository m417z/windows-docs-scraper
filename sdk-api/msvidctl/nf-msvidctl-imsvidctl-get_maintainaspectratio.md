# IMSVidCtl::get_MaintainAspectRatio

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_MaintainAspectRatio** method queries whether the Video Control maintains the aspect ratio of the source video.

## Parameters

### `CurrentValue` [out]

Receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The Video Control will maintain the aspect ratio of the source video. |
| VARIANT_FALSE | The Video Control will stretch the video to fill the window. |

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | NULL pointer argument. |

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_MaintainAspectRatio](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_maintainaspectratio)