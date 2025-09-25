# IRdcGeneratorFilterMaxParameters::SetHorizonSize

## Description

The **SetHorizonSize**
method sets the horizon size—the length over which the FilterMax generator looks
for local maxima. This determines the default smallest size for a chunk.

## Parameters

### `horizonSize` [in]

Specifies the length in bytes of the horizon size.
The valid range is from **MSRDC_MINIMUM_HORIZONSIZE** to
**MSRDC_MAXIMUM_HORIZONSIZE**. If this parameter is not set then a suitable default will
be used.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[GetHorizonSize](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nf-msrdc-irdcgeneratorfiltermaxparameters-gethorizonsize)

[IRdcGeneratorFilterMaxParameters](https://learn.microsoft.com/previous-versions/windows/desktop/api/msrdc/nn-msrdc-irdcgeneratorfiltermaxparameters)