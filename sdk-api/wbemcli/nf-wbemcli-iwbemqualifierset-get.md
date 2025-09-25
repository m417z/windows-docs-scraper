# IWbemQualifierSet::Get

## Description

The **IWbemQualifierSet::Get** method gets the specified named qualifier, if found.

## Parameters

### `wszName` [in]

Name of the qualifier for which the value is being requested. The pointer is treated as read-only.

### `lFlags` [in]

Reserved. This parameter must be 0.

### `pVal` [out]

When successful, **VARIANT** is assigned to the correct type and value for the qualifier. **VariantInit** is called on this **VARIANT**.

It is the responsibility of the caller to call **VariantClear** on the pointer when the value is no longer required. If there is an error code, the **VARIANT** pointed to by *pVal* is not modified.

If this parameter is **NULL**, the parameter is ignored.

### `plFlavor` [out]

Can be **NULL**. If not **NULL**, this must point to a **LONG** that receives the qualifier flavor bits for the requested qualifier. For more information, see
[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors) and [WBEM_FLAVOR_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_flavor_type).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)