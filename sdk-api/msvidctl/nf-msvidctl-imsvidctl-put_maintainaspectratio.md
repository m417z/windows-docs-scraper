# IMSVidCtl::put_MaintainAspectRatio

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_MaintainAspectRatio** method specifies whether the Video Control maintains the aspect ratio of the source video.

## Parameters

### `NewValue` [in]

Specifies one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The Video Control will maintain the aspect ratio of the source video. |
| VARIANT_FALSE | The Video Control will stretch the video to fill the window. (Default.) |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_MaintainAspectRatio](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_maintainaspectratio)