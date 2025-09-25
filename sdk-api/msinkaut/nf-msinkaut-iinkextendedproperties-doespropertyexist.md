# IInkExtendedProperties::DoesPropertyExist

## Description

Retrieves a value that indicates whether an [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) object exists within an [IInkExtendedProperties](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties) collection.

## Parameters

### `Guid` [in]

Specifies the globally unique identifier (GUID) of the property to be checked.

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `DoesPropertyExist` [out, retval]

When this method returns, contains **VARIANT_TRUE** if the property exists within the collection; otherwise, **VARIANT_FALSE**.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_INVALIDARG** | Invalid display handle. |
| **TPC_E_INVALID_STROKE** | The stroke is invalid. |

## See also

[IInkExtendedProperties Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties)