# IMSVidClosedCaptioning::get_Enable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Enable** method queries whether closed captioning is enabled.

## Parameters

### `On` [out]

Pointer to a variable that receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | Closed captioning is enabled. |
| VARIANT_FALSE | Closed captioning is disabled. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidClosedCaptioning Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidclosedcaptioning)

[IMSVidClosedCaptioning::put_Enable](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidclosedcaptioning-put_enable)