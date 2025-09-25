# IInkExtendedProperties::Add

## Description

Creates and adds an [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) object to the [IInkExtendedProperties](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties) collection.

## Parameters

### `Guid` [in]

 The name of the new [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) object. The name is expressed as a BSTR that represents the globally unique identifier (GUID) in the following format:

{dfc71f44-354b-4ca1-93d7-7459410b6343} (Including curly braces)

For more information about the BSTR data type, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `Data` [in]

 The data for the new [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) object.

For more information about the VARIANT structure, see [Using the COM Library](https://learn.microsoft.com/windows/desktop/tablet/using-the-com-library).

### `InkExtendedProperty` [out, retval]

When this method returns, contains a pointer to the new extended property.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | A parameter contained an invalid pointer. |
| **E_INVALIDARG** | The user did not specify data. |
| **CO_E_CLASSSTRING** | Invalid GUID format. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **TPC_E_INVALID_STROKE** | The stroke is invalid. |

## Remarks

**Note** You cannot store an empty [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) object. The object must contain data before it can be stored. For example, if you try to add extended properties to a stroke for later use, an exception is thrown if the extended property contains no data.

The following types are acceptable:

* Byte or CHAR array
* Arrays of integers, floats, large integers, doubles, dates, or decimals
* Booleans (but not arrays of Booleans)
* BSTRs (but not arrays of BSTRs)
* Arrays of Variants. All arrays of variants passed as an [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) must be of the same type and be all numeric. For example, variant arrays of BSTRS, arrays of arrays, VT_NULL and VT_EMPTY are not supported.

**Note** If you call this method with the *Guid* parameter set to a GUID that already exists in the [IInkExtendedProperties](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties) collection, the new data will replace the existing extended property for that GUID instead of adding a second element.

## See also

[IInkExtendedProperties Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties)

[InkStrokes Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms703293(v=vs.85))