# ITLegacyCallMediaControl2::GenerateCustomTones

## Description

The
**GenerateCustomTones** method generates the specified custom tone.

This method is intended for C/C++ applications. Visual Basic and scripting applications should use the
[GenerateCustomTonesByCollection](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itlegacycallmediacontrol2-generatecustomtonesbycollection) method instead.

## Parameters

### `pToneList` [in]

Pointer to a
[TAPI_CUSTOMTONE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ns-tapi3if-tapi_customtone) array that specifies the tones to generate.

### `lNumTones` [in]

The number of entries in the array specified by the *pToneList* parameter.

### `lDuration` [in]

The duration, in milliseconds, during which the tone should be sustained.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method translates to a call to the TAPI 2.*x*
[lineGenerateTone](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratetone) function.

## See also

[ITLegacyCallMediaControl2](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itlegacycallmediacontrol2)

[TAPI_CUSTOMTONE](https://learn.microsoft.com/windows/desktop/api/tapi3if/ns-tapi3if-tapi_customtone)