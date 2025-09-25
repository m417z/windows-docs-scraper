# ITextStoreACP::InsertTextAtSelection

## Description

The **ITextStoreACP::InsertTextAtSelection** method inserts text at the insertion point or selection. A caller must have a read/write lock on the document before inserting text.

## Parameters

### `dwFlags` [in]

Specifies whether the *pacpStart* and *pacpEnd* parameters and the [TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange) structure contain the results of the text insertion.

The [TF_IAS_NOQUERY](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants) and TF_IAS_QUERYONLY flags cannot be combined.

| Value | Meaning |
| --- | --- |
| **0** | Text insertion will occur, and the *pacpStart* and *pacpEnd* parameters will contain the results of the text insertion. The **TS_TEXTCHANGE** structure must be filled with this flag. |
| **TF_IAS_NOQUERY** | Text is inserted, the values of the *pacpStart* and *pacpEnd* parameters can be **NULL**, and the **TS_TEXTCHANGE** structure must be filled. Use this flag to view the results of the text insertion. |
| **TF_IAS_QUERYONLY** | Text is not inserted, and the values for the *pacpStart* and *pacpEnd* parameters contain the results of the text insertion. The values of these parameters depend on how the application implements text insertion into a document. For more information, see the Remarks section. Use this flag to view the results of the text insertion without actually inserting the text. It is not required that you fill the **TS_TEXTCHANGE** structure if you use this flag. |

### `pchText` [in]

Pointer to the string to insert in the document. The string can be **NULL** terminated.

### `cch` [in]

Specifies the text length.

### `pacpStart` [out]

Pointer to the starting application character position where the text insertion occurs.

### `pacpEnd` [out]

Pointer to the ending application character position where the text insertion occurs. This parameter value is the same as the value of the *pacpStart* parameter for an insertion point.

### `pChange` [out]

Pointer to a **TS_TEXTCHANGE** structure with the following members.

| Value | Meaning |
| --- | --- |
| **acpStart** | The starting application character position before the text is inserted into the document. |
| **acpOldEnd** | The ending application character position before the text is inserted into the document. This value is the same as **acpStart** for an insertion point. If this value is different from **acpStart**, then text was selected prior to the text insertion. |
| **acpNewEnd** | The end position after the text insertion occurred. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **TS_E_NOLOCK** | The caller does not have a lock on the document. |
| **E_INVALIDARG** | The *pchText* parameter is invalid. |

## Remarks

The values of the *pacpStart* and the *pacpEnd* parameters depend upon how the client application inserts text into a document. For example, if the application sets the cursor at the start of the inserted text after text insertion, then the value for the *pacpStart* and *pacpEnd* parameters is the same as the **acpStart** member of the **TS_TEXTCHANGE** structure.

Applications should not call the [ITextStoreACPSink::OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-ontextchange) method in response to this method.

## See also

[Compositions](https://learn.microsoft.com/windows/desktop/TSF/compositions)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[ITextStoreACPSink::OnTextChange](https://learn.microsoft.com/windows/desktop/api/textstor/nf-textstor-itextstoreacpsink-ontextchange)

[TF_IAS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants)

[TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange)