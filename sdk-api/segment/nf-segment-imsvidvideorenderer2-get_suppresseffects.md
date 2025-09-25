# IMSVidVideoRenderer2::get_SuppressEffects

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SuppressEffects** method retrieves settings that control power management and visual effects.

## Parameters

### `bSuppress` [out]

Receives the value VARIANT_TRUE or VARIANT_FALSE. For more information, see [IMSVidVideoRenderer2::put_SuppressEffects](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer2-put_suppresseffects).

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_POINTER** | NULL pointer argument. |
| **S_OK** | Success. |

## See also

[IMSVidVideoRenderer2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidvideorenderer2)