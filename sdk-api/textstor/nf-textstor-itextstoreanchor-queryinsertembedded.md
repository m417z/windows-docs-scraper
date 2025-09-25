# ITextStoreAnchor::QueryInsertEmbedded

## Description

Determines whether the document can accept an embedded object through the InsertEmbedded or InsertEmbeddedAtSelection methods.

## Parameters

### `pguidService` [in]

Pointer to the object type. If **NULL**, *pFormatEtc* should be used.

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

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::InsertEmbedded](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-insertembedded)

[ITextStoreAnchor::InsertEmbeddedAtSelection](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-insertembeddedatselection)