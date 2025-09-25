# IMSVidPlayback::put_PositionMode

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_PositionMode** method specifies how position values will be interpreted by this interface.

## Parameters

### `lPositionMode` [in]

Specifies one of the following values.

| Value | Description |
| --- | --- |
| FrameMode | Position values are specified as frame numbers. |
| TenthsSecondsMode | Position values are specified as hundredths of seconds. |

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_STATE** | The graph is not built. Call the [Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method on the Video Control. |
| **E_FAIL** | Failed. Possibly the source does not support this mode. |
| **E_INVALIDARG** | Invalid argument. |
| **S_OK** | The method succeeded. |

**Note**The value ERROR_INVALID_STATE is converted to an **HRESULT** with the **HRESULT_FROM_WIN32** macro.

## Remarks

The position mode determines how the parameters are interpreted for the following methods:

* [IMSVidPlayback::get_Length](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidplayback-get_length)
* [IMSVidPlayback::get_CurrentPosition](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidplayback-get_currentposition)
* [IMSVidPlayback::put_CurrentPosition](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidplayback-put_currentposition)

Call the [IMSVidCtl::Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method before calling this method.

#### Examples

```cpp

hr = m_pPlayback->put_PositionMode(TenthsSecondsMode);

```

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)

[get_PositionMode](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidplayback-get_positionmode)