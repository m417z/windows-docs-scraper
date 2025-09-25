# MI_PropertySet_ContainsElement function

## Description

Determines whether the property list contains the specified property name.

## Parameters

### `self` [in]

Property list to be checked.

### `name`

A null-terminated string that represents the name to check for in the property list.

### `flag` [out]

Returned Boolean value. **MI_TRUE** indicates that the specified property was found; otherwise **MI_FALSE** is returned.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.