# IWbemPropertyProvider::PutProperty

## Description

The **IWbemPropertyProvider::PutProperty** method is called by Windows Management to update a property value supported by a property provider.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

### `strLocale` [in]

String indicating the desired locale in cases where the returned property value can be localized. If the property cannot be localized, the implementation can ignore this value.

### `strClassMapping` [in]

Literal copy of the string value for the **ClassContext** qualifier for the class. This points to a valid **BSTR**, which is treated as read-only, or **NULL** if the qualifier does not exist.

### `strInstMapping` [in]

Literal copy of the string value for the **InstanceContext** qualifier for the instance. This must point to a valid **BSTR**, which is treated as read-only, or **NULL** if the qualifier does not exist.

### `strPropMapping` [in]

Literal copy of the value of the **PropertyContext** qualifier for the property. This must point to a valid **BSTR**, which is treated as read-only, or **NULL** if the qualifier does not exist.

### `pvValue` [in]

Pointer to an existing **VARIANT** that contains the value to be written.

## Return value

This method must return **WBEM_S_NO_ERROR** if the operation succeeds, or **WBEM_S_FALSE** if the operation fails.

## See also

[GetProperty](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbempropertyprovider-getproperty)