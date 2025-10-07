# WMDM\_PROP\_VALUES\_ENUM structure

The **WMDM\_PROP\_VALUES\_ENUM** structure contains an enumerated set of valid values for a particular property in a particular property configuration.

## Members

**cEnumValues**

Count of enumerated values.

**pValues**

Pointer to an array of values. The size of the array is equal to the value of **cEnumValues**.

## Remarks

This structure is used in the **WMDM\_PROP\_DESC** structure to describe an enumerated set of valid values. An enumerated set of valid values is applicable when WMDM\_ENUM\_PROP\_VALID\_VALUES\_ENUM is selected from the **WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM** enumeration.

The caller is required to free the memory used by **pValues**. For an example of how to do this, see [**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IWMDMDevice3::GetFormatCapability**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability)

[**WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-enum-prop-valid-values-form)

[**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability)

[**WMDM\_PROP\_CONFIG**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-config)

[**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc)

[**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

