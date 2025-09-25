# IWMCodecProps::GetCodecProp

## Description

Retrieves a codec property specific to an output format.

## Parameters

### `dwFormat` [in]

The output format to which the property applies. Set this value to the FOURCC value of the desired video format.

### `pszName` [in]

Wide-character, null-terminated string containing the property name. The properties listed in the following table are supported only through the IWMCodecProps interface.

| Property name constant | Meaning |
| --- | --- |
| **g_wszWMCPCodecName** | Retrieves the name of the codec that is associated with the format (or FOURCC). This is an alternative to the [IWMCodecStrings](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecstrings) interface. |
| **g_wszWMCPSupportedVBRModes** | Retrieves the encoding modes supported by the codec. The value returned contains one or more of the following flags: <br><br>* WM_CODEC_ONEPASS_CBR<br>* WM_CODEC_ONEPASS_VBR<br>* WM_CODEC_TWOPASS_CBR<br>* WM_CODEC_TWOPASS_VBR_UNCONSTRAINED<br>* WM_CODEC_TWOPASS_VBR_PEAKCONSTRAINED |

### `pType` [out]

Address of a variable that receives the data type of the property value.

### `pValue` [out]

Address of the byte buffer that receives the property value.

### `pdwSize` [in, out]

Pointer to the size of the value buffer, in bytes. If pValue is **NULL**, the method will set this value to the size required.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IWMCodecProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecprops)