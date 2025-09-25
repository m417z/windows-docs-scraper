# IAudioProcessingObject::IsInputFormatSupported

## Description

This method negotiates with the Windows Vista audio engine to establish a data format for the stream of audio data.

## Parameters

### `pOppositeFormat` [in, optional]

A pointer to an [IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype) interface. This parameter is used to indicate the output format of the data. The value of pOppositeFormat must be set to **NULL** to indicate that the output format can be any type.

### `pRequestedInputFormat` [in, optional]

A pointer to an [IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype) interface. This parameter is used to indicate the input format that is to be verified.

### `ppSupportedInputFormat` [out, optional]

This parameter indicates the supported format that is closest to the format to be verified.

## Return value

If the call completed successfully, the ppSupportedInputFormat parameter returns a pRequestedInputFormat pointer and the IsInputFormatSupported method returns a value of S_OK. Otherwise, this method returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **S_FALSE** | The format of the input/output format pair is not supported. ppSupportedInputFormat returns a suggested new format. |
| **APOERR_FORMAT_NOT_SUPPORTED** | The format to be verified is not supported. The value of ppSupportedInputFormat does not change. |
| **E_POINTER** | Invalid pointer that is passed to the method. The value of ppSupportedInputFormat does not change. |
| **Other HRESULT values** | These additional error conditions are tracked by the audio engine. |

## Remarks

There are differences in the implementation of the `IsInputFormatSupported` method by the different APOs. For example, with certain implementations, the output can only be of type float when the input format is of type integer.

To initiate format negotiation, the audio service first sets the output of the LFX sAPO to the default float32-based format. The audio service then calls the `IAudioProcessingObject::IsInputFormatSupported` method of the LFX sAPO, suggests the default format, and monitors the HRESULT response of this method. If the input of the LFX sAPO can support the suggested format, it returns S_OK, together with a reference to the supported format. If the input of the LFX sAPO cannot support the suggested format, it returns S_FALSE together with a reference to a format that is the closest match to the suggested one. If the LFX sAPO cannot support the suggested format and does not have a close match, it returns APOERR_FORMAT_NOT_SUPPORTED. The GFX sAPO works with the output format of the LFX sAPO. So the GFX sAPO is not involved in the format negotiation process.