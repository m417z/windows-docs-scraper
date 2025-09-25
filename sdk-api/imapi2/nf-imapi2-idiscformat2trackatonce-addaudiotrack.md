# IDiscFormat2TrackAtOnce::AddAudioTrack

## Description

Writes the data stream to the current media as a new track.

## Parameters

### `data` [in]

An **IStream** interface of the audio data to write as the next track on the media.

The data format contains 44.1KHz, 16-bit stereo, raw audio samples. This is the same format used by the audio samples in a Microsoft WAV audio file (without the header).

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_IMAPI_DF2TAO_MEDIA_IS_NOT_PREPARED** | The requested operation is only valid when media has been "prepared".<br><br>Value: 0xC0AA0502 |
| **E_IMAPI_DF2TAO_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0500 |
| **E_IMAPI_DF2TAO_TRACK_LIMIT_REACHED** | CD-R and CD-RW media support a maximum of 99 audio tracks.<br><br>Value: 0xC0AA0508 |
| **E_IMAPI_DF2TAO_STREAM_NOT_SUPPORTED** | The provided audio stream is not valid.<br><br>Value: 0xC0AA050D |
| **E_IMAPI_DF2TAO_NOT_ENOUGH_SPACE** | There is not enough space left on the media to add the provided audio track.<br><br>Value: 0xC0AA0509 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |
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
| **E_IMAPI_REQUEST_CANCELLED** | The request was canceled.<br><br>Value: 0xC0AA0002 |

## Remarks

Before calling this method, you must call the [IDiscFormat2TrackAtOnce::put_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-put_recorder) and [IDiscFormat2TrackAtOnce::PrepareMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-preparemedia) methods.

You should also consider calling the following methods if their default values are not appropriate for your application:

* [IDiscFormat2TrackAtOnce::put_BufferUnderrunFreeDisabled](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-put_bufferunderrunfreedisabled)
* [IDiscFormat2TrackAtOnce::put_ClientName](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-put_clientname)
* [IDiscFormat2TrackAtOnce::put_DoNotFinalizeMedia](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-put_donotfinalizemedia)

To determine the progress of the write operation, you must implement the [DDiscFormat2TrackAtOnceEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2trackatonceevents) interface. For examples that show how to implement an event handler in a script, see [Monitoring Progress With Events](https://learn.microsoft.com/windows/desktop/imapi/monitoring-progress-with-events).

The media can accommodate 99 tracks of audio data. Track numbering starts at 1. The last track is 99.

Silence, or data samples containing zeroes, will be added to the track-writing operation in the following ways:

* The minimum track size is 4 seconds and if needed, the track data will be enlarged to meet this requirement.
* Due to the nature of track-at-once recording, a two-second gap is added between successive audio tracks. This gap is normally hidden by PC-based players, but may be noticeable on some consumer electronics equipment.

## See also

[IDiscFormat2TrackAtOnce](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2trackatonce)

[IDiscFormat2TrackAtOnce::CancelAddTrack](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2trackatonce-canceladdtrack)