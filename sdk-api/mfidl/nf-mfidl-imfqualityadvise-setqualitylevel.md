# IMFQualityAdvise::SetQualityLevel

## Description

Sets the quality level. The quality level determines how the component consumes or produces samples.

## Parameters

### `eQualityLevel` [in]

Requested quality level, specified as a member of the [MF_QUALITY_LEVEL](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mf_quality_level) enumeration.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NO_MORE_QUALITY_LEVELS** | The component does not support the specified quality level or any levels below it. |

## See also

[IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise)