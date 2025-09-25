# IMSVidCtl::get__OutputsAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get__OutputsAvailable** method retrieves the output devices that are available in a specified category.

This method is currently not supported.

## Parameters

### `CategoryGuid` [in]

Pointer to a GUID that specifies the category to enumerate.

### `pVal` [out]

Receives an [IMSVidOutputDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidoutputdevices) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

To obtain the available renderers, use the [get_AudioRenderersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_audiorenderersavailable) and [get_VideoRenderersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_videorenderersavailable) methods.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)