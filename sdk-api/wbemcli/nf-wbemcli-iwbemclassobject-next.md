# IWbemClassObject::Next

## Description

The **IWbemClassObject::Next** method retrieves the
next property in an enumeration that started with
[IWbemClassObject::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginenumeration).
This should be called repeatedly to enumerate all the properties until
**WBEM_S_NO_MORE_DATA** returns. If the enumeration is to be terminated early, then
[IWbemClassObject::EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-endenumeration) should
be called.

The order of the properties returned during the enumeration is not defined.

## Parameters

### `lFlags` [in]

Reserved. This parameter must be 0.

### `strName` [out]

Receives a new **BSTR** that contains the property name. To prevent memory leaks
in the client process, the caller must call
[SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when the name is no
longer required. You can set this parameter to **NULL** if the name is not required.

### `pVal` [out]

This **VARIANT** is filled with the value of the property. The method calls
[VariantInit](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantinit) on this
**VARIANT**, so the caller should ensure that the **VARIANT**
is not active prior to the call. The caller must use
[VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) when the value is no
longer required.

You can set this parameter to **NULL** if the value is not required. If an error code
is returned, the **VARIANT** pointed to by *pVal* is left
unmodified.

### `pType` [out, optional]

This parameter can be **NULL**. If it is not **NULL**, it must
point to a **CIMTYPE** variable (a **LONG**) into which the
type of the property is placed. It is possible that the value of this property can be a
**VT_NULL** **VARIANT**, in which case it
is necessary to determine the actual type of the property.

### `plFlavor` [out, optional]

Can be **NULL**. If not **NULL**, the
**LONG** value pointed to receives information on the origin of the property as
follows. For more information, see [Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors) and [WBEM_FLAVOR_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_flavor_type).

#### WBEM_FLAVOR_ORIGIN_SYSTEM

The property is a standard system property.

####

For classes:

#### WBEM_FLAVOR_ORIGIN_PROPAGATED

The property was inherited from the parent class.

The property, while inherited from the parent class, has not been modified at the instance level.

#### WBEM_FLAVOR_ORIGIN_LOCAL

The property belongs to the derived-most class.

The property is modified at the instance level (that is, either a value was supplied or a qualifier was
added/modified).

For instances:

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The
following list lists the value contained within an **HRESULT**. For general
**HRESULT** values, see
[System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the underlying type of the property is an object path, date or time, or another special type, then the
returned type does not contain enough information. The caller must examine the
[CIMTYPE](https://learn.microsoft.com/windows/desktop/WmiSdk/cimtype-qualifier) for the specified property, and determine
if the property is an object reference, date or time, or another special type.

This method also returns
[system properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginenumeration)

[IWbemClassObject::EndEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-endenumeration)

[IWbemClassObject::Get](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-get)

[WMI System Properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties)