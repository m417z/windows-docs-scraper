# IMSVidCtl::put_FeaturesActive

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_FeaturesActive** method specifies a collection of features to activate.

## Parameters

### `pVal` [in]

Pointer to the [IMSVidFeatures](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidfeatures) interface on a collection of features.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

Features represent additional capabilities beyond basic tuning and rendering, such as closed captioning or IP data services. When the Video Control builds the filter graph, it uses the active features collection to configure the graph.

For a default graph, it is not necessary to specify the active features. To activate a feature, create a new [MSVidFeatures](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd695126(v=vs.85)) collection object. Then use the [IMSVidCtl::get_FeaturesAvailable](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_featuresavailable) method to enumerate the available features, and call [IMSVidDevice::get__ClassID](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsviddevice-get__classid) on each feature. If the CLSID matches the feature you wish to activate, add that feature to your MSVidFeatures collection. Then call **put_FeaturesActive** with a pointer to the MSVidFeatures collection.

If the Video Control's state is not **STATE_UNBUILT**, call the [IMSVidCtl::Decompose](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-decompose) to tear down the filter graph before calling this method.

## See also

[IMSVidCtl Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidctl)

[IMSVidCtl::get_FeaturesActive](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_featuresactive)

[IMSVidCtl::get_State](https://learn.microsoft.com/previous-versions/windows/desktop/api/msvidctl/nf-msvidctl-imsvidctl-get_state)