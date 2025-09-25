# IMSVidEVR::get_Presenter

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_Presenter** method retrieves the presenter object for the [Enhanced Video Renderer](https://learn.microsoft.com/windows/desktop/DirectShow/enhanced-video-renderer-filter) (EVR) filter.

## Parameters

### `ppAllocPresent` [out]

Receives a pointer to the [IMFVideoPresenter](https://learn.microsoft.com/windows/desktop/api/evr/nn-evr-imfvideopresenter) interface. This interface is documented in this Media Foundation SDK documentation. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidEVR](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidevr)