# IInkExtendedProperties::Remove

## Description

Removes the [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) object from the [IInkExtendedProperties](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties) collection.

## Parameters

### `Identifier` [in]

The identifier of the [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) object to remove from the collection. The identifier can be a globally unique identifier (GUID), an index, or an extended property object.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **TPC_E_INVALID_PROPERTY** | Property could not be found (invalid GUID or index). |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | Invalid display handle. |
| **E_UNEXPECTED** | Unexpected parameter or property type. |

## Remarks

This method removes only the extended property from a snapshot of, or reference to, the ink data and does not remove the actual ink data.

The *Identifier* parameter can be a BSTR, a LONG, or an [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch). Use a BSTR for the GUID of the property, a LONG for the index of the property, and an **IDispatch** for a reference to a specific property. To specify the GUID of the property when you are using late binding, such as when you use a scripting language, you must pass in the argument as a STRING literal and not use a variable.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

## See also

[IInkExtendedProperties Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties)