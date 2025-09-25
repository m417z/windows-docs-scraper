# IMSVidPlayback::Step

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Step** method steps through the video stream by a specified number of frames.

## Parameters

### `lStep` [in]

Specifies how many frames to step. If *lStep* is 1, the Video Control steps forward one frame. If *lStep* is a number *N* greater than 1, the Video Control skips *N* - 1 frames and shows the *N*th frame.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented. |
| **ERROR_INVALID_STATE** | The graph is not built. Call the [Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method on the Video Control. |
| **S_OK** | The method succeeded. |

**Note**The value ERROR_INVALID_STATE is converted to an **HRESULT** with the **HRESULT_FROM_WIN32** macro.

## Remarks

Although a negative value for *lStep* is defined as stepping backward, that functionality is currently not implemented, and the method returns E_NOTIMPL.

Call the [IMSVidCtl::Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method before calling this method.

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)

[IMSVidPlayback::get_CanStep](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidplayback-get_canstep)