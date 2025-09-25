# ITfInsertAtSelection::InsertTextAtSelection

## Description

Inserts text at the selection or insertion point.

## Parameters

### `ec` [in]

Identifies the edit context. This is obtained from [ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext) or [ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession).

### `dwFlags` [in]

Bit field with one of the following values.

| Value | Meaning |
| --- | --- |
| **TF_IAS_NOQUERY** | *ppRange* is **NULL**. This flag cannot be combined with the TF_IAS_QUERYONLY flag. |
| **TF_IAS_QUERYONLY** | The context is not modified, but *ppRange* is set as if the insert had occurred. Read-only access is sufficient. If this flag is not set, *ec* must have read/write access. This flag cannot be combined with the TF_IAS_NOQUERY flag. |
| **TF_IAS_NO_DEFAULT_COMPOSITION** | The manager will not create a default composition if a composition is required. The caller must create a composition object that covers the inserted text before releasing the context lock. |

### `pchText` [in]

Specifies the text to insert.

### `cch` [in]

Specifies the character count of the text in *pchText*.

### `ppRange` [out]

Receives the position of the inserted object.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TF_E_NOLOCK** | The text service does not have a document lock |
| **TF_E_DISCONNECTED** | Context object is not on a document stack. |
| **TS_E_NOSELECTION** | Context has no selection. |
| **TS_E_READONLY** | Selection is read-only. |

## Remarks

To insert an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object instead of text, use [ITfInsertAtSelection::InsertEmbeddedAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-insertembeddedatselection).

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITfDocumentMgr::CreateContext](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfdocumentmgr-createcontext)

[ITfEditSession::DoEditSession](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfeditsession-doeditsession)

[ITfInsertAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nn-msctf-itfinsertatselection)

[ITfInsertAtSelection::InsertEmbeddedAtSelection](https://learn.microsoft.com/windows/desktop/api/msctf/nf-msctf-itfinsertatselection-insertembeddedatselection)