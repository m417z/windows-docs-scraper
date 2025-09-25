# ITfInsertAtSelection::InsertEmbeddedAtSelection

## Description

The **ITfInsertAtSelection::InsertEmbeddedAtSelection** method inserts an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object at the selection or insertion point.

## Parameters

### `ec` [in]

Identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `dwFlags` [in]

Bit field with one of the following values:

TF_IAS_NOQUERY

The *ppRange* parameter is **NULL** on exit.

TF_IAS_QUERYONLY

Context is not modified but the *ppRange* parameter is set as if the insert occurred. Read-only access is sufficient. If this flag is not set, the *ec* parameter must have read/write access.

TF_IAS_NO_DEFAULT_COMPOSITION

The TSF manager does not create a default composition if a composition is required. The caller must create a composition object that covers the inserted text before releasing the context lock.

### `pDataObject` [in]

Pointer to object to insert.

### `ppRange` [out]

Position of the inserted object. Optional.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_NOLOCK** | The *ec* parameter is an invalid edit cookie. |
| **TF_E_DISCONNECTED** | Context object is not on a document stack. |
| **TS_E_NOSELECTION** | Context has no selection. |
| **TS_E_READONLY** | Selection is read-only. |
| **TF_E_FORMAT** | Context owner cannot handle objects of the type provided by the *pDataObject* parameter. |

## Remarks

Callers can use the [ITfQueryEmbedded::QueryInsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfqueryembedded-queryinsertembedded) method to determine if a particular object type is likely to be accepted by this method.

To insert text instead of an **IDataObject** object, use the [ITfInsertAtSelection::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-inserttextatselection) method.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfInsertAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinsertatselection)

[ITfInsertAtSelection::InsertTextAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-inserttextatselection)

[ITfQueryEmbedded::QueryInsertEmbedded](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfqueryembedded-queryinsertembedded)