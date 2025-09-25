# CoGetCallerTID function

## Description

Returns a pointer to a **DWORD** that contains the apartment ID of the caller's thread.

## Parameters

### `lpdwTID` [out]

Receives the apartment ID of the caller's thread. For a single threaded apartment (STA), this is the current thread ID. For a multithreaded apartment (MTA), the value is 0. For a neutral apartment (NA), the value is -1.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_TRUE** | The caller's thread ID is set and the caller is in the same process. |
| **S_FALSE** | The caller's thread ID is set and the caller is in a different process. |
| **E_OUTOFMEMORY** | The caller's thread ID was not set. |

## Remarks

If the caller is not running on the same computer, this function does not return the apartment ID and the return value is S_FALSE.

There is no guarantee that the information returned from this API is not tampered with, so do not use the ID that is returned to make security decisions. The ID can only be used for logging and diagnostic purposes.