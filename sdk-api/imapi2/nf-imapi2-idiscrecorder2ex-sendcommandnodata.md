# IDiscRecorder2Ex::SendCommandNoData

## Description

Sends a MMC command to the recording device. Use this function when no data buffer is sent to nor received from the device.

## Parameters

### `Cdb` [in]

Command packet to send to the device.

### `CdbSize` [in]

Size, in bytes, of the command packet to send. Must be between 6 and 16 bytes.

### `SenseBuffer` [out]

Sense data returned by the recording device.

### `Timeout` [in]

Time limit, in seconds, allowed for the send command to receive a result.

## Return value

S_OK or one of the following values can be returned on success, but other success codes may be returned as a result of implementation:

| Return code | Description |
| --- | --- |
| **S_IMAPI_COMMAND_HAS_SENSE_DATA** | The device fails the command, but returns sense data.<br><br>Value: 0x00AA0200 |

 The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

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

## Remarks

For details of the contents of the command packet and sense data, see the latest revision of the MMC specification at ftp://ftp.t10.org/t10/drafts/mmc5.

Client-defined commands (CDBs) used with this method must be between 6 and 16 bytes in length. In addition, the size of each command must match the size defined by the operation code as defined in the following table.

| CDB operation code range | CDB group | Required CDB size |
| --- | --- | --- |
| 0x00 — 0x1F | 0 | 6 bytes |
| 0x20 — 0x3F | 1 | 10 bytes |
| 0x40 — 0x5F | 2 | 10 bytes |
| 0x60 — 0x7F | 3 | Will enforce standard-specified size requirements for this opcode range in the future. |
| 0x80 — 0x9F | 4 | 16 bytes |
| 0xA0 — 0xBF | 5 | 12 bytes |
| 0xC0 — 0xDF | 6 | Vendor Unique - Any size allowed |
| 0xE0 — 0xFF | 7 | Vendor Unique - Any size allowed |

Some very early devices used vendor-unique opcodes and therefore some opcodes cannot be validated in this manner. The following opcodes are still valid and only verify that the size is between 6 and 16 bytes:

0x02, 0x05, 0x06, 0x09, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x13, 0x14, 0x19, 0x20, 0x21, 0x22, 0x23, 0x24, 0x26, 0x27, 0x29, 0x2C, 0x2D

## See also

[IDiscRecorder2Ex](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscrecorder2ex)

[IDiscRecorder2Ex::SendCommandGetDataFromDevice](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-sendcommandgetdatafromdevice)

[IDiscRecorder2Ex::SendCommandSendDataToDevice](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2ex-sendcommandsenddatatodevice)