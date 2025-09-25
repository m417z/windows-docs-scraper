# WsResetServiceHost function

## Description

Resets service host so that it can be opened again.

Rather the creating a new service host from scratch **WsResetServiceHost**
provides a convenient way to reuse service host. Specifically in a scenario
where a service host has to go through close and open on a regular basis,
this allows for an efficient way for reusing the same service host. It resets
the underlying channel and listeners for reuse.

## Parameters

### `serviceHost` [in]

The service host to reset.

### `error` [in, optional]

Specifies where additional error information should be stored if the function fails.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **WS_E_INVALID_OPERATION** | The serviceHost was in an inappropriate state. |
| **E_INVALIDARG** | One or more arguments are invalid. |