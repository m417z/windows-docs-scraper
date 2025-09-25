# IMSVidCtl::get_OutputsAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_OutputsAvailable** method retrieves the output devices that are available in a specified category.

## Parameters

### `CategoryGuid` [in]

**BSTR** that specifies the GUID of the category to enumerate

### `pVal` [out]

Receives an [IMSVidOutputDevices](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidoutputdevices) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_AudioRenderersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_audiorenderersavailable)

[IMSVidCtl::get_VideoRenderersAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_videorenderersavailable)