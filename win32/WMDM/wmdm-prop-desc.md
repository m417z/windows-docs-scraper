# WMDM\_PROP\_DESC structure

The **WMDM\_PROP\_DESC** structure describes valid values of a property in a particular property configuration.

## Members

**pwszPropName**

Name of the property. The application must free this memory when it is done using it.

**ValidValuesForm**

An [**WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-enum-prop-valid-values-form) enumeration value describing the type of values, such as a range or list. The value of this enumeration determines which member variable is used.

**ValidValues**

Holds the valid values of the property in a particular property configuration. This member holds one of three items: the enumeration value WMDM\_ENUM\_PROP\_VALID\_VALUES\_ANY; the member **ValidValuesRange**; or the member **EnumeratedValidValues**. The value or member is indicated by **ValidValuesForm**.

**ValidValuesRange**

A [**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range) structure containing a range of valid values. This is present only when **ValidValuesForm** is set to WMDM\_ENUM\_PROP\_VALID\_VALUES\_RANGE. See Remarks.

**EnumeratedValidValues**

A [**WMDM\_PROP\_VALUES\_ENUM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-enum) structure containing an enumerated set of valid values. This is present only when **ValidValuesForm** is set to WMDM\_ENUM\_PROP\_VALID\_VALUES\_ENUM. See Remarks.

## Remarks

The **WMDM\_PROP\_DESC** structure contains a property description that consists of a property name and its valid values in a particular configuration.

The caller is required to free the memory used by **ValidValuesRange** or **EnumeratedValues**. For an example of how to do this, see [**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IWMDMDevice3::GetFormatCapability**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability)

[**WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-enum-prop-valid-values-form)

[**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability)

[**WMDM\_PROP\_CONFIG**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-config)

[**WMDM\_PROP\_VALUES\_ENUM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-enum)

[**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

