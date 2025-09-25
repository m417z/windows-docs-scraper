# IWbemObjectAccess::GetPropertyInfoByHandle

## Description

The
**GetPropertyInfoByHandle** method returns the name and data type of the property that is associated with a property handle.

## Parameters

### `lHandle` [in]

Integer that contains the handle identifying the property.

### `pstrName` [out]

Pointer to a string used to return the name of the specified property.

### `pType` [out]

Pointer to a **CIMTYPE** used to return the type of the property.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemObjectAccess](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemobjectaccess)