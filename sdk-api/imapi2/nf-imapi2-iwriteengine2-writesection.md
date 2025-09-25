# IWriteEngine2::WriteSection

## Description

Writes a data stream to the current recorder.

## Parameters

### `data` [in]

An **IStream** interface of the data stream to write to the recorder.

### `startingBlockAddress` [in]

Starting logical block address (LBA) of the write operation. Negative values are supported.

### `numberOfBlocks` [in]

Number of blocks from the data stream to write.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |
| **E_IMAPI_REQUEST_CANCELLED** | The request was canceled.<br><br>Value: 0xC0AA0002 |

## Remarks

Before calling this method, you must call the [IWriteEngine2::put_Recorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_recorder) method to specify the recording device and the [IWriteEngine2::put_BytesPerSector](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_bytespersector) method to specify the number of bytes to use for each sector during writing.

You should also consider calling the following methods if their default values are not appropriate for your application:

* [IWriteEngine2::put_EndingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_endingsectorspersecond)
* [IWriteEngine2::put_StartingSectorsPerSecond](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_startingsectorspersecond)
* [IWriteEngine2::put_UseStreamingWrite12](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-put_usestreamingwrite12)

This method is synchronous. To determine the progress of the write operation, you must implement the [DWriteEngine2Events](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-dwriteengine2events) interface. For examples that show how to implement an event handler in a script, see [Monitoring Progress With Events](https://learn.microsoft.com/windows/desktop/imapi/monitoring-progress-with-events).

## See also

[DWriteEngine2Events](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-dwriteengine2events)

[IWriteEngine2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-iwriteengine2)

[IWriteEngine2::CancelWrite](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-cancelwrite)

[IWriteEngine2::get_WriteInProgress](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2-get_writeinprogress)

[IWriteEngine2EventArgs::get_SectorCount](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_sectorcount)

[IWriteEngine2EventArgs::get_StartLba](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-iwriteengine2eventargs-get_startlba)