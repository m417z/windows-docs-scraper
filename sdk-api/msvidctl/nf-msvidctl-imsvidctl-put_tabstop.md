# IMSVidCtl::put_TabStop

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_TabStop** method specifies whether a user can use the TAB key to give the focus to the Video Control.

## Parameters

### `vbool` [in]

Specifies one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | Include the Video Control in the tabbing order. |
| VARIANT_FALSE | Do not include the Video Control in the tabbing order. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_TabStop](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_tabstop)