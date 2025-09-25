# IWbemObjectAccess::GetPropertyHandle

## Description

The
**GetPropertyHandle** method returns a unique handle that identifies a property. You can use this handle to identify properties when using
[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess) methods to read or write property values.

## Parameters

### `wszPropertyName` [in]

Constant, null-terminated string of 16-bit Unicode characters that contains the property name.

### `pType` [out]

Pointer to a **CIMTYPE** used to return the CIM type of the property.

### `plHandle` [out]

Pointer to an integer used to return the property handle.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## Remarks

Handles can be retrieved for all data types other than CIM_OBJECT and CIM_ARRAY. Returned handles work across all instances of a class.

## See also

[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess)