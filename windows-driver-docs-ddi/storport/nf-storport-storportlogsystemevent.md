# StorPortLogSystemEvent function

## Description

The StorPortLogSystemEvent routine gives miniport drivers full access to the capabilities of the Windows kernel event facility, enabling miniport drivers to create event log entries that are truly useful in troubleshooting storage issues. It provides a better alternative to the existing miniport driver event logging function, [StorPortLogError](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogerror).

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `LogDetails` [in, out]

A [STOR_LOG_EVENT_DETAILS](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_log_event_details) structure that contains information to appear in the system event log entry.

### `MaximumSize` [in, out]

Variable to receive maximum combined size of miniport's dump data and strings. Only returned if the function fails and returns a STOR_STATUS_INVALID_BUFFER_SIZE value. This parameter is optional.

## Return value

| Return code | Description |
| --- | --- |
| **STOR_STATUS_NOT_IMPLEMENTED** | This function is not implemented on the active operating system. |
| **STOR_STATUS_INVALID_PARAMETER** | An invalid parameter was passed in. |
| **STOR_STATUS_INVALID_IRQL** | The call was made at IRQL > DISPATCH_LEVEL. |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | There were insufficient system resources to complete the request. |
| **STOR_STATUS_UNSUPPORTED_VERSION:** | An unsupported (for example, more current) version of the STOR_LOG_EVENT_DETAILS structure was specified. When this is returned, LogDetails->InterfaceRevision is set to the latest supported version. |
| **STOR_STATUS_INVALID_BUFFER_SIZE** | The buffers passed to the function were too large. When this value is returned, MaximumSize is set to the maximum combined size of the miniport's dump data and strings. |
| **STOR_STATUS_SUCCESS** | The log operation completed successfully. |

## Remarks

To understand how you may use custom error codes to best advantage, see [Storport Error Log Extensions](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-event-log-extensions). The StorPortLogSystemEvent routine must be called at IRQL <= DISPATCH_LEVEL. If you pass in a more recent version of STOR_LOG_EVENT_DETAILS than that supported by this build, this function changes the InterfaceRevision field to the latest supported version and returns STOR_STATUS_UNSUPPORTED_VERSION. The InterfaceRevision field of STOR_LOG_EVENT_DETAILS is a 32-bit value. However, only the three most-significant bytes are used for validation. The low byte is reserved to distinguish between compatible, minor variations of a particular version. For instance, a revision 0x00000101 structure is compatible with a Storport that implements revision 0x00000100 of the interface, although it is possible that some minor, noncritical functionality may be lost. If you specify a combined size of dump data and strings that exceeds the maximum allowed event log entry size, the integer pointed to by MaximumSize is set to the maximum allowed size of miniport dump data and strings, and STOR_INVALID_BUFFER_SIZE is returned. Although this function accepts ULONG values for the path, target, and LUN address specifiers, the values are truncated to UCHAR values because Storport internally only supports 8-bit values for these specifiers.

## See also

[StorPortLogError](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportlogerror)