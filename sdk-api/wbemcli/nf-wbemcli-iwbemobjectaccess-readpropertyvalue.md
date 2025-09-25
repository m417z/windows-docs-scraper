# IWbemObjectAccess::ReadPropertyValue

## Description

The **ReadPropertyValue** method returns a specified number of bytes of a property associated with a property handle. Use this method to read the value of a property that contains a string or to read a property that contains a value that is not 32 (**DWORD**) or 64 (**QWORD**) bits long.

## Parameters

### `lHandle` [in]

Integer that contains the handle identifying this property.

### `lBufferSize` [in]

Integer that contains the buffer size.

### `plNumBytes` [out]

Pointer to an integer used to return the number of bytes read.

### `aData` [out]

Pointer to an array used to return the property data.

## Return value

This method returns **WBEM_S_NO_ERROR** if successful; otherwise, this method returns an **HRESULT** with one of the following values.

## Remarks

String data is returned as **null**-terminated **WCHAR** data.

## See also

[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess)