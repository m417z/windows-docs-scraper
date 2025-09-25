# IWbemClassObject::Get

## Description

The
**IWbemClassObject::Get** method retrieves the specified property value, if it exists. This method can also return
[system properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties).

## Parameters

### `wszName` [in]

Name of the desired property. It is treated as read-only.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pVal` [out]

When successful, this parameter is assigned the correct type and value for the qualifier, and the [VariantInit](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantinit) function is called on *pVal*. It is the responsibility of the caller to call [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) on *pVal* when the value is not needed. If there is an error, the value that *pVal* points to is not modified. If an uninitialized *pVal* value is passed to the method, then the caller must check the return value of the method, and call **VariantClear** only when the method succeeds.

### `pType` [out, optional]

Can be **NULL**. If it is not **NULL**, it receives the CIM type of the property, that is, one of the CIM-type constants, such as **CIM_SINT32**, **CIM_STRING**, and so on. For more information about these values, see [CIMTYPE_ENUMERATION](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-cimtype_enumeration). This indicates the CIM semantics of the property value packed into **VARIANT**.

### `plFlavor` [out, optional]

Can be **NULL**. If not **NULL**, the LONG value pointed to receives information about the origin of the property. For more information, see [Qualifier Flavors](https://learn.microsoft.com/windows/desktop/WmiSdk/qualifier-flavors) and [WBEM_FLAVOR_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_flavor_type).

#### WBEM_FLAVOR_ORIGIN_SYSTEM

The property is a standard system property.

#### WBEM_FLAVOR_ORIGIN_PROPAGATED

For classes only. The property was inherited from the parent class.

For instances only. The property is inherited from the parent class, but has not been modified at the instance level.

#### WBEM_FLAVOR_ORIGIN_LOCAL

For classes only. The property belongs to the derived child class.

For instances only. The property is modified at the instance level—that is, a value was supplied, or a qualifier was added or modified.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the value contained in an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the type of the property is an object path, date/time string, or other special type, then the returned values in the **VARIANT** do not contain enough information to identify the true type. The *pvtType* out parameter indicates this.

To obtain the string form of the Common Information Model (CIM) type for the property, the
[IWbemQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemqualifierset) pointer for the property must be obtained, and the **Cimtype** qualifier retrieved. That qualifier is the string form of the CIM type, such as **sint32** versus **CIM_SINT32**, which is a numeric constant.

**Note** When you create a new object using
[IWbemClassObject::SpawnInstance](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-spawninstance), it is important to note that some system properties are not set until the object is written to Windows Management Instrumentation (WMI). In all cases,
**IWbemClassObject::Get** succeeds in accessing the requested system property, but the returned **VARIANT** may contain **VT_NULL**.

#### Examples

For an extended discussion and example of making queries in C++ and WMI, see Making [WMI Queries In C++](https://www.codeproject.com/Articles/10539/Making-WMI-Queries-In-C) on CodeProject.

The following C++ example shows how to retrieve the CIM class name from an object by using the system property **__CLASS.** The code requires the following #include statements and references to compile.

```cpp
#include <iostream>
using namespace std;
#include <wbemidl.h>
#pragma comment(lib, "wbemuuid.lib")
```

```cpp
//Assumes that pObj is defined as a pointer
// to an IWbemClassObject object.

VARIANT v;
BSTR strClassProp = SysAllocString(L"__CLASS");
HRESULT hr;
hr = pObj->Get(strClassProp, 0, &v, 0, 0);
SysFreeString(strClassProp);

// check the HRESULT to see if the action succeeded.

if (SUCCEEDED(hr) && (V_VT(&v) == VT_BSTR))
{
    wprintf(L"The class name is %s\n.", V_BSTR(&v));
}
else
{
    wprintf(L"Error in getting specified object\n");
}
VariantClear(&v);

```

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::GetPropertyQualifierSet](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-getpropertyqualifierset)

[WMI Qualifiers](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-qualifiers)

[WMI System Classes](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-classes)

[WMI System Properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties)