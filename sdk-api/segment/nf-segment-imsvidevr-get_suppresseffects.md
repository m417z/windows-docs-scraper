# IMSVidEVR::get_SuppressEffects

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **get_SuppressEffects** method queries whether the [Video Control](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ee663618(v=vs.85)) configures the system for optimal video playback

## Parameters

### `bSuppress` [out]

Receives a **VARIANT_BOOL**. For more information, see [IMSVidEVR::put_SuppressEffects](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidevr-put_suppresseffects). The default value is VARIANT_TRUE.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## See also

[IMSVidEVR](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidevr)