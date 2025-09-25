## Description

The **STORPORT_ETW_LEVEL** enumeration defines the level of importance or severity of an ETW event.

## Constants

### `StorportEtwLevelLogAlways:0`

Log the event unconditionally. An event with this level is logged without any throttling.

### `StorportEtwLevelCritical:1`

Indicates a critical condition that could cause severe problems such as a system crash. An event with this level is logged without any throttling.

### `StorportEtwLevelError:2`

Indicates an error condition. Events at this level are throttled at the specific device instance at which the miniport event is targeted. There's an upper limit on the count of events per hour at the device instance.

### `StorportEtwLevelWarning:3`

Indicates a potential issue or something unexpected. Like error-level events, warning-level events are throttled at the specific device instance level.

### `StorportEtwLevelInformational:4`

Indicates an informational event, such as status. Informational events are also throttled at the specific device instance level.

### `StorportEtwLevelVerbose:5`

Indicates that the event provides detailed tracing information, typically for debugging purposes. Verbose-level events aren't throttled.

### `StorportEtwLevelMax`

Maximum value for the enumeration.

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