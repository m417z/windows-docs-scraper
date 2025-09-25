# IMSVidCtl::put_BackColor

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_BackColor** method specifies the background color of the Video Control.

## Parameters

### `backcolor` [in]

Specifies the background color as an **OLE_COLOR** value.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The Video Control uses the background color when the filter graph is stopped or unbuilt. It also uses this color in letterbox mode to paint unused areas of the video rectangle. The background color is sometimes called the "border" color.

#### Examples

```cpp

COLORREF orange = RGB(0xFF, 0x80, 0x00);
hr = pVideoControl->put_BackColor(static_cast<OLE_COLOR>(orange));

```

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_BackColor](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_backcolor)

[IVMRWindowlessControl::SetBorderColor](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-ivmrwindowlesscontrol-setbordercolor)