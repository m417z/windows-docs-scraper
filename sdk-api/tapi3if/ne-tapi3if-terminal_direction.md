# TERMINAL_DIRECTION enumeration

## Description

The
**TERMINAL_DIRECTION** enumeration is used to describe the direction of the media stream with respect to the local computer or the directional capabilities of a terminal.

## Constants

### `TD_CAPTURE:0`

The stream is captured on the local computer, and the data is sent out to the remote end of the connection. When applied to a terminal, this means it can originate a stream.

### `TD_RENDER`

The stream is arriving from the remote end of the connection. When applied to a terminal, this means it can render a stream.

### `TD_BIDIRECTIONAL`

The terminal can handle either capture or render streams.

### `TD_MULTITRACK_MIXED`

Different tracks on the multi-track terminal may travel in different directions. For example, one track may specify **TD_RENDER** and another may specify **TD_CAPTURE**.

### `TD_NONE`

The terminal direction is unknown or not initialized.

## See also

[ITStream::get_Direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstream-get_direction)

[ITStreamControl::CreateStream](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itstreamcontrol-createstream)

[ITTerminal::get_Direction](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminal-get_direction)

[ITTerminalManager::CreateDynamicTerminal](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itterminalmanager-createdynamicterminal)

[ITTerminalSupport::CreateTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-createterminal)

[ITTerminalSupport::GetDefaultStaticTerminal](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itterminalsupport-getdefaultstaticterminal)