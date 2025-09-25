# IMSVidPlayback::put_Rate

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Rate** method sets the playback rate.

## Parameters

### `plRate` [in]

Specifies the playback rate, as a ratio to the authored rate. For example, 0.5 means half the normal speed, 1.0 means normal speed, and 2.0 means twice the normal speed.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | The source filter does not support the specified rate. |
| **ERROR_INVALID_STATE** | The graph is not built. Call the [Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method on the Video Control. |
| **S_OK** | The method succeeded. |

**Note**The value ERROR_INVALID_STATE is converted to an **HRESULT** with the **HRESULT_FROM_WIN32** macro.

## Remarks

Call the [IMSVidCtl::Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method before calling this method.

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)