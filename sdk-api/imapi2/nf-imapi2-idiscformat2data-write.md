# IDiscFormat2Data::Write

## Description

Writes the data stream to the device.

**Note** For write success, the size of the passed-in stream must be a multiple of the sector size, 2048. This includes operations that utilize streams associated with .iso images not created by IMAPI.

## Parameters

### `data` [in]

An **IStream** interface of the data stream to write.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
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
| **E_IMAPI_RECORDER_REQUIRED** | The request requires a current disc recorder to be selected.<br><br>Value: 0xC0AA0003 |
| **S_IMAPI_ROTATIONADJUSTED** | The requested rotation type was not supported by the drive and the rotation type was adjusted.<br><br>Value: 0x00AA0005 |
| **S_IMAPI_SPEEDADJUSTED** | The requested write speed was not supported by the drive and the speed was adjusted.<br><br>Value: 0x00AA0004 |
| **S_IMAPI_BOTHADJUSTED** | The requested write speed and rotation type were not supported by the drive and they were both adjusted.<br><br>Value: 0x00AA0006 |
| **E_IMAPI_DF2DATA_RECORDER_NOT_SUPPORTED** | This device does not support the operations required by this disc format.<br><br>Value: 0xC0AA0407 |
| **E_IMAPI_REQUEST_CANCELLED** | The request was canceled.<br><br>Value: 0xC0AA0002 |
| **E_IMAPI_DF2DATA_WRITE_IN_PROGRESS** | There is currently a write operation in progress.<br><br>Value: 0xC0AA0400 |
| **E_IMAPI_DF2DATA_STREAM_NOT_SUPPORTED** | The size of the provided **IStream** object is invalid. The size must be a multiple of the sector size, 2048.<br><br>Value: 0xC0AA0403 |
| **E_IMAPI_DF2DATA_MEDIA_IS_NOT_SUPPORTED** | The current media type is unsupported.<br><br>Value: (HRESULT)0xC0AA0406 |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_NOTIMPL** | Not implemented.<br><br>Value: 0x80004001 |

## Remarks

Before calling this method, you must call the following methods:

* [IDiscFormat2Data::put_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_recorder)
* [IDiscFormat2Data::put_ClientName](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_clientname)

You should also consider calling the following methods if their default values are not appropriate for your application:

* [IDiscFormat2Data::put_BufferUnderrunFreeDisabled](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_bufferunderrunfreedisabled)
* [IDiscFormat2Data::put_DisableConsumerDvdCompatibilityMode](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_disableconsumerdvdcompatibilitymode)
* [IDiscFormat2Data::put_ForceMediaToBeClosed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_forcemediatobeclosed)
* [IDiscFormat2Data::put_ForceOverwrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_forceoverwrite)
* [IDiscFormat2Data::put_PostgapAlreadyInImage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-put_postgapalreadyinimage)
* [IDiscFormat2Data::SetWriteSpeed](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-setwritespeed)

This method is synchronous, which means that control is not returned until the provided **IStream** is recorded to the media. To determine the progress of the write operation, you must implement the [DDiscFormat2DataEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2dataevents) interface. For examples that show how to implement an event handler in a script, see [Monitoring Progress With Events](https://learn.microsoft.com/windows/desktop/imapi/monitoring-progress-with-events).

On sequentially recorded discs, the provided [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream) is recorded as a new session. On rewritable discs, the provided **IStream** is always recorded starting from sector 0, but the object providing the **IStream** interface can also provide the [IBlockRangeList](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iblockrangelist) interface listing the sectors that need to be recorded. The **IBlockRangeList** interface is used to avoid rewriting of sectors that have not changed in multisession scenarios. If the object providing **IStream** does not provide **IBlockRangeList**, it is assumed that the entire **IStream** needs to be recorded.

## See also

[DDiscFormat2DataEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2dataevents)

[IDiscFormat2Data](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2data)

[IDiscFormat2Data::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2data-cancelwrite)