# IMFSAMIStyle::GetStyles

## Description

Gets a list of the style names defined in the SAMI file.

## Parameters

### `pPropVarStyleArray` [out]

Pointer to a **PROPVARIANT** that receives an array of null-terminated wide-character strings. The **PROPVARIANT** type is VT_VECTOR | VT_LPWSTR. The caller must clear the **PROPVARIANT** by calling **PropVariantClear**.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IMFSAMIStyle](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfsamistyle)

[SAMI Media Source](https://learn.microsoft.com/windows/desktop/medfound/sami-media-source)