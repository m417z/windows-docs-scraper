# IStreamBufferConfigure::GetBackingFileCount

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **GetBackingFileCount** method retrieves the maximum and minimum number of backing files.

## Parameters

### `pdwMin` [out]

Pointer to a variable that receives the backing file minimum.

### `pdwMax` [out]

Pointer to a variable that receives the backing file maximum.

## Return value

Returns an **HRESULT**. Possible values include those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If the reader lags behind the writer by more than *pdwMin* files, the writer starts to send STREAMBUFFER_EC_CONTENT_BECOMING_STALE events. If the reader lags behind the writer by more than *pdwMax* files, the writer begins to overwrite files and sends an STREAMBUFFER_EC_STALE_FILE_DELETED event.

## See also

[IStreamBufferConfigure Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/sbe/nn-sbe-istreambufferconfigure)