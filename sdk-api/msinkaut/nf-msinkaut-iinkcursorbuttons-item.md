# IInkCursorButtons::Item

## Description

Retrieves the [IInkCursorButton](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursorbutton) object at the specified index or string identifier within the [IInkCursorButtons](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursorbuttons) collection.

## Parameters

### `Identifier` [in]

The zero-based index or BSTR identifier of the [IInkCursorButton](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursorbutton) object to get.

For more information about the VARIANT and BSTR data types, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Button` [out, retval]

Upon return, contains the [IInkCursorButton](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursorbutton) object at the specified index within the [IInkCursorButtons](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursorbuttons) collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **CO_E_CLASSTRING** | Invalid GUID format. |
| **DISP_E_TYPEMISMATCH** | One of the parameters is not a valid VARIANT type. |
| **E_INVALIDARG** | Invalid argument. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |
| **REGDB_CLASSNOTREG** | Type object not registered. |
| **E_OUTOFMEMORY** | Cannot allocate memory to complete the operation. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **TPC_E_RECOGNIZER_NOT_REGISTERED** | The recognizers registry key is corrupted or your environment does not support handwriting recognition. |

## Remarks

An error occurs if the index doesn't match any existing member of the collection.

The **Item** method takes an input argument of type VARIANT. However, the subtype of this variable must be integer or string (BSTR). This means that when you are using late binding, such as when you use a scripting language, you must pass in the argument as a STRING literal and not use a variable.

## See also

[IInkCursorButton Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursorbutton)

[IInkCursorButtons Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursorbuttons)