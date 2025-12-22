# IWbemClassObject::Put

## Description

The
**IWbemClassObject::Put** method sets a named property to a new value. This method always overwrites the current value with a new one. When
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject) points to a CIM class definition,
**Put** creates or updates the property value. When
**IWbemClassObject** points to a CIM instance,
**Put** updates a property value only. **Put** cannot create a property value.

A user cannot create properties with names that begin or end with an underscore (_). This is reserved for system classes and properties.

## Parameters

### `wszName` [in]

A parameter that must point to a valid property name. This parameter cannot be **NULL**.

### `lFlags` [in]

Reserved. This parameter must be 0 (zero).

### `pVal` [in]

A parameter that must point to a valid **VARIANT**, which becomes the new property value. If *pVal* is **NULL** or points to a **VARIANT** of type **VT_NULL**, the property is set to **NULL**, that is, no value.

### `Type` [in]

A type of **VARIANT** pointed to by *pVal*.

The **NULL** value for a property designated by a **VARIANT** of type **VT_NULL** is distinguished from a property of type **VT_I4** with a 0 (zero) value.

When creating new properties, if *pVal* is **NULL** or points to a **VT_NULL**, the type of the property is determined from the *vtType* parameter.

If *pVal* is to contain an embedded
[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject), the caller must call **IWbemClassObject::QueryInterface** for **IID_IUnknown** and place the resulting pointer in the **VARIANT** using a type of **VT_UNKNOWN**. The original embedded object is copied during the
**Put** operation, and so cannot be modified by the operation.

The pointer is treated as read-only. The caller must call [VariantClear](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-variantclear) after this call is complete.

Use this parameter only when creating new properties in a CIM class definition and *pVal* is **NULL** or points to a **VARIANT** of type **VT_NULL**. In such a case, the *vtType* parameter specifies the CIM type of the property. In every other case, *vtType* must be 0 (zero). Also, *vtType* must be 0 (zero) when the underlying object is an instance (even if *pVal* is **NULL**), because the type of the property is fixed and cannot be changed. In other words, use *vtType* if, and only if, *pVal* is **NULL** or points to a **VT_NULL****VARIANT**, and the underlying object is a CIM class.

When using
**IWbemClassObject::Put** to assign empty array values to a property, you do not need to specify the exact VT type; you can assign a value to *pVal* that is a **VARIANT** with a variant type of **VT_ARRAY**|**VT_VARIANT**.

## Return value

This method returns an **HRESULT** that indicates the status of the method call. The following list lists the values contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

If the property set by the
**IWbemClassObject::Put** method exists in the parent class, the default value of the property is changed unless the property type does not match the parent class type. If the property does not exist and it is not a type mismatch, the property is created.

When executing this method on an instance, an overwrite always occurs, because the property always exists.

When creating a new class and the underlying type of the property is an object reference, date/time string, or other special type, you might need to modify the CIM type parameter for the property to indicate the special new class. The
[CIMType](https://learn.microsoft.com/windows/desktop/WmiSdk/swbemproperty-cimtype) qualifier on instance properties is read-only and inherited from the class object.

If the variant type specified in *pVal* does not match the CIM type of the property, WMI attempts to change the variant to the appropriate variant type, using the normal variant coercion rules. If the variant cannot be coerced, **WBEM_E_TYPE_MISMATCH** is returned. The following list lists exceptions to the normal variant coercion rules when the property is type **uint32**.

| Pass in variant type | Result |
| --- | --- |
| **VT_I4** | **S_OK** |
| **VT_I2** | **WBEM_TYPE_MISMATCH** |
| **VT_R8** | **S_OK**<br><br>However, passing in a **VT_ARRAY**\|**VT_R8** to a property of type **uint32**[] will fail. |

The
[__CLASS](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties) system property is only writable during class creation, when it may not be left blank. All other system properties are read-only.

#### Examples

The following code example shows how to set the class name for a new CIM class.

```cpp
// pObj is an empty object from IWbemServices::GetObject
// Set up the property value.
VARIANT v;
VariantInit(&v);
V_VT(&v) = VT_BSTR;
V_BSTR(&v) = SysAllocString(L"MyClass");

// Write it.
LPCWSTR strClassProp = L"__CLASS";
pObj->Put(strClassProp, 0, &v, 0);

// Clean up.
VariantClear(&v);
```

The following code example shows how to set the value of the SomeUint64 property. Be aware that the **BSTR** value must be in decimal format and not hexadecimal.

```cpp
// pObj is an instance containing a uint64 property
// Set up the property value.
VARIANT v;
VariantInit(&v);
V_VT(&v) = VT_BSTR;
V_BSTR(&v) = SysAllocString(L"1033"); // - decimal format, not hex

// Write it.
LPCWSTR strClassProp = L"SomeUint64";
pObj->Put(strClassProp, 0, &v, CIM_UINT64);

// Clean up.
VariantClear(&v);
```

## See also

[IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q))

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[WMI Qualifiers](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-qualifiers)

[WMI System Classes](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-classes)

[WMI System Properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties)