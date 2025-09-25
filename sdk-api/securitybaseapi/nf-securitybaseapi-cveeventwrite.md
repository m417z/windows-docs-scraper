# CveEventWrite function

## Description

A tracing function for publishing events when an attempted security vulnerability exploit is detected in your user-mode application.

## Parameters

### `CveId` [in]

A pointer to the CVE ID associated with the vulnerability for which this event is being raised.

### `AdditionalDetails` [in, optional]

A pointer to a string giving additional details that the event producer may want to provide to the consumer of this event.

## Return value

Returns ERROR_SUCCESS if successful or one of the following values on error.

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters is not valid. |
| **ERROR_ARITHMETIC_OVERFLOW** | The event size is larger than the allowed maximum (64k - header). |
| **ERROR_MORE_DATA** | The session buffer size is too small for the event. |
| **ERROR_NOT_ENOUGH_MEMORY** | Occurs when filled buffers are trying to flush to disk, but disk IOs are not happening fast enough. This happens when the disk is slow and event traffic is heavy. Eventually, there are no more free (empty) buffers and the event is dropped. |
| **STATUS_LOG_FILE_FULL** | The real-time playback file is full. Events are not logged to the session until a real-time consumer consumes the events from the playback file. Do not stop logging events based on this error code. |

## Remarks

The CveEventWrite function publishes a CVE-based event. This function should be called only in scenarios where an attempt to exploit a known, patched vulnerability is detected by the application. Ideally, this function call should be added as part of the fix (update) itself.

The default consumer for this event is EventLog-Application. To enable another consumer, the provider can be added to the consumer session.

Provider GUID: 85a62a0d-7e17-485f-9d4f-749a287193a6

Source Name: Microsoft-Windows-Audit-CVE or Audit-CVE