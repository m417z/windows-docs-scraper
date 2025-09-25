# IWICDevelopRaw::SetExposureCompensation

## Description

Sets the exposure compensation stop value.

## Parameters

### `ev` [in]

Type: **double**

The exposure compensation value. The value range for exposure compensation is -5.0 through +5.0, which equates to 10 full stops.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that a codec report that this method is supported even if the results at the outer range limits are not of perfect quality.