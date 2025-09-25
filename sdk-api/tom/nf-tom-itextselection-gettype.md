# ITextSelection::GetType

## Description

Gets the type of text selection.

## Parameters

### `pType`

Type: **long***

The selection type. The method returns *pType* with one of the values in the following table.

| Selection type | Value | Meaning |
| --- | --- | --- |
| **tomNoSelection** | 0 | No selection and no insertion point. |
| **tomSelectionIP** | 1 | Insertion point. |
| **tomSelectionNormal** | 2 | Single nondegenerate range. |
| **tomSelectionFrame** | 3 | Frame. |
| **tomSelectionColumn** | 4 | Table column. |
| **tomSelectionRow** | 5 | Table rows. |
| **tomSelectionBlock** | 6 | Block selection. |
| **tomSelectionInlineShape** | 7 | Picture. |
| **tomSelectionShape** | 8 | Shape. |

## Return value

Type: **StdMETHODIMP**

The method returns an **HRESULT** value. If the method succeeds, it returns **S_OK**. If *pType* is null, the method fails and it returns E_INVALIDARG.

## See also

**Conceptual**

[ITextSelection](https://learn.microsoft.com/windows/desktop/api/tom/nn-tom-itextselection)

**Reference**

[Text Object Model](https://learn.microsoft.com/windows/desktop/Controls/text-object-model)