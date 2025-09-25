# ITTerminalControl::CompleteConnectTerminal

## Description

The
**CompleteConnectTerminal** method completes the terminal connection.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |

## Remarks

This method always returns S_OK. If an MSP cannot connect the terminal, the error return must occur during the call to
[ITTerminalControl::ConnectTerminal](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itterminalcontrol-connectterminal).

## See also

[ITTerminalControl](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itterminalcontrol)