# IAudioProcessingObject::IsOutputFormatSupported

## Description

The `IsOutputFormatSupported` method is used to verify that a specific output format is supported.

## Parameters

### `pOppositeFormat` [in, optional]

A pointer to an IAudioMediaType interface. This parameter indicates the output format. This parameter must be set to **NULL** to indicate that the output format can be any type.

### `pRequestedOutputFormat` [in, optional]

A pointer to an **IAudioMediaType** interface. This parameter indicates the output format that is to be verified.

### `ppSupportedOutputFormat` [out, optional]

This parameter indicates the supported output format that is closest to the format to be verified.

## Return value

If the call completes successfully, the ppSupportedOutputFormat parameter returns a pRequestedOutputFormat pointer and the IsOutputFormatSupported method returns a value of S_OK. Otherwise, this method returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **S_FALSE** | The format of Input/output format pair is not supported. The ppSupportedOutPutFormat parameter returns a suggested new format. |
| **APOERR_FORMAT_NOT_SUPPORTED** | The format is not supported. The value of ppSupportedOutputFormat does not change. |
| **E_POINTER** | An invalid pointer was passed to the function. The value of ppSupportedOutputFormat does not change. |
| **Other HRESULT values** | These additional error conditions are tracked by the audio engine. |

## Remarks

There are differences in the implementation of the `IsOutputFormatSupported` method by the different APOs. For example, with certain implementations, the output can only be of type float when the input format is of type integer.

## See also

[IAudioMediaType](https://learn.microsoft.com/windows/desktop/api/audiomediatype/nn-audiomediatype-iaudiomediatype)

[IAudioProcessingObject](https://learn.microsoft.com/windows/desktop/api/audioenginebaseapo/nn-audioenginebaseapo-iaudioprocessingobject)