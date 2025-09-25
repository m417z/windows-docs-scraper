# IInkWordList2::AddWords

## Description

Adds more than one word to an [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class) in a single operation.

## Parameters

### `NewWords` [in]

A **BSTR** of **NULL** separated words terminated by a double **NULL** containing the words to add to the [InkWordList](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class).

For more information about the **BSTR** data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | At least one word already exists in the list. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |

## Remarks

To access this method, first create and instance of the [InkWordList Class](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class), then call [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to get a pointer to the [IInkWordList2 Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkwordlist2). Use this pointer to call the **AddWords Method**.

## See also

[AddWord Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkwordlist-addword)

[IInkWordList2 Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkwordlist2)

[InkWordList Class](https://learn.microsoft.com/windows/desktop/tablet/inkwordlist-class)