# IMFQualityAdviseLimits::GetMaximumDropMode

## Description

Gets the maximum *drop mode*. A higher drop mode means that the object will, if needed, drop samples more aggressively to match the presentation clock.

## Parameters

### `peDropMode` [out]

Receives the maximum drop mode, specified as a member of the [MF_QUALITY_DROP_MODE](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_quality_drop_mode) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the current drop mode, call the [IMFQualityAdvise::GetDropMode](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfqualityadvise-getdropmode) method. To set the drop mode, call the [IMFQualityAdvise::SetDropMode](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfqualityadvise-setdropmode) method.

## See also

[IMFQualityAdviseLimits](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadviselimits)