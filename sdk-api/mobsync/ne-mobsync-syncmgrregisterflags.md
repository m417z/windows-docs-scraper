# SYNCMGRREGISTERFLAGS enumeration

## Description

The **SYNCMGRREGISTERFLAGS** enumeration values are used in methods of the [ISyncMgrRegister](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrregister) interface to identify events for which the handler is registered to be notified.

## Constants

### `SYNCMGRREGISTERFLAG_CONNECT:0x1`

Network connect events.

### `SYNCMGRREGISTERFLAG_PENDINGDISCONNECT:0x2`

Pending network disconnect event.

### `SYNCMGRREGISTERFLAG_IDLE:0x4`

Idle events.

## Remarks

The SYNCMGRREGISTERFLAGS_MASK value can be used to identify valid **SYNCMGRREGISTERFLAGS** values.