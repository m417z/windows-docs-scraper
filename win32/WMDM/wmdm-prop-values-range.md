# WMDM\_PROP\_VALUES\_RANGE structure

The **WMDM\_PROP\_VALUES\_RANGE** structure describes a range of valid values for a particular property in a particular property configuration.

## Members

**rangeMin**

Minimum value in the range.

**rangeMax**

Maximum value in the range.

**rangeStep**

The step size in which valid values increment from the minimum value to the maximum value. This permits specifying discrete permissible values in a range.

## Remarks

This structure is used in the [**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc) structure to describe a range of valid values. A range of valid values is applicable when WMDM\_ENUM\_PROP\_VALID\_VALUES\_ENUM is selected from the [**WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-enum-prop-valid-values-form) enumeration.

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

[**WMDM\_PROP\_VALUES\_ENUM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-enum)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

