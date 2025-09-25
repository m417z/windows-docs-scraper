# IMSVidPlayback::get_EnableResetOnStop

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_EnableResetOnStop** method indicates how playback will resume if the graph is rebuilt.

## Parameters

### `pVal` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_FALSE | The Video Control will not seek to start of the media. |
| VARIANT_TRUE | The Video Control will seek to start of the media. |

## Return value

The method returns an **HRESULT**. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | The method succeeded. |

## Remarks

For more information, see [IMSVidPlayback::put_EnableResetOnStop](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidplayback-put_enableresetonstop).

## See also

[IMSVidPlayback Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidplayback)