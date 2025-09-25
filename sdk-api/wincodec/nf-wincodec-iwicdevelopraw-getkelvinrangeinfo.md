# IWICDevelopRaw::GetKelvinRangeInfo

## Description

Gets the information about the current Kelvin range of the raw image.

## Parameters

### `pMinKelvinTemp` [out]

Type: **UINT***

A pointer that receives the minimum Kelvin temperature.

### `pMaxKelvinTemp` [out]

Type: **UINT***

A pointer that receives the maximum Kelvin temperature.

### `pKelvinTempStepValue` [out]

Type: **UINT***

A pointer that receives the Kelvin step value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.