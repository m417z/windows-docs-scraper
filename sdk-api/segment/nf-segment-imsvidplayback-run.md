# IMSVidPlayback::Run

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **Run** method runs the playback device.

Applications should call the [IMSVidCtl::Run](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-run) method, rather than this method.

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | Not implemented. |
| **S_OK** | The method succeeded. |

## Remarks

This method allows for direct control of the source. However, if the underlying source filter is controlled using the standard DirectShow [IMediaControl](https://learn.microsoft.com/windows/desktop/api/control/nn-control-imediacontrol) interface, this method returns E_NOTIMPL.

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)