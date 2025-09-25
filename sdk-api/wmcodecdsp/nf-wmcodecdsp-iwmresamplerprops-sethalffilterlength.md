# IWMResamplerProps::SetHalfFilterLength

## Description

Specifies the quality of the output.

## Parameters

### `lhalfFilterLen` [in]

Specifies the quality of the output. The valid range is 1 to 60, inclusive.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

This method is equivalent to setting the [MFPKEY_WMRESAMP_FILTERQUALITY](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmresamp-filterquality) property.

## See also

[IWMResamplerProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmresamplerprops)