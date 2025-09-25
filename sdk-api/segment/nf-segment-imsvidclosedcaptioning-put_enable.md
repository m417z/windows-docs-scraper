# IMSVidClosedCaptioning::put_Enable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_Enable** method enables or disables closed captioning.

## Parameters

### `On` [in]

Specifies whether to enable or disable the closed captioning feature. Use one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | Enable closed captioning. |
| VARIANT_FALSE | Disable closed captioning. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidClosedCaptioning Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidclosedcaptioning)

[IMSVidClosedCaptioning::get_Enable](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidclosedcaptioning-get_enable)