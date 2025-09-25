# ITextStoreAnchor::InsertEmbedded

## Description

Inserts an IDataObject data object into a text stream.

## Parameters

### `dwFlags` [in]

Must be TS_IE_CORRECTION.

### `paStart` [in]

Pointer to the anchor at the start of the object to be inserted.

### `paEnd` [in]

Pointer to the anchor at the end of the object to be inserted.

### `pDataObject` [in]

Pointer to an **IDataObject** data object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method was unable to obtain a valid interface pointer to the start and/or end anchors. |
| **E_INVALIDARG** | One or more input parameters are invalid. |
| **E_NOTIMPL** | The application does not support embedded objects. |
| **TS_E_FORMAT** | The application does not support the data type contained in *pDataObject*. |
| **TS_E_INVALIDPOS** | *paStart* and/or *paEnd* are not within the document. |
| **TS_E_NOLOCK** | The caller does not have a read/write lock. |

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::QueryInsertEmbedded](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-queryinsertembedded)

[ITextStoreAnchor::SetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-settext)

[TS_CHAR_EMBEDDED](https://learn.microsoft.com/windows/desktop/TSF/ts-char--constants)

[TS_IE_* Constants](https://learn.microsoft.com/windows/desktop/TSF/ts-ie--constants)