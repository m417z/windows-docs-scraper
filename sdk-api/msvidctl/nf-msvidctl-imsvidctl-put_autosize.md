# IMSVidCtl::put_AutoSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_AutoSize** method specifies whether the Video Control automatically resizes to display its entire contents.

## Parameters

### `vbool` [in]

Specifies whether the Video Control automatically resizes. Use one of the following values.

| Value | Description |
| --- | --- |
| VARIANT_TRUE | The Video Control automatically resizes. |
| VARIANT_FALSE | The Video Control does not automatically resize. |

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_AutoSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_autosize)