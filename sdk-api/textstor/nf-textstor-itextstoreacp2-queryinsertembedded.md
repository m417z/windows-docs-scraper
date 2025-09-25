# ITextStoreACP2::QueryInsertEmbedded

## Description

Gets a value indicating whether the specified object can be inserted into the document.

## Parameters

### `pguidService` [in]

Pointer to the object type. Can be **NULL**.

### `pFormatEtc` [in]

Pointer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc) structure that contains format data of the object. This parameter cannot be **NULL** if the *pguidService* parameter is **NULL**.

### `pfInsertable` [out]

Receives **TRUE** if the object type can be inserted into the document or **FALSE** if the object type can't be inserted into the document.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *pFormatEtc* parameter is **NULL**. |

## Remarks

The clipboard formats supported by the document are dependent on the application.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-formatetc)

[ITextStoreACP2](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp2)

[InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-insertembedded)

[InsertEmbeddedAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp2-insertembeddedatselection)