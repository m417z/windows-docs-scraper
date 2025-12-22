# PropVariantToVariant function

## Description

Converts the contents of a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure to a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure.

## Parameters

### `pPropVar` [in]

Type: **const [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to a source [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure.

### `pVar` [out]

Type: **VARIANT***

Pointer to a [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) structure. When this function returns, the **VARIANT** contains the converted information.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Normally, the data stored in the [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) is copied to the [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) without a datatype change. However, in the following cases, there is no direct **VARIANT** support for the datatype, and they are converted as shown.

| Original [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) Type | Stored as [VARIANT](https://learn.microsoft.com/windows/desktop/api/oaidl/ns-oaidl-variant) Type |
| --- | --- |
| VT_BLOB, VT_STREAM | VT_UNKNOWN. The **punkVal** member will contain a pointer to an [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) that contains the source data. |
| VT_LPSTR, VT_LPWSTR, VT_CLSID | VT_BSTR |
| VT_FILETIME | VT_DATE |
| VT_VECTOR\|x | VT_ARRAY\|y |

The following types cannot be converted with this function.

* VT_STORAGE
* VT_BLOB_OBJECT
* VT_STREAMED_OBJECT
* VT_STORED_OBJECT
* VT_CF
* VT_VECTOR | VT_CF