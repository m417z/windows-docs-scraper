# IEnumTfPropertyValue::Skip

## Description

Moves the current position forward in the enumeration sequence by the specified number of elements.

## Parameters

### `ulCount` [in]

Contains the number of elements to skip.

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method reached the end of the enumeration before the specified number of elements could be skipped. |

## See also

[IEnumTfPropertyValue interface](https://learn.microsoft.com/windows/win32/api/msctf/nn-msctf-ienumtfpropertyvalue), [TF_PROPERTYVAL structure](https://learn.microsoft.com/windows/win32/api/msctf/ns-msctf-tf_propertyval)