# TSSESSION_STATE enumeration

## Description

Indicates the state of a session.

## Constants

### `STATE_INVALID:-1`

The session state is not valid.

### `STATE_ACTIVE`

The user is logged on to WinStation.

### `STATE_CONNECTED`

WinStation is connected to the client (session reconnected).

### `STATE_CONNECTQUERY`

In the process of connecting to the client (session reconnect pending).

### `STATE_SHADOW`

Shadowing another WinStation.

### `STATE_DISCONNECTED`

WinStation is active but the client is disconnected.

### `STATE_IDLE`

Waiting for the client to connect.

### `STATE_LISTEN`

WinStation is listening for a connection.

### `STATE_RESET`

WinStation is being reset (session logged off).

### `STATE_DOWN`

WinStation is down due to error.

### `STATE_INIT`

WinStation is initializing.

### `STATE_MAX`

## See also

[ITsSbSession](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbsession)