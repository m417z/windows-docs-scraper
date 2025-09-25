# IInkWordList::AddWord

## Description

Adds a single word to the [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class) object.

## Parameters

### `NewWord` [in]

The word to add to an [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class) object. The word is not added if it already exists in the list.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | The word already exists in the list. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

If a string is added to a word list, its capitalized versions are also implicitly added. For instance, adding "hello" implicitly adds "Hello" and "HELLO".

## See also

[IInkWordList](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkwordlist)

[InkRecognizerContext Class](https://learn.microsoft.com/windows/desktop/tablet/inkrecognizercontext-class)

[InkWordList Class](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class)

[RemoveWord Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkwordlist-removeword)