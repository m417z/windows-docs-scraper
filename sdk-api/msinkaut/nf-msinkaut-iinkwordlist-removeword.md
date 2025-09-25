# IInkWordList::RemoveWord

## Description

Removes a single word from an [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class).

## Parameters

### `RemoveWord` [in]

The word to remove from the [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class).

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

If a string is added to a word list, its capitalized versions are also implicitly added. For instance, adding "hello" implicitly adds "Hello" and "HELLO". Therefore, removing "hello" also implicitly removes "Hello" and "HELLO". However, if you add "hello" and then try to remove "Hello", the **RemoveWord** call has no effect, because "Hello" was never explicitly added.

## See also

[AddWord Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkwordlist-addword)

[IInkWordList](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinkwordlist)

[InkWordList Class](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class)