# IMSVidCtl::put_DisplaySize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_DisplaySize** method specifies the display size.

## Parameters

### `NewValue` [in]

Specifies the display size as a member of the [DisplaySizeList](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/ne-msvidctl-displaysizelist) enumeration.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Setting this property has no effect if the **AutoSize** property is false.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_DisplaySize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_displaysize)

[IMSVidCtl::put_AutoSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_autosize)