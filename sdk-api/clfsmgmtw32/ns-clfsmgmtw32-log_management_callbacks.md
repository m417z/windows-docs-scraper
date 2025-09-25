# LOG_MANAGEMENT_CALLBACKS structure

## Description

The **LOG_MANAGEMENT_CALLBACKS** structure is used to register with the Common Log File System (CLFS) for the callbacks that a client program requires information from.

## Members

### `CallbackContext`

A pointer to the context which is a client-defined value. CLFS ignores this value other than to pass it with every callback to the client.

### `AdvanceTailCallback`

 Called when the management functionality determines that the client should advance the tail of its log.

### `LogFullHandlerCallback`

Called when an asynchronous request is initiated when [HandleLogFull](https://learn.microsoft.com/windows/desktop/api/clfsmgmtw32/nf-clfsmgmtw32-handlelogfull) completes.

### `LogUnpinnedCallback`

Called when a pinned log becomes unpinned.