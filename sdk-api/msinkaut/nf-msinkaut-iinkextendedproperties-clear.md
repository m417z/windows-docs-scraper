# IInkExtendedProperties::Clear

## Description

Clears all of the [IInkExtendedProperty](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperty) objects from the [IInkExtendedProperties](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties) collection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INK_EXCEPTION** | An exception occurred inside the method. |
| **E_FAIL** | An unspecified error occurred. |

## Remarks

To clear only one extended property at a time, call the [Remove](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkextendedproperties-remove) method of the [IInkExtendedProperties](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties) collection.

## See also

[IInkExtendedProperties Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkextendedproperties)

[Remove Method [IInkExtendedProperties Interface]](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkextendedproperties-remove)