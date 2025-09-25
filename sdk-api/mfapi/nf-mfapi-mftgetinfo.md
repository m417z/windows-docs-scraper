# MFTGetInfo function

## Description

Gets information from the registry about a Media Foundation transform (MFT).

## Parameters

### `clsidMFT` [in]

The CLSID of the MFT.

### `pszName` [out]

Receives a pointer to a wide-character string containing the friendly name of the MFT. The caller must free the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). This parameter can be **NULL**.

### `ppInputTypes` [out]

Receives a pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array describes an input format that the MFT supports. The caller must free the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). This parameter can be **NULL**.

### `pcInputTypes` [out]

Receives the number of elements in the *ppInputTypes* array. If *ppInputTypes* is **NULL**, this parameter is ignored and can be **NULL**.

### `ppOutputTypes` [out]

Receives a pointer to an array of [MFT_REGISTER_TYPE_INFO](https://learn.microsoft.com/windows/win32/api/mfobjects/ns-mfobjects-mft_register_type_info) structures. Each member of the array describes an output format that the MFT supports. The caller must free the array by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree). This parameter can be **NULL**.

### `pcOutputTypes` [out]

Receives the number of elements in the *ppOutputType* array. If *ppOutputTypes* is **NULL**, this parameter is ignored and can be **NULL**.

### `ppAttributes` [out]

Receives a pointer to the [IMFAttributes](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfattributes) interface of an attribute store. The caller must release the interface. The attribute store might contain attributes that are stored in the registry for the specified MFT. (For more information, see [MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister).) If no attributes are stored in the registry for this MFT, the attribute store is empty.

This parameter can be **NULL**.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[MFTEnum](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftenum)

[MFTRegister](https://learn.microsoft.com/windows/desktop/api/mfapi/nf-mfapi-mftregister)

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)

[Media Foundation Transforms](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-transforms)

[Registering and Enumerating MFTs](https://learn.microsoft.com/windows/desktop/medfound/registering-and-enumerating-mfts)