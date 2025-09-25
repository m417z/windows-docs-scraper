# IMFOutputSchema::GetConfigurationData

## Description

Returns configuration data for the output protection system. The configuration data is used to enable or disable the protection system, and to set the protection levels.

## Parameters

### `pdwVal` [out]

Receives the configuration data. The meaning of this data depends on the output protection system.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IMFOutputSchema](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfoutputschema)