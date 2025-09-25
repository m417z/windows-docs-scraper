# ITTerminalControl::DisconnectTerminal

## Description

The
**DisconnectTerminal** method disconnects internal filters and removes them from the filter graph.

## Parameters

### `pGraph` [in]

Pointer to the interface for the graph to be disconnected.

### `dwReserved` [in]

Reserved; not currently used.

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_UNEXPECTED** | An unknown error occurred during the disconnect attempt. |

## See also

[ITTerminalControl](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itterminalcontrol)