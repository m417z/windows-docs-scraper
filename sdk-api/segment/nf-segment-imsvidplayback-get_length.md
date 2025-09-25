# IMSVidPlayback::get_Length

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Length** method retrieves the length of the playback source.

## Parameters

### `lLength` [out]

Pointer to a variable that receives the length. The units for the returned value are determined by the current position mode.

| Position Mode | Returned Value |
| --- | --- |
| FrameMode | Frame number |
| TenthsSecondsMode | Hundredths of seconds |

To set the position mode, call [IMSVidPlayback::put_PositionMode](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidplayback-put_positionmode).

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_NOINTERFACE** | The source does not support getting the length. |
| **E_POINTER** | NULL pointer argument. |
| **ERROR_INVALID_STATE** | The graph is not built. Call the [Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method on the Video Control. |
| **S_OK** | The method succeeded. |

**Note**The value ERROR_INVALID_STATE is converted to an **HRESULT** with the **HRESULT_FROM_WIN32** macro.

## Remarks

Call the [IMSVidCtl::Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method before calling this method.

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)