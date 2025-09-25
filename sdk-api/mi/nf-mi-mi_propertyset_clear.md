# MI_PropertySet_Clear function

## Description

Removes all names from the property list. Afterwards, the count is zero. This allows property lists to be reused (without having to be destructed and reconstructed).

## Parameters

### `self` [in, out]

Property list to clear.

## Return value

A value of the [MI_Result](https://learn.microsoft.com/windows/desktop/api/mi/ne-mi-mi_result) enumeration that specifies the function return code. This can be one of the following codes.