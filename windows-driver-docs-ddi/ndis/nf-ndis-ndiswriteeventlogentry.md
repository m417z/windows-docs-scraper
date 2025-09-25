# NdisWriteEventLogEntry function

## Description

**NdisWriteEventLogEntry** logs an event to the Win32 event log.

## Parameters

### `LogHandle` [in]

Pointer to the driver object of the protocol that is logging this event.

### `EventCode` [in]

Specifies the NDIS_STATUS_*XXX* code describing the event.

### `UniqueEventValue` [in]

Identifies this instance of the error message.

### `NumStrings` [in]

Specifies the number of pointers to Unicode strings in the optional
*StringsList*. If
*StringsList* is **NULL**,
*NumStrings* must be zero.

### `StringsList` [in, optional]

Either **NULL** or points to buffered Unicode strings. These strings, which describe the event, are
inserted into the Win32 event log and can be examined with the Win32 event viewer. Each string must be a
NUL-terminated Unicode string.

### `DataSize` [in]

Specifies the number of bytes in the buffer for the binary data at
*Data* . If
*Data* is **NULL**,
*DataSize* must be zero.

### `Data` [in, optional]

Either **NULL** or points to buffered binary dump data that is useful for understanding the event.
This data can be examined with the Win32 event viewer.

## Return value

**NdisWriteEventLogEntry** can return one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The event was successfully logged. |
| **NDIS_STATUS_BUFFER_TOO_SHORT** | The optionally supplied Unicode strings and binary dump data exceed the maximum-allowed size (MAX_EVENT_LOG_DATA_SIZE). |
| **NDIS_STATUS_RESOURCES** | NDIS was unable to allocate memory for the I/O error log record. |

## Remarks

**NdisWriteEventLogEntry** allocates an I/O error log record, fills in the record with the supplied
information about the event, and then writes the record to the I/O error log file. A user can view the
logged event, including an optional description of the event and/or optional binary dump data, with the
Win32 event viewer.

The NT error-logging thread uses any strings supplied in the optional
*StringsList* to fill in messages written into the Win32 event log. Each string must be a
NUL-terminated Unicode string. The I/O manager assumes that the initial string is either the name of the
driver reporting the error or the name of the device that caused the error.

The Unicode strings supplied by the caller should be read from the registry or should be
language-independent (that is, the strings should be the same in any language -- for example, the string
could be a file name).

Caller-supplied dump data can be any binary data (such as register values) that is useful in
understanding the event. The caller does not have to pad the binary data. If necessary,
**NdisWriteEventLogEntry** pads the binary dump data so that the final data size is a multiple integral
of
**sizeof**(ULONG).

The system limits the total size of the optional data supplied to
**NdisWriteEventLogEntry**. The combined size of the strings list and the (possibly padded) binary
dump must be less than or equal to MAX_EVENT_LOG_DATA_SIZE.

**NdisWriteEventLogEntry** is called only by protocol drivers. Miniport drivers should call
**NdisWriteErrorLogEntry** to log events and errors.

## See also

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportResetEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_reset)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)

[NdisWriteErrorLogEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteerrorlogentry)