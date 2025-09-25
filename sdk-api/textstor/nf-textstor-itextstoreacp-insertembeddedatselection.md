# ITextStoreACP::InsertEmbeddedAtSelection

## Description

The **ITextStoreACP::InsertEmbeddedAtSelection** method inserts an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) object at the insertion point or selection. The client that calls this method must have a read/write lock before inserting an **IDataObject** object into the document.

## Parameters

### `dwFlags` [in]

Specifies whether the *pacpStart* and *pacpEnd* parameters and the [TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange) structure will contain the results of the object insertion.

The [TF_IAS_NOQUERY](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants) and TF_IAS_QUERYONLY flags cannot be combined.

| Value | Meaning |
| --- | --- |
| **0** | Text insertion will occur, and the *pacpStart* and *pacpEnd* parameters will contain the results of the text insertion. The **TS_TEXTCHANGE** structure must be filled with this flag. |
| **TF_IAS_NOQUERY** | Text is inserted, the values of the *pacpStart* and *pacpEnd* parameters can be **NULL**, and the **TS_TEXTCHANGE** structure must be filled. Use this flag if the results of the text insertion are not required. |
| **TF_IAS_QUERYONLY** | Text is not inserted, and the values for the *pacpStart* and *pacpEnd* parameter contain the results of the text insertion. The values of these parameters depend on how the application implements text insertion into a document. For more information, see the Remarks section.<br><br>Use this flag to view the results of the text insertion without actually inserting the text, for example, to predict the results of collapsing or otherwise adjusting a selection. It is not required that you fill the **TS_TEXTCHANGE** structure with this flag. |

### `pDataObject` [in]

Pointer to the **IDataObject** object to be inserted.

### `pacpStart` [out]

Pointer to the starting application character position where the object insertion will occur.

### `pacpEnd` [out]

Pointer to the ending application character position where the object insertion will occur. This parameter value will be the same as the value of the *pacpStart* parameter for an insertion point.

### `pChange` [out]

Pointer to a **TS_TEXTCHANGE** structure with the following members.

| Value | Meaning |
| --- | --- |
| **acpStart** | The starting application character position before the object is inserted into the document. |
| **acpOldEnd** | The ending application character position before the object is inserted into the document. This value is the same as **acpStart** for an insertion point. If this value is different from **acpStart**, then text was selected prior to the object insertion. |
| **acpNewEnd** | The ending application character position after the object insertion took place. |

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *pchText* parameter is invalid. |
| **TS_E_NOLOCK** | The caller does not have a lock on the document. |

## Remarks

The values of the *pacpStart* and *pacpEnd* parameters depend upon how the client application inserts an object into a document. For example, if the application sets the cursor at the start of the object after object insertion, then the value of the *pacpStart* and *pacpEnd* parameters is the same as the **acpStart** member of the **TS_TEXTCHANGE** structure.

## See also

[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)

[ITextStoreACP](https://learn.microsoft.com/windows/desktop/api/textstor/nn-textstor-itextstoreacp)

[TF_IAS_* Constants](https://learn.microsoft.com/windows/desktop/TSF/tf-ias--constants)

[TS_TEXTCHANGE](https://learn.microsoft.com/windows/desktop/api/textstor/ns-textstor-ts_textchange)