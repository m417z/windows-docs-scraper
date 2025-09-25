# ITfRange::InsertEmbedded

## Description

The **ITfRange::InsertEmbedded** method inserts an object at the location of the start anchor of the range of text.

## Parameters

### `ec` [in]

Edit cookie obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `dwFlags` [in]

Bit fields that specify how insertion should occur. If [TF_IE_CORRECTION](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants) is set, the operation is a correction, so that other text services can preserve data associated with the original text.

### `pDataObject` [in]

Pointer to the data transfer object to be inserted.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_NOTIMPL** | The implementing application does not expose embedded objects in its stream. |
| **TF_E_COMPOSITION_REJECTED** | The context owner rejected a default composition. |
| **TF_E_FORMAT** | The context owner cannot handle the specified object type. |
| **TF_E_NOLOCK** | The value of the *ec* parameter is an invalid cookie, or the caller does not have a read-only lock. |
| **TF_E_RANGE_NOT_COVERED** | The caller already has an active composition, but the range is positioned over text not covered by the composition. |
| **TF_E_READONLY** | The document or the location of the range cannot be modified. |

## Remarks

Use this method to insert objects into the text stream, because the [TF_CHAR_EMBEDDED](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants) object placeholder character cannot be passed into [ITfRange::SetText](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-settext). This method is modeled after the OLE clipboard API, with applications using *pDataObject* as they would an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) returned from OleGetClipboard.

When a range covers multiple regions, the method should be called on each region separately. Otherwise, the method might fail.

By default, text services start and end a temporary composition that covers the range, to ensure that context owners consistently recognize compositions over edited text. If the composition owner rejects a default composition, then the method returns TF_E_COMPOSITION_REJECTED. Default compositions are only created if the caller has not already started one. If the caller has an active composition, the call fails.

To determine in advance whether a context owner supports insertion of a particular object, use [ITfQueryEmbedded::QueryInsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfqueryembedded-queryinsertembedded).

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfRange](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfrange)

[ITfRange::GetEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfrange-getembedded)

[Miscellaneous Framework Constants](https://learn.microsoft.com/windows/desktop/TSF/miscellaneous-framework-constants)

[Text Stores](https://learn.microsoft.com/windows/desktop/TSF/text-stores)