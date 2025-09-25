# ITextStoreAnchor::InsertTextAtSelection

## Description

Inserts text at the insertion point or selection.

## Parameters

### `dwFlags` [in]

Specifies whether the *paStart* and *paEnd* parameters will contain the results of the text insertion.

The [TF_IAS_NOQUERY](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants) and TF_IAS_QUERYONLY flags cannot be combined.

| Value | Meaning |
| --- | --- |
| **TF_IAS_NOQUERY** | Text is inserted, and the values of the *ppaStart* and *ppaEnd* parameters can be **NULL**. Use this flag if the results of the text insertion are not required. |
| **TF_IAS_QUERYONLY** | Text is not inserted, and the *ppaStart* and *ppaEnd* anchors contain the results of the text insertion. The values of these parameters depend on how the application implements text insertion into a document. Use this flag to view the results of the text insertion without actually inserting the text. Zero-length text can be inserted. |

### `pchText` [in]

Pointer to the string to insert in the document. The string can be **NULL** terminated.

### `cch` [in]

Specifies the text length.

### `ppaStart` [out]

Pointer to the anchor object at the start of the text insertion.

### `ppaEnd` [out]

Pointer to the anchor object at the end of the text insertion. For an insertion point, this parameter value will be the same as the value of the *ppaStart* parameter.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_FAIL** | The method could not instantiate one of the anchors *paStart* or *paEnd*. |
| **E_INVALIDARG** | The *pchText* parameter is invalid. |
| **TS_E_NOLOCK** | The caller does not have a lock on the document. |

## See also

[Compositions](https://learn.microsoft.com/windows/desktop/TSF/compositions)

[ITextStoreAnchor](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreanchor)

[ITextStoreAnchorSink::OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreanchorsink-ontextchange)

[TF_IAS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants)

[TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange)