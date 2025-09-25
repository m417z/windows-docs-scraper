# MFGetSupportedMimeTypes function

## Description

Retrieves the MIME types that are registered for the source resolver.

## Parameters

### `pPropVarMimeTypeArray` [out]

Pointer to a **PROPVARIANT** that receives the MIME types. Before calling this method, call **PropVariantInit** to initialize the **PROPVARIANT**. If the method succeeds, the **PROPVARIANT** contains an array of wide-character strings. The **PROPVARIANT** data type is VT_VECTOR | VT_LPWSTR. The caller must release the **PROPVARIANT** by calling **PropVariantClear**.

## Return value

The function returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The function succeeded. |

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)