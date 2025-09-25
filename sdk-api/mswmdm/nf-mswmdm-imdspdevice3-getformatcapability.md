# IMDSPDevice3::GetFormatCapability

## Description

The **GetFormatCapability** method retrieves information from a device about the values or ranges of values supported by the device for each aspect of a particular object format.

## Parameters

### `format` [in]

[WMDM_FORMATCODE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-formatcode)

Enumerated value representing inquired format.

### `pFormatSupport` [out]

Returned [WMDM_FORMAT_CAPABILITY](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-format-capability) structure containing the values or ranges of values supported for each aspect of a particular object format.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method can be called for any of the supported formats. The list of supported formats are represented by **g_wszWMDMFormatsSupported** device property.

For a particular format, this method should return all configurations of supported properties (for example, combinations of bit rate and sample rate). This information is expressed as a format capability. For detailed information, see [WMDM_FORMAT_CAPABILITY](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-format-capability).

## See also

[IMDSPDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice3)

[IMDSPDevice3::GetProperty](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice3-getproperty)

[WMDM_ENUM_PROP_VALID_VALUES_FORM](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-enum-prop-valid-values-form)

[WMDM_FORMAT_CAPABILITY](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-format-capability)

[WMDM_PROP_CONFIG](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-prop-config)

[WMDM_PROP_DESC](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-prop-desc)

[WMDM_PROP_VALUES_ENUM](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-prop-values-enum)

[WMDM_PROP_VALUES_RANGE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-prop-values-range)