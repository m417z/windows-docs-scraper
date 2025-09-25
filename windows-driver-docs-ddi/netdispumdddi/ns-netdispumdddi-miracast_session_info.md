# MIRACAST_SESSION_INFO structure

## Description

Contains info on a wireless display (Miracast) connected session.

## Members

### `MonitorConnected`

If set, the monitor (the source) is connected to a Miracast sink.

### `ReducedModeListDueToBandwidth`

If set, the user-mode driver has reduced the modes exposed to the operating system based on the current suggested encode rate.

### `Reserved`

Reserved for system use and should be set to zero.

### `Value`

Holds a 32-bit value that identifies the Miracast connected session.