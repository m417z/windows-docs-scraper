# IWbemClassObject::GetNames

## Description

The **IWbemClassObject::GetNames** method
retrieves the names of the properties in the object. Furthermore, depending on user-supplied
selection criteria, it can retrieve all or a subset of the properties. These properties can then be accessed by
using [IWbemClassObject::Get](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-get) for each name. This
method can also return [system properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties).

## Parameters

### `wszQualifierName` [in]

A parameter that can be **NULL**. If not **NULL**, it must point to a valid **LPCWSTR** specifying a qualifier name which operates as part of a filter. This is handled as read-only. For more information, see Remarks.

### `lFlags` [in]

For more information, see Remarks.

### `pQualifierVal` [in]

A parameter that can be **NULL**. If not **NULL**, it must point to a valid **VARIANT** structure initialized to a filter value. This **VARIANT** is handled as read-only by the method. Thus, the caller must call **VariantClear** on it, if required. For more information, see Remarks.

### `pNames` [out]

A parameter that cannot be **NULL**, but on entry this parameter must point to **NULL**. A new **SAFEARRAY** structure is always allocated, and the pointer is set to point to it. The returned array can have 0 elements, but is always allocated when **WBEM_S_NO_ERROR** returns. On error, a new **SAFEARRAY** structure is not returned.

## Return value

This method returns an **HRESULT** indicating the status of the method call. The following list lists the value contained within an **HRESULT**. For general **HRESULT** values, see [System Error Codes](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

The names returned are controlled by a combination of flags and parameters. For example, all names of all
properties can be specified, or only the key properties can be specified, and so on. The primary filter is
specified in the *lFlags* parameter; the other parameters vary depending upon it.

The flag values are bit fields, and can be combined. One flag from each of the following groups can be combined
with a flag from each of the other groups. Flag values within a group are mutually exclusive.

| Group 1 flags | Description |
| --- | --- |
| **WBEM_FLAG_ALWAYS** | Return all property names. The *strQualifierName* and *pQualifierVal* parameters are not used. |
| **WBEM_FLAG_ONLY_IF_TRUE** | Return only properties that have a qualifier of the name specified by the parameter *strQualifierName*. If this flag is used, you must specify *strQualifierName*. |
| **WBEM_FLAG_ONLY_IF_FALSE** | Return only properties that do not have a qualifier of the name specified by the parameter *strQualifierName*. If this flag is used, you must specify *strQualifierName*. |
| **WBEM_FLAG_ONLY_IF_IDENTICAL** | Return only properties that have a qualifier of the name specified by the parameter *QualifierName*, and also have a value identical to the value specified by the **VARIANT** structure pointed to by *pQualifierVal*. If this flag is used, you must specify both *QualifierName* and *pQualifierVal*. |

| Group 2 flags | Description |
| --- | --- |
| **WBEM_FLAG_KEYS_ONLY** | Return only the names of the property or properties that define the keys. |
| **WBEM_FLAG_REFS_ONLY** | Return only property names that are object references. |

| Group 3 flags | Description |
| --- | --- |
| **WBEM_FLAG_LOCAL_ONLY** | Return only property names that belong to the derived-most class. Exclude properties from the parent class or parent classes. |
| **WBEM_FLAG_PROPAGATED_ONLY** | Return only property names that belong to the parent class or parent classes. |
| **WBEM_FLAG_SYSTEM_ONLY** | Return only [system properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties). |
| **WBEM_FLAG_NONSYSTEM_ONLY** | Return only property names that are not system properties. |

It is not an error for an empty list to be returned in cases where no properties match the specified
filters.

For more information about using **SAFEARRAY** structures of
**BSTR** values, see
[Retrieving Part of a WMI Instance](https://learn.microsoft.com/windows/desktop/WmiSdk/retrieving-part-of-an-instance).

## See also

[IWbemClassObject](https://learn.microsoft.com/windows/desktop/api/wbemcli/nn-wbemcli-iwbemclassobject)

[IWbemClassObject::BeginEnumeration](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-beginenumeration)

[IWbemClassObject::Get](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemclassobject-get)

[WBEM_CONDITION_FLAG_TYPE](https://learn.microsoft.com/windows/win32/api/wbemcli/ne-wbemcli-wbem_condition_flag_type)

[WMI System Properties](https://learn.microsoft.com/windows/desktop/WmiSdk/wmi-system-properties)