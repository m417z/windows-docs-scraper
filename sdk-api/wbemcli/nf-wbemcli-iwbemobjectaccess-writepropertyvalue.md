# IWbemObjectAccess::WritePropertyValue

## Description

The **WritePropertyValue** method writes a specified number of bytes to a property identified by a property handle. Use this method to set string and all other non-**DWORD** or non-**QWORD** data.

## Parameters

### `lHandle` [in]

Integer that contains the handle that identifies this property.

### `lNumBytes` [in]

Integer that contains the number of bytes being written to the property. For nonstring property values, *lNumBytes* must be the correct data size of the property type specified. For string property values such as reference, string, and datetime, *lNumBytes* must be the length of the specified string in bytes, and the string itself must be of an even length in bytes and be followed with a null-termination character.

### `aData` [in]

Pointer to the constant byte type array that contains the data.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess)