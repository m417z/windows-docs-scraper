# IoSetActivityIdThread function

## Description

The IoSetActivityIdThread routine associates an activity ID with the current thread. Drivers should use this routine when they are tracing aware and are issuing I/O on a worker thread.

## Parameters

### `ActivityId`

The activity ID provided by caller.

## Return value

The activity ID that was previously set on the thread. Drivers must call IoClearActivityIdThread with this pointer when tracing is completed within the same thread context.

## Remarks

Drivers that use I/O work items do not need to call this routine because the I/O subsystem takes care of propagating activity IDs to threads in that case.