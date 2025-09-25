# IWbemQualifierSet::Next

## Description

The **IWbemQualifierSet::Next** method retrieves the next qualifier in an enumeration that started with
[IWbemQualifierSet::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-beginenumeration). This method is called repeatedly to enumerate all the qualifiers until **WBEM_S_NO_MORE_DATA** returns. To terminate the enumeration early, call
[IWbemQualifierSet::EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-endenumeration).

The order of the qualifiers returned during the enumeration is not defined.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pstrName` [out]

This parameter receives the name of the qualifier. A new **BSTR** is always allocated whenever **WBEM_S_NO_ERROR** returns.

If *pstrName* is **NULL**, it is ignored; otherwise, the caller must ensure that this parameter does not point to a valid **BSTR** on entry, or else there will be a memory leak. Also, the caller must remember to call **SysFreeString** on the returned string when it is no longer required.

### `pVal` [out]

This parameter receives the value for the qualifier. **VariantInit** is called on the **VARIANT** by this method. The caller must call **VariantClear** on this pointer when the value is no longer required. If an error code is returned, the **VARIANT** pointed to by *pVal* is left unmodified. This parameter is ignored if set to **NULL**.

### `plFlavor` [out]

If not **NULL**, the value pointed to is set to the qualifier flavor. For more information, see
[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors) and [WBEM_FLAVOR_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_flavor_type).

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**.

## See also

[IWbemQualifierSet::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-beginenumeration)

[IWbemQualifierSet::EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemqualifierset-endenumeration)

[Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors)