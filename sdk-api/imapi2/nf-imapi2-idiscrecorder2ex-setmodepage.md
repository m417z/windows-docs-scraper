# IDiscRecorder2Ex::SetModePage

## Description

Sets the mode page data for the device.

## Parameters

### `requestType` [in]

Type of mode page data to send. For possible values, see the [IMAPI_MODE_PAGE_REQUEST_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_mode_page_request_type) enumeration type.

### `data` [in]

Data buffer that contains the mode page data to send to the media. Do not include a header; this method generates and prepends a header to the mode page data.

For details on specifying the fields of the mode page data, see the MODE SELECT (10) command in the latest revision of the MMC specification at ftp://ftp.t10.org/t10/drafts/mmc5.

### `byteSize` [in]

Size, in bytes, of the data buffer.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_FAIL** | Unspecified failure.<br><br>Value: 0x80004005 |
| **E_IMAPI_RECORDER_GET_CONFIGURATION_NOT_SUPPORTED** | The drive does not support the GET CONFIGURATION command.<br><br>Value: 0xC0AA020C |
| **E_IMAPI_RECORDER_NO_SUCH_FEATURE** | The feature page requested is not supported by the device.<br><br>Value: 0xC0AA020A |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_IMAPI_RECORDER_FEATURE_IS_NOT_CURRENT** | The feature page requested is supported, but is not marked as current.<br><br>Value: 0xC0AA020B |
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

## See also

[IDiscRecorder2Ex](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2ex)

[IDiscRecorder2Ex::GetModePage](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getmodepage)

[IDiscRecorder2Ex::GetSupportedModePages](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-getsupportedmodepages)

[IMAPI_MODE_PAGE_REQUEST_TYPE](https://learn.microsoft.com/windows/desktop/api/imapi2/ne-imapi2-imapi_mode_page_request_type)

IMAPI_MODE_PAGE_TYPE