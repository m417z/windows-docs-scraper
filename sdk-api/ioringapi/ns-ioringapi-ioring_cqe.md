## Description

Represents a completed I/O ring queue entry.

## Members

### `UserData`

A **UINT_PTR** representing the user data associated with the entry. This is the same value provided as the *UserData* parameter when building the operation's submission queue entry. Applications can use this value to correlate the completion with the original operation request.

### `ResultCode`

A **HRESULT** indicating the result code of the associated I/O ring operation.

### `Information`

A **ULONG_PTR** representing information about the completed queue operation.

## Remarks

## See also