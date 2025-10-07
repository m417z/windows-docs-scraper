# WMDM\_FORMAT\_CAPABILITY structure

The **WMDM\_FORMAT\_CAPABILITY** structure describes the capabilities of a device for a particular format. This structure contains a set of property configurations in an array of **WMDM\_PROP\_CONFIG** structures. Each property configuration represents a set of compatible property values across all the properties supported for a given format. The application can get this structure by calling the **IWMDMDevice3::GetFormatCapability** method and passing in the format code. For a list of format codes, see [**WMDM\_FORMATCODE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-formatcode).

## Members

**nPropConfig**

Number of property configurations in the **pConfigs** array.

**pConfigs**

Pointer to an array of [**WMDM\_PROP\_CONFIG**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-config) structures. The size of array is equal to the value of **nPropConfig**.

## Remarks

The **WMDM\_FORMAT\_CAPABILITY** structure provides a flexible mechanism to express the capabilities of the device for a particular format.

If the content is meant to be rendered by the device (for example, an audio file to be played by the device), the properties of the content must match one of the property configurations returned by [**IWMDMDevice3::GetFormatCapability**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability) in the **WMDM\_FORMAT\_CAPABILITY** structure. For example, for an audio file, the bit rate and sample rate must satisfy one of the property configurations returned.

The caller is responsible for freeing the memory allocated for this structure. The following function demonstrates how to clear a **WMDM\_FORMAT\_CAPABILITY** structure.

```C++
void FreeFormatCapability(WMDM_FORMAT_CAPABILITY formatCap)
{
    // Loop through all configurations.
    for (UINT i=0; i < formatCap.nPropConfig; i++)
    {
        // Loop through all descriptions of a configuration and delete
        // the values particular to that description type.
        for (UINT j=0; j < formatCap.pConfigs[i].nPropDesc; j++)
        {
            switch (formatCap.pConfigs[i].pPropDesc[j].ValidValuesForm)
            {
                case WMDM_ENUM_PROP_VALID_VALUES_ENUM:
                    for (UINT k=0; k < formatCap.pConfigs[i].pPropDesc[j].ValidValues.EnumeratedValidValues.cEnumValues; k++)
                    {
                        PropVariantClear (&(formatCap.pConfigs[i].pPropDesc[j].ValidValues.EnumeratedValidValues.pValues[k]));
                    }
                    CoTaskMemFree(formatCap.pConfigs[i].pPropDesc[j].ValidValues.EnumeratedValidValues.pValues);
                    break;
                case WMDM_ENUM_PROP_VALID_VALUES_RANGE:
                    PropVariantClear (&(formatCap.pConfigs[i].pPropDesc[j].ValidValues.ValidValuesRange.rangeMin));
                    PropVariantClear (&(formatCap.pConfigs[i].pPropDesc[j].ValidValues.ValidValuesRange.rangeMax));
                    PropVariantClear (&(formatCap.pConfigs[i].pPropDesc[j].ValidValues.ValidValuesRange.rangeStep));
                    break;
                case WMDM_ENUM_PROP_VALID_VALUES_ANY:
                    // No dynamically allocated memory for this value.
                default:
                    break;
            }

            // Free the memory for the description name.
            CoTaskMemFree(formatCap.pConfigs[i].pPropDesc[j].pwszPropName);
        }
        // Free the memory holding the array of description items for this configuration.
        CoTaskMemFree(formatCap.pConfigs[i].pPropDesc);
    }

    // Free the memory pointing to the array of configurations.
    CoTaskMemFree(formatCap.pConfigs);
    formatCap.nPropConfig = 0;
}
```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IWMDMDevice3::GetFormatCapability**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getformatcapability)

[**WMDM\_ENUM\_PROP\_VALID\_VALUES\_FORM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-enum-prop-valid-values-form)

[**WMDM\_PROP\_CONFIG**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-config)

[**WMDM\_PROP\_DESC**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-desc)

[**WMDM\_PROP\_VALUES\_ENUM**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-enum)

[**WMDM\_PROP\_VALUES\_RANGE**](https://learn.microsoft.com/windows/win32/wmdm/wmdm-prop-values-range)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

