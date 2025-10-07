# WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM enumeration

The **WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM** enumeration type describes possible forms of valid values for a property.

## Constants

**WMDM\_ENUM\_PROP\_VALID\_VALUES\_ANY**

All values are valid.

**WMDM\_ENUM\_PROP\_VALID\_VALUES\_RANGE**

Valid values are expressed as a range. For detailed information, see the [**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range) structure.

**WMDM\_ENUM\_PROP\_VALID\_VALUES\_ENUM**

Valid values are an enumerated set. For detailed information, see the [**WMDM\_PROP\_VALUES\_ENUM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-enum) structure.

## Remarks

This enumeration is used in the [**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc) structure to specify the form of valid values for a property.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmdm/enumeration-types)

[**IWMDMDevice3::GetFormatCapability**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability)

[**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability)

[**WMDM\_PROP\_CONFIG**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-config)

[**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc)

[**WMDM\_PROP\_VALUES\_ENUM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-enum)

[**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range)

