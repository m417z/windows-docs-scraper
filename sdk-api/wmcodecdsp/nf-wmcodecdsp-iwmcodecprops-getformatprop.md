# IWMCodecProps::GetFormatProp

## Description

Retrieves a format property for an output media type. Use this method to get information about enumerated audio formats.

## Parameters

### `pmt` [in]

Pointer to the output media type.

### `pszName` [in]

Wide-character, null-terminated string containing the property name. The properties listed in the following table are supported only through the IWMCodecProps interface.

| Property name constant | Meaning |
| --- | --- |
| **g_wszSpeechFormatCaps** | Retrieves the speech modes available for the format (used only by the Windows Media Audio 9 Voice codec). Value contains flags identical to the values used to specify the mode for [MFPKEY_WMAVOICE_ENC_MusicSpeechClassMode](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-wmavoice-enc-musicspeechclassmodeproperty). |

The properties in the following list are also supported. They are used with **IPropertyBag** for video.

* [MFPKEY_VBRENABLED](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-vbrenabledproperty)
* [MFPKEY_VBRQUALITY](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-vbrqualityproperty)

### `pType` [out]

Address of a variable that receives the data type of the property value.

### `pValue` [out]

Address of the byte buffer that receives the property value.

### `pdwSize` [in, out]

Pointer to the size of the value buffer, in bytes. If pValue is **NULL**, the method will set this value to the size required.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IWMCodecProps Interface](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-iwmcodecprops)

[MFPKEY_VBRENABLED](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-vbrenabledproperty)

[MFPKEY_VBRQUALITY](https://learn.microsoft.com/windows/desktop/medfound/mfpkey-vbrqualityproperty)