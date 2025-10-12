# WmiTraceMessage function

## Description

The **WmiTraceMessage** routine adds a message to the output log of a [WPP software tracing](https://learn.microsoft.com/windows-hardware/drivers/devtest/wpp-software-tracing) session.

## Parameters

### `LoggerHandle` [in]

Specifies a trace handle for a software tracing session.

### `MessageFlags` [in]

Specifies a bitwise OR of one or more message flags. See the Remarks section for details.

### `MessageGuid` [in]

Specifies a GUID that identifies the class of software trace messages.

### `MessageNumber` [in]

Identifies the message subtype. The meaning of subtypes is specific to the software trace class and the provider.

### `...` [in]

Provides a required list of message parameters that specify a set of message parts. The parameters are organized as a sequence of parameter pairs, where each pair specifies one part of the complete message. Each parameter pair consists of a PVOID pointer to data, followed immediately by a size_t value that specifies the length of the data. The parameter list must be terminated by a **NULL** PVOID pointer followed by a size_t(0).

## Return value

**WmiTraceMessage** returns one of the following values:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_INVALID_HANDLE** | *LoggerHandle* is not a valid software trace handle. |
| **STATUS_NO_MEMORY** | There is insufficient buffer memory to log the message. See the Remarks section. |
| **Other NTSTATUS value** | An internal error occurred. |

## Remarks

A caller can use **WmiTraceMessage** or [WmiTraceMessageVa](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmitracemessageva) to add a message to the output log of a WPP software tracing session. **WmiTraceMessage** simplifies a caller's code by handling the variable list mechanism before calling **WmiTraceMessageVa**.

A caller can set the following message flags:

| Flag | Description |
| --- | --- |
| TRACE_MESSAGE_SEQUENCE | Include a sequence number in the message. Message sequencing can only be used if it is set for the software tracing session specified by *LoggerHandle*. |
| TRACE_MESSAGE_GUID | *MessageGuid* specifies a GUID that identifies a software trace class. This flag must be set. |
| TRACE_MESSAGE_TIMESTAMP | Include a time stamp in the message. |
| TRACE_MESSAGE_PERFORMANCE_TIMESTAMP | This flag is not implemented and is obsolete. It must not be used. |
| TRACE_MESSAGE_SYSTEMINFO | Include the thread identifier (TID) and process identifier (PID) in the message. |

A message will not be logged if one of the following is true:

* The total size, in bytes, of the message data and the message header is greater than the size of individual message buffers allocated for a software tracing session. (The maximum message header size is 48 bytes.)
* All message buffers allocated to software tracing session are full.

**WmiTraceMessage** runs at the IRQL of the caller.

## See also

[IoWMIWriteEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiwriteevent)

[TRACE_INFORMATION_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_trace_information_class)

[WmiFireEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmilib/nf-wmilib-wmifireevent)

[WmiQueryTraceInformation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmiquerytraceinformation)

[WmiTraceMessageVa](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmitracemessageva)