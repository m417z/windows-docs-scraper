# IMSVidAnalogTuner::get_SAP

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SAP** method retrieves the tuner's SAP setting to enable secondary audio components.

This method is currently not supported.

## Parameters

### `pfSapOn` [out]

Pointer to a flag indicating whether SAP is on.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IAMTVAudio Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamtvaudio)

[IMSVidAnalogTuner Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidanalogtuner)

[IMSVidAnalogTuner::put_SAP](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidanalogtuner-put_sap)