# IMFSAMIStyle::GetSelectedStyle

## Description

Gets the current style from the SAMI media source.

## Parameters

### `ppwszStyle` [out]

Receives a pointer to a null-terminated string that contains the name of the style. If no style is currently set, the method returns an empty string. The caller must free the memory for the string by calling [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSAMIStyle](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamistyle)

[SAMI Media Source](https://learn.microsoft.com/windows/desktop/medfound/sami-media-source)