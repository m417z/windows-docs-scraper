# IRdcGeneratorFilterMaxParameters::GetHorizonSize

## Description

The **GetHorizonSize**
method returns the horizon size—the length over which the FilterMax generator looks
for local maxima. This determines the default smallest size for a chunk.

## Parameters

### `horizonSize` [out]

Address of a **ULONG** that will receive the length in bytes of the horizon size.
The valid range is from **MSRDC_MINIMUM_HORIZONSIZE** to
**MSRDC_MAXIMUM_HORIZONSIZE**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IRdcGeneratorFilterMaxParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorfiltermaxparameters)

[SetHorizonSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgeneratorfiltermaxparameters-sethorizonsize)