# IMFQualityAdviseLimits::GetMinimumQualityLevel

## Description

Gets the minimum quality level that is supported by the component.

## Parameters

### `peQualityLevel` [out]

Receives the minimum quality level, specified as a member of the [MF_QUALITY_LEVEL](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_quality_level) enumeration.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To get the current quality level, call the [IMFQualityAdvise::GetQualityLevel](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfqualityadvise-getqualitylevel) method. To set the quality level, call the [IMFQualityAdvise::SetQualityLevel](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfqualityadvise-setqualitylevel) method.

## See also

[IMFQualityAdviseLimits](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadviselimits)