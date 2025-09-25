# IStreamBufferConfigure::SetBackingFileCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **SetBackingFileCount** method sets the maximum and minimum number of backing files.

## Parameters

### `dwMin` [in]

Specifies the backing file minimum. The valid range is from 4 to 100.

### `dwMax` [in]

Specifies the backing file maximum. The valid range is from 6 to 102, and the value must be at least 2 greater than *dwMin*.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The [StreamBufferConfig](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/streambufferconfig-object) object was not initialized. |
| **S_OK** | The method succeeded. |

## Remarks

If the reader lags behind the writer by more than *dwMin* files, the writer starts to send STREAMBUFFER_EC_CONTENT_BECOMING_STALE events. If the reader lags behind the writer by more than *dwMax* files, the writer begins to overwrite files and sends an STREAMBUFFER_EC_STALE_FILE_DELETED event.

Before calling this method, call [IStreamBufferInitialize::SetHKEY](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nf-sbe-istreambufferinitialize-sethkey) to specify a registry key where the information will be stored.

## See also

[IStreamBufferConfigure Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure)