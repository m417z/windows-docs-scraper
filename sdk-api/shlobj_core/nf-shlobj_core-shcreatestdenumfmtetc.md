# SHCreateStdEnumFmtEtc function

## Description

[**SHCreateStdEnumFmtEtc** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Creates an [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) object from an array of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures.

## Parameters

### `cfmt` [in]

Type: **UINT**

The number of entries in the *afmt* array.

### `afmt`

Type: **const [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)[]**

An array of [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structures that specifies the clipboard formats of interest.

### `ppenumFormatEtc` [out]

Type: **[IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc)****

When this function returns successfully, receives an [IEnumFORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumformatetc) interface pointer. Receives **NULL** on failure.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.