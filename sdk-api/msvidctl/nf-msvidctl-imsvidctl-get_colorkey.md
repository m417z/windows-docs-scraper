# IMSVidCtl::get_ColorKey

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_ColorKey** method retrieves the color key that the video renderer is using.

## Parameters

### `CurrentValue` [out]

Receives an **OLE_COLOR** value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The color key is used when the video renderer draws to an overlay surface.

#### Examples

```cpp

OLE_COLOR ocKey;
COLORREF clrKey;
pVideoControl->get_ColorKey(&ocKey);
OleTranslateColor(ocKey, 0, &clrKey);
```

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_ColorKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_colorkey)

[IVMRWindowlessControl::GetColorKey](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrwindowlesscontrol-getcolorkey)