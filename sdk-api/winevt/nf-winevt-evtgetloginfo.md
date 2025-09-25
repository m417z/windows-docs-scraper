# EvtGetLogInfo function

## Description

Gets information about a channel or log file.

## Parameters

### `Log` [in]

 A handle to the channel or log file that the [EvtOpenLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenlog) function returns.

### `PropertyId` [in]

The identifier of the property to retrieve. For a list of property identifiers, see the [EVT_LOG_PROPERTY_ID](https://learn.microsoft.com/windows/desktop/api/winevt/ne-winevt-evt_log_property_id) enumeration.

### `PropertyValueBufferSize` [in]

The size of the *PropertyValueBuffer* buffer, in bytes.

### `PropertyValueBuffer` [in]

A caller-allocated buffer that will receive the property value. The buffer contains an [EVT_VARIANT](https://learn.microsoft.com/windows/desktop/api/winevt/ns-winevt-evt_variant) object. You can set this parameter to **NULL** to determine the required buffer size.

### `PropertyValueBufferUsed` [out]

The size, in bytes, of the caller-allocated buffer that the function used or the required buffer size if the function fails with ERROR_INSUFFICIENT_BUFFER.

## Return value

| Return code/value | Description |
| --- | --- |
| **TRUE** | The function succeeded. |
| **FALSE** | The function failed. To get the error code, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function. |

## Remarks

 You can get complete information for Operational and Admin channels or .evtx files; however, for Debug and Analytic channels or .etl files, you cannot get information for the EvtLogFull, EvtLogOldestRecordNumber, and EvtLogNumberOfLogRecords properties.

## See also

[EvtOpenLog](https://learn.microsoft.com/windows/desktop/api/winevt/nf-winevt-evtopenlog)