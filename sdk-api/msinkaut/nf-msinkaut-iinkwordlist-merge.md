# IInkWordList::Merge

## Description

Merges the specified [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class) object into this word list.

## Parameters

### `MergeWordList` [in]

The word list to merge into this word list. Words that already exist in the list are not added.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## See also

[IInkWordList](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkwordlist)

[InkWordList Class](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class)