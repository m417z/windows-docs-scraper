# IDiscFormat2TrackAtOnce::SetWriteSpeed

## Description

Sets the write speed of the disc recorder.

## Parameters

### `RequestedSectorsPerSecond` [in]

Requested write speed measured in disc sectors per second.

A value of 0xFFFFFFFF (-1) requests that the write occurs using the fastest supported speed for the media. This is the default.

### `RotationTypeIsPureCAV` [in]

Requested rotational-speed control type. Set to VARIANT_TRUE to request constant angular velocity (CAV) rotational-speed control type. Set to VARIANT_FALSE to use another rotational-speed control type that the recorder supports. The default is VARIANT_FALSE.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_IMAPI_RECORDER_REQUIRED** | The request requires a current disc recorder to be selected.<br><br>Value: 0xC0AA0003 |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_IMAPI_RECORDER_COMMAND_TIMEOUT** | The device failed to accept the command within the timeout period. This may be caused by the device having entered an inconsistent state, or the timeout value for the command may need to be increased.<br><br>Value: 0xC0AA020D |
| **E_IMAPI_RECORDER_INVALID_RESPONSE_FROM_DEVICE** | The device reported unexpected or invalid data for a command.<br><br>Value: 0xC0AA02FF |
| **E_IMAPI_RECORDER_MEDIA_UPSIDE_DOWN** | The media is inserted upside down.<br><br>Value: 0xC0AA0204 |
| **E_IMAPI_RECORDER_MEDIA_BECOMING_READY** | The drive reported that it is in the process of becoming ready. Please try the request again later.<br><br>Value: 0xC0AA0205 |
| **E_IMAPI_RECORDER_MEDIA_NO_MEDIA** | There is no media in the device.<br><br>Value: 0xC0AA0202 |
| **E_IMAPI_RECORDER_MEDIA_FORMAT_IN_PROGRESS** | The media is currently being formatted. Please wait for the format to complete before attempting to use the media.<br><br>Value: 0xC0AA0206 |
| **E_IMAPI_RECORDER_MEDIA_BUSY** | The drive reported that it is performing a long-running operation, such as finishing a write. The drive may be unusable for a long period of time.<br><br>Value: 0xC0AA0207 |
| **E_IMAPI_LOSS_OF_STREAMING** | The write failed because the drive did not receive data quickly enough to continue writing. Moving the source data to the local computer, reducing the write speed, or enabling a "buffer underrun free" setting may resolve this issue.<br><br>Value: 0xC0AA0300 |
| **E_IMAPI_RECORDER_MEDIA_INCOMPATIBLE** | The media is not compatible or of unknown physical format.<br><br>Value: 0xC0AA0203 |
| **E_IMAPI_RECORDER_DVD_STRUCTURE_NOT_PRESENT** | The DVD structure is not present. This may be caused by incompatible drive/medium used.<br><br>Value: 0xC0AA020E |
| **E_IMAPI_RECORDER_NO_SUCH_MODE_PAGE** | The device reported that the requested mode page (and type) is not present.<br><br>Value: 0xC0AA0201 |
| **E_IMAPI_RECORDER_INVALID_MODE_PARAMETERS** | The drive reported that the combination of parameters provided in the mode page for a MODE SELECT command were not supported.<br><br>Value: 0xC0AA0208 |
| **E_IMAPI_RECORDER_MEDIA_WRITE_PROTECTED** | The drive reported that the media is write protected.<br><br>Value: 0xC0AA0209 |
| **E_IMAPI_RECORDER_MEDIA_SPEED_MISMATCH** | The media's speed is incompatible with the device. This may be caused by using higher or lower speed media than the range of speeds supported by the device.<br><br>Value: 0xC0AA020F |
| **HRESULT_FROM_WIN32(ERROR_INVALID_HANDLE)** | The specified handle is invalid.<br><br>Value: 6 |
| **HRESULT_FROM_WIN32(ERROR_DEV_NOT_EXIST)** | The specified network resource or device is no longer available.<br><br>Value: 55 |
| **E_IMAPI_RECORDER_LOCKED** | The device associated with this recorder during the last operation has been exclusively locked, causing this operation to failed.<br><br>Value: 0xC0AA0210 |
| **E_IMAPI_UNEXPECTED_RESPONSE_FROM_DEVICE** | The write failed because the drive returned error information that could not be recovered from.<br><br>Value: 0xC0AA0301 |
| **S_IMAPI_ROTATIONADJUSTED** | The requested rotation type was not supported by the drive and the rotation type was adjusted.<br><br>Value: 0x00AA0005 |
| **S_IMAPI_SPEEDADJUSTED** | The requested write speed was not supported by the drive and the speed was adjusted.<br><br>Value: 0x00AA0004 |
| **S_IMAPI_BOTHADJUSTED** | The requested write speed and rotation type were not supported by the drive and they were both adjusted.<br><br>Value: 0x00AA0006 |

## Remarks

This method sets the write speed and type of rotational-speed control for a recorder. Requested values might differ from the values set in the recorder. To specify the recorder, call the [IDiscFormat2TrackAtOnce::put_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-put_recorder) method.

If the recorder supports the requested write speed, the disc device uses the requested value. If the recorder does not support the requested write speed, the recorder uses a write speed that it does support that is closest to the requested value. The [IDiscFormat2TrackAtOnce::get_CurrentWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_currentwritespeed) property contains the value used by the recorder.

To retrieve a list of the write speeds that the recorder and current media supports, call the [IDiscFormat2TrackAtOnce::get_SupportedWriteSpeeds](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_supportedwritespeeds) method.

If you request constant angular velocity (CAV) for rotational-speed control type and the recorder does not support CAV, the disc device uses another type of rotational-speed control type that it supports. The [IDiscFormat2TrackAtOnce::get_CurrentRotationTypeIsPureCAV](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_currentrotationtypeispurecav) property indicates the value used by the recorder.

To retrieve the requested values, call the [IDiscFormat2TrackAtOnce::get_RequestedWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_requestedwritespeed) and [IDiscFormat2TrackAtOnce::get_RequestedRotationTypeIsPureCAV](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_requestedrotationtypeispurecav) methods.

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::get_CurrentRotationTypeIsPureCAV](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_currentrotationtypeispurecav)

[IDiscFormat2TrackAtOnce::get_RequestedRotationTypeIsPureCAV](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_requestedrotationtypeispurecav)

[IDiscFormat2TrackAtOnce::get_SupportedWriteSpeedDescriptors](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_supportedwritespeeddescriptors)

[IDiscFormat2TrackAtOnce::get_SupportedWriteSpeeds](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-get_supportedwritespeeds)