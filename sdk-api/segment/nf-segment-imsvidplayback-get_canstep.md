# IMSVidPlayback::get_CanStep

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_CanStep** method queries whether the input source can step frame by frame.

## Parameters

### `fBackwards` [in]

Use one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_FALSE | Query whether the input can step forward |
| VARIANT_TRUE | Query whether the input can step backward. |

### `pfCan` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_FALSE | The source cannot step in the specified direction. |
| VARIANT_TRUE | The source can step in the specified direction. |

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **ERROR_INVALID_STATE** | The graph is not built. Call the [Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method on the Video Control. |
| **S_OK** | The method succeeded. |

**Note**The value ERROR_INVALID_STATE is converted to an **HRESULT** with the **HRESULT_FROM_WIN32** macro.

## Remarks

Call the [IMSVidCtl::Build](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-build) or [IMSVidCtl::View](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-view) method before calling this method.

#### Examples

```cpp

VARIANT_BOOL fCan = VARIANT_FALSE;
hr = m_pPlayback->get_CanStep(VARIANT_FALSE, &fCan);

```

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)