# IMSVidCtl::get_TabStop

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_TabStop** method queries whether a user can use the TAB key to give the focus to the Video Control.

## Parameters

### `pbool` [out]

Receives one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The Video Control is in the tabbing order. |
| VARIANT_FALSE | The Video Control is not in the tabbing order. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_TabStop](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_tabstop)