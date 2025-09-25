# IWMDMDevice3::GetFormatCapability

## Description

The **GetFormatCapability** method retrieves device support for files of a specified format. The capabilities are expressed as supported properties and their allowed values.

## Parameters

### `format` [in]

Value from the [WMDM_FORMATCODE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-formatcode) enumeration representing the queried format.

### `pFormatSupport` [out]

Pointer to the returned [WMDM_FORMAT_CAPABILITY](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-format-capability) structure containing supported properties and their allowed values. These values must be released by the application as described in [Getting Format Capabilities on Devices That Support IWMDMDevice3](https://learn.microsoft.com/windows/desktop/WMDM/getting-format-capabilities-on-devices-that-support-iwmdmdevice3).

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The client can obtain the list of supported formats by using the [IWMDMDevice3::GetProperty](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmdevice3-getproperty) method to query the **g_wszWMDMFormatsSupported** device property.

For a particular format, a client can call this function to obtain the supported properties and get information about configurations of supported properties (for example, combinations of bit rate and sample rate). This information is expressed as a format capability.

#### Examples

The following function is passed a device pointer and a format code, and retrieves the device's format capabilities for that format. The function uses a custom function to clear the retrieved values. This custom function is shown in [Getting Format Capabilities on Devices That Support IWMDMDevice3](https://learn.microsoft.com/windows/desktop/WMDM/getting-format-capabilities-on-devices-that-support-iwmdmdevice3).

```cpp

// Each format configuration is described by a WMDM_FORMAT_CAPABILITY enum, and
// has a WMDM_FORMAT_CAPABILITY structure describing the device capabilities for that format.
//        Each WMDM_FORMAT_CAPABILITY structure has a WMDM_PROP_CONFIG structure listing configurations.
//            Each WMDM_PROP_CONFIG has a WMDM_PROP_DESC describing a specific format configuration.
//                Each WMDM_PROP_DESC holds specific values as a range, a set, or a flag meaning all values are accepted.
HRESULT myGetFormatCaps(WMDM_FORMATCODE formatCode, IWMDMDevice3* pDevice)
{
    HRESULT hr = S_OK;

    // Get a list of supported configurations for the format.
    WMDM_FORMAT_CAPABILITY formatCapList;
    hr = pDevice->GetFormatCapability(formatCode, &formatCapList);
    HANDLE_HR(hr, "Got a WMDM_FORMATCODE structure in GetCaps","Couldn't get a WMDM_FORMATCODE structure in GetCaps");

    // Print out the format name.
    // TODO: Display a banner for device formats.
    PrintWMDM_FORMATCODE(formatCode); // Custom function to print out the format code.

    // Loop through the configurations and examine each one.
    for(UINT iConfig = 0; iConfig < formatCapList.nPropConfig; iConfig++)
    {
        WMDM_PROP_CONFIG formatConfig = formatCapList.pConfigs[iConfig];

        // Preference level for this configuration (lower number means more preferred).
        // TODO: Display a banner for the preference-level output.

        // Loop through all properties for this configuration and get supported
        // values for the property. Values can be a single value, a range,
        // or a list of enumerated values.
        for(UINT iDesc = 0; iDesc < formatConfig.nPropDesc; iDesc++)
        {
            WMDM_PROP_DESC propDesc = formatConfig.pPropDesc[iDesc];
            // TODO: Display the property name.

            // Three ways a value can be represented: any, a range, or a list.
            switch (propDesc.ValidValuesForm)
            {
                case WMDM_ENUM_PROP_VALID_VALUES_ANY:
                    // TODO: Display a message indicating that all values are valid.
                    break;
                case WMDM_ENUM_PROP_VALID_VALUES_RANGE:
                    {
                        // List these in the docs as the propvariants set.
                        WMDM_PROP_VALUES_RANGE rng = propDesc.ValidValues.ValidValuesRange;
                        // TODO: Display a banner for the values to follow
                        // TODO: Display the max value.
                        // TODO: Display the min value.
                        // TODO: Display the step value.
                    }
                    break;
                case WMDM_ENUM_PROP_VALID_VALUES_ENUM:
                    {
                        // TODO: Display a banner for the values to follow.
                        WMDM_PROP_VALUES_ENUM list = propDesc.ValidValues.EnumeratedValidValues;
                        PROPVARIANT pVal;
                        for(UINT iValue = 0; iValue < list.cEnumValues; iValue++)
                        {
                            pVal = list.pValues[iValue];
                            // TODO: Display the current value.
                            PropVariantClear(&pVal);
                            PropVariantInit(&pVal);
                        }
                    }

                    break;
                default:
                    HANDLE_HR(E_FAIL, "Undefined configuration type in GetCaps" << endl, "");
                    break;
            }
        }
    }
    // Now clear the memory used by WMDM_FORMAT_CAPABILITY.
    FreeFormatCapability(formatCapList);

e_Exit:
    return hr;
}

```

## See also

[Discovering Device Format Capabilities](https://learn.microsoft.com/windows/desktop/WMDM/discovering-device-format-capabilities)

[IWMDMDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmdevice3)