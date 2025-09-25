# IDiscFormat2Erase::EraseMedia

## Description

Erases the media in the active disc recorder.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
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
| **E_IMAPI_ERASE_MEDIA_IS_NOT_SUPPORTED** | The current media type is unsupported.<br><br>Value: 0xC0AA0909 |
| **E_IMAPI_ERASE_DRIVE_FAILED_SPINUP_COMMAND** | The drive returned an error for a START UNIT (spinup) command. Manual intervention may be required.<br><br>Value: 0x80AA0908 |
| **E_IMAPI_ERASE_TOOK_LONGER_THAN_ONE_HOUR** | The drive did not complete the erase in one hour. The drive may require a power cycle, media removal, or other manual intervention to resume proper operation.<br><br>**Note** Currently, this value will also be returned if an attempt to perform an erase on CD-RW or DVD-RW media via the [IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase) interface fails as a result of the media being bad.<br><br>Value: 0x80AA0906 |

## Remarks

Synchronously erases the media. Progress can be reported by calling into registered events of type [DDiscFormat2EraseEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2eraseevents).

Before calling this method, you must call the following methods:

* [IDiscFormat2Erase::put_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-put_recorder)
* [IDiscFormat2Erase::put_ClientName](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-put_clientname)

You should also consider calling the [IDiscFormat2Erase::put_FullErase](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-put_fullerase) method if its default value is not appropriate for your application.

This method is synchronous. To determine the progress of the erase operation, you must implement the [DDiscFormat2EraseEvents](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-ddiscformat2eraseevents) interface. For examples that show how to implement an event handler in a script, see [Monitoring Progress With Events](https://learn.microsoft.com/windows/desktop/imapi/monitoring-progress-with-events).

Currently, the E_IMAPI_ERASE_TOOK_LONGER_THAN_ONE_HOUR value is returned if an attempt to perform an erase on CD-RW or DVD-RW media via the [IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase) interface fails as a result of the media being bad or a drive failure.

## See also

[IDiscFormat2Erase](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscformat2erase)

[IDiscFormat2Erase::get_FullErase](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-get_fullerase)

[IDiscFormat2Erase::put_FullErase](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscformat2erase-put_fullerase)