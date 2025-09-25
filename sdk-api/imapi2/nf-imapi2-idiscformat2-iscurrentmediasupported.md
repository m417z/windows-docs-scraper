# IDiscFormat2::IsCurrentMediaSupported

## Description

Determines if the current media in a supported recorder supports the given format.

## Parameters

### `recorder` [in]

An [IDiscRecorder2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2) interface of the recorder to test.

### `value` [out]

Is VARIANT_TRUE if the media in the recorder supports the given format; otherwise, VARIANT_FALSE.

**Note** VARIANT_TRUE also implies that the result from [IsDiscRecorderSupported](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2-isrecordersupported) is VARIANT_TRUE.

## Return value

S_OK or S_FALSE are returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_RECORDER_MEDIA_NO_MEDIA** | There is no media in the device.<br><br>(HRESULT)0xC0AA0202 |

**Note** Currently, Windows Vista will return **S_OK** and **VARIANT_FALSE** when media is not present in the device, while  **E_IMAPI_RECORDER_MEDIA_NO_MEDIA** and **VARIANT_FALSE** are returned in Windows 7.

## See also

[IDiscFormat2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2)

[IDiscFormat2::IsDiscRecorderSupported](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2-isrecordersupported)