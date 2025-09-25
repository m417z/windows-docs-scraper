# WTSGetChildSessionId function

## Description

Retrieves the child session identifier, if present.

## Parameters

### `pSessionId` [out]

The address of a **ULONG** variable that receives the child session identifier. This will be (**ULONG**)–1 if there is no child session for the current session.

## Return value

Returns nonzero if the function succeeds or zero otherwise.

## Remarks

For more information about child sessions, see [Child Sessions](https://learn.microsoft.com/windows/desktop/TermServ/child-sessions).