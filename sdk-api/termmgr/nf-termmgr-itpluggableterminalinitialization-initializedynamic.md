# ITPluggableTerminalInitialization::InitializeDynamic

## Description

The
**InitializeDynamic** method performs primary terminal object creation for the pluggable terminal.

## Parameters

### `iidTerminalClass` [in]

The IID_ for the class of the terminal being initialized.

### `dwMediaType` [in]

ORed list of the media types supported by the terminal.

### `Direction` [in]

The
[TERMINAL_DIRECTION](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-terminal_direction) descriptor for the terminal.

### `htAddress` [in]

MSP handle for the address to associate with the terminal being created.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ITPluggableTerminalInitialization](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalinitialization)