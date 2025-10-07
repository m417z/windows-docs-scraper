# WMDM\_PROP\_CONFIG structure

The **WMDM\_PROP\_CONFIG** structure describes a set of compatible property values across all the properties supported by the device for a particular format. This structure contains a number of property descriptions in an array of [**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc) structures.

## Members

**nPreference**

Device's level of preference for this configuration. The lowest value indicates the most preferred configuration.

**nPropDesc**

Number of property descriptions contained in this configuration. There is a single property description for each property supported for the specified format.

**pPropDesc**

Pointer to an array of [**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc) structures containing property descriptions. The size of the array is equal to the value of **nPropDesc**. The application must free this memory when finished with it.

## Remarks

The [**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability) structure returned by [**IWMDMDevice3::GetFormatCapability**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability) for a particular format consists of a number of property configurations. **WMDM\_PROP\_CONFIG** structures describe those configurations.

A property configuration describes values for all the properties supported for a given format. The values of different properties in a single configuration are compatible with each other. For example, for an audio file, a configuration will include valid values of sample rate and valid values of the bit rate such that all combinations of these sample and bit rates can be played on the device.

The caller is required to free the memory used by **pPropDesc**. For an example of how to do this, see [**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IWMDMDevice3::GetFormatCapability**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability)

[**WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-enum-prop-valid-values-form)

[**WMDM\_FORMAT\_CAPABILITY**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-format-capability)

[**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc)

[**WMDM\_PROP\_VALUES\_ENUM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-enum)

[**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

