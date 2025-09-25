# ITextStoreAnchor::InsertEmbeddedAtSelection

## Description

The **ITextStoreAnchor::InsertEmbeddedAtSelection** method inserts an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object at the insertion point or selection. The client that calls this method must have a read/write lock before inserting an **IDataObject** into the text stream.

## Parameters

### `dwFlags` [in]

Specifies whether the *paStart* and *paEnd* parameters will contain the results of the object insertion.

The [TF_IAS_NOQUERY](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants) and TF_IAS_QUERYONLY flags cannot be combined.

| Value | Meaning |
| --- | --- |
| **TF_IAS_NOQUERY** | Text is inserted, and the values of the *ppaStart* and *ppaEnd* parameters can be **NULL**. Use this flag if the results of the text insertion are not required. |
| **TF_IAS_QUERYONLY** | Text is not inserted, and the *ppaStart* and *ppaEnd* anchors contain the results of the text insertion. The values of these parameters depend on how the application implements text insertion into a document.<br><br>Use this flag to view the results of the text insertion without actually inserting the text, for example, to predict the results of collapsing or otherwise adjusting a selection. |

### `pDataObject` [in]

Pointer to the **IDataObject** object to be inserted.

### `ppaStart` [out]

Pointer to the anchor object at the start of the object insertion.

### `ppaEnd` [out]

Pointer to the anchor object at the end of the object insertion. For an insertion point, this parameter value will be the same as the value of the *ppaStart* parameter.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method could not instantiate one of the anchors *paStart* or *paEnd*. |
| **E_INVALIDARG** | The *pchText* parameter is invalid. |
| **E_OUTOFMEMORY** | The method could not instantiate one of the anchors *paStart* or *paEnd*. |
| **TS_E_NOLOCK** | The caller does not have a lock on the document. |

## Remarks

Clients must use this method to insert an object into a text stream, since a [TS_CHAR_EMBEDDED](https://learn.microsoft.com/windows/desktop/TSF/ts-char--constants) constant cannot be passed into [ITextStoreAnchor::SetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-settext).

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchor::QueryInsertEmbedded](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-queryinsertembedded)

[ITextStoreAnchor::SetText](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchor-settext)

[TF_IAS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants)

[TS_CHAR_EMBEDDED](https://learn.microsoft.com/windows/desktop/TSF/ts-char--constants)