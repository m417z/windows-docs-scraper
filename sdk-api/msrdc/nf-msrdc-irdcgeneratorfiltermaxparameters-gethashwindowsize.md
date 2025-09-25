# IRdcGeneratorFilterMaxParameters::GetHashWindowSize

## Description

The **GetHashWindowSize**
method returns the hash window size—the size of the sliding window used by the
FilterMax generator for computing the hash used in the local maxima calculations.

## Parameters

### `hashWindowSize` [out]

Address of a **ULONG** that will receive the length in bytes of the hash window
size. The valid range is from **MSRDC_MINIMUM_HASHWINDOWSIZE** to
**MSRDC_MAXIMUM_HASHWINDOWSIZE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcGeneratorFilterMaxParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorfiltermaxparameters)

[SetHashWindowSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgeneratorfiltermaxparameters-sethashwindowsize)