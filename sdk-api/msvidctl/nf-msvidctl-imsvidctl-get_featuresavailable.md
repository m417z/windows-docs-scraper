# IMSVidCtl::get_FeaturesAvailable

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_FeaturesAvailable** method retrieves the features that are available on the local system.

## Parameters

### `pVal` [out]

Receives an [IMSVidFeatures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidfeatures) interface pointer. The caller must release the interface.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

This method returns a collection of feature objects. Use the returned [IMSVidFeatures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidfeatures) pointer to enumerate the collection. To activate a feature, add it to the active features collection. To search for a specific feature, call the [IMSVidDevice::get__ClassID](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsviddevice-get__classid) method on each feature and compare the result against the CLSID of the feature you are looking for.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)