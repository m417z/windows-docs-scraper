# ITextStoreACP::QueryInsertEmbedded

## Description

Gets a value indicating whether the specified object can be inserted into the document.

## Parameters

### `pguidService` [in]

Pointer to the object type. Can be **NULL**.

### `pFormatEtc` [in]

Pointer to the [FORMATETC](https://learn.microsoft.com/windows/desktop/com/the-formatetc-structure) structure that contains format data of the object. This parameter cannot be **NULL** if the *pguidService* parameter is **NULL**.

### `pfInsertable` [out]

Receives **TRUE** if the object type can be inserted into the document or **FALSE** if the object type cannot be inserted into the document.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *pFormatEtc* parameter is **NULL**. |

## Remarks

The clipboard formats supported by the document are dependent on the application.

## See also

[FORMATETC](https://learn.microsoft.com/windows/desktop/com/the-formatetc-structure)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACP::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-insertembedded)

[ITextStoreACP::InsertEmbeddedAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacp-insertembeddedatselection)