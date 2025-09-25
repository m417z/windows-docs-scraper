## Description

A **STORPORT_ETW_EVENT_OPCODE** enumeration defines operational nature of an ETW event.

## Constants

### `StorportEtwEventOpcodeInfo:0`

Indicates a general, informational event.

### `StorportEtwEventOpcodeStart:1`

The device or unit was started.

### `StorportEtwEventOpcodeStop:2`

The device or unit was stopped. The event corresponses to the last unpaired start event.

### `StorportEtwEventOpcodeDC_Start:3`

Indicates a data collection starting event. These are rundown event types.

### `StorportEtwEventOpcodeDC_Stop:4`

Indicates a data collection stopping event. These are rundown event types.

### `StorportEtwEventOpcodeExtension:5`

Indicates an extension event.

### `StorportEtwEventOpcodeReply:6`

Indicates a reply event.

### `StorportEtwEventOpcodeResume:7`

The device or unit was resumed after a suspend event.

### `StorportEtwEventOpcodeSuspend:8`

The device or unit is suspended pending completion of another operation.

### `StorportEtwEventOpcodeSend:9`

Indicates that transfer of activity is sent to another component.

### `StorportEtwEventOpcodeReceive:240`

Indicates that transfer of activity is received from another component.

## Remarks

## See also

[**StorPortEtwChannelEvent2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwchannelevent2)

[**StorPortEtwChannelEvent4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwchannelevent4)

[**StorPortEtwChannelEvent8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwchannelevent8)

[**StorPortEtwEvent2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent2)

[**StorPortEtwEvent4**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent4)

[**StorPortEtwEvent8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwevent8)

[**StorPortEtwLogByteStream**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportetwlogbytestream)

[**StorPortNvmeMiniportEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportnvmeminiportevent)