# FsrmEventType enumeration

## Description

Defines the event types that an event logging action (see
[FsrmActionType](https://learn.microsoft.com/windows/desktop/api/fsrmenums/ne-fsrmenums-fsrmactiontype)) can log.

## Constants

### `FsrmEventType_Unknown:0`

The event type is unknown. Do not use this flag.

### `FsrmEventType_Information:1`

The event is an information event.

### `FsrmEventType_Warning:2`

The event is a warning event.

### `FsrmEventType_Error:3`

The event is an error event.

## See also

[FSRM Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrm-enumerations)

[IFsrmActionEventLog::EventType](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrm/nf-fsrm-ifsrmactioneventlog-get_eventtype)

[MSFT_FSRMAction](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/msft-fsrmaction)