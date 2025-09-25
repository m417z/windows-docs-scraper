# IMSVidCtl::get_AutoSize

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_AutoSize** method retrieves a value that determines whether the Video Control is automatically resized to display its entire contents.

## Parameters

### `pbool` [out]

Pointer to a variable of type **VARIANT_BOOL** that receives the current value of the property.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::put_AutoSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-put_autosize)