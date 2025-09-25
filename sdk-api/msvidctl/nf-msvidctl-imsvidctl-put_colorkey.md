# IMSVidCtl::put_ColorKey

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_ColorKey** method specifies the color key.

## Parameters

### `NewValue` [in]

Specifies the color key as an **OLE_COLOR** value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The color key is used when the video renderer draws to an overlay surface.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_ColorKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_colorkey)