# WS_RECEIVE_OPTION enumeration

## Description

Specifies whether a message is required when receiving from a channel.

## Constants

### `WS_RECEIVE_REQUIRED_MESSAGE:1`

A message is required to be received. If the channel does not have
any more messages, then the function will fail.

### `WS_RECEIVE_OPTIONAL_MESSAGE:2`

The message is not required to be received. If the channel does not have any more
messages, the function will return **WS_S_END**.
(See [Windows Web Services Return Values](https://learn.microsoft.com/windows/desktop/wsw/windows-web-services-return-values).)