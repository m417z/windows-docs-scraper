# MFCreateWaveFormatExFromMFMediaType function

## Description

Converts a Media Foundation audio media type to a **WAVEFORMATEX** structure.

## Parameters

### `pMFType`

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type.

### `ppWF`

Receives a pointer to the **WAVEFORMATEX** structure. The caller must release the memory allocated for the structure by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

### `pcbSize`

Receives the size of the **WAVEFORMATEX** structure.

### `Flags`

Contains a flag from the [MFWaveFormatExConvertFlags](https://learn.microsoft.com/windows/desktop/api/mfapi/ne-mfapi-mfwaveformatexconvertflags) enumeration.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## Remarks

If the **wFormatTag** member of the returned structure is **WAVE_FORMAT_EXTENSIBLE**, you can cast the pointer to a **WAVEFORMATEXTENSIBLE** structure.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Type Conversions](https://learn.microsoft.com/windows/desktop/medfound/media-type-conversions)

[Media Types](https://learn.microsoft.com/windows/desktop/medfound/media-types)