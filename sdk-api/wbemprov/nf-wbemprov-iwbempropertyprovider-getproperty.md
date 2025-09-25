# IWbemPropertyProvider::GetProperty

## Description

The
**IWbemPropertyProvider::GetProperty** method is called by Windows Management to retrieve an individual property value.

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

### `pvValue` [out]

Pointer to an uninitialized **VARIANT** that receives the value for the property. The implementation must call **VariantInit** and return the value. If an error occurs, the implementation is expected to ignore the pointer.

## Return value

This method must return **WBEM_S_NO_ERROR** if the call succeeds. If the call fails, the method must return **WBEM_S_FALSE**.

## See also

[Constructing Property Providers](https://learn.microsoft.com/windows/desktop/api/wbemprov/nf-wbemprov-iwbempropertyprovider-putproperty)

[IWbemPropertyProvider](https://learn.microsoft.com/windows/desktop/api/wbemprov/nn-wbemprov-iwbempropertyprovider)

**PutProperty**