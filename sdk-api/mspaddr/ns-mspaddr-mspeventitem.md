# MSPEVENTITEM structure

## Description

The
**MSPEVENTITEM** structure contains link pointers and event types for MSP events.

## Members

### `Link`

Doubly-linked list. Part of Windows 2000 run-time routines that are callable by both kernel mode code in the executive and user mode code in various subsystems. See Ntrtl.h or search the Platform SDK for details.

### `MSPEventInfo`

The
[MSP_EVENT_INFO](https://learn.microsoft.com/windows/win32/api/msp/ns-msp-msp_event_info) structure contains information concerning an event.