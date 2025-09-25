# GetApplicationRecoveryCallback function

## Description

Retrieves a pointer to the callback routine registered for the specified process. The address returned is in the virtual address space of the process.

## Parameters

### `hProcess` [in]

A handle to the process. This handle must have the PROCESS_VM_READ access right.

### `pRecoveryCallback` [out]

A pointer to the recovery callback function. For more information, see [ApplicationRecoveryCallback](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa373202(v=vs.85)).

### `ppvParameter` [out]

A pointer to the callback parameter.

### `pdwPingInterval` [out]

The recovery ping interval, in 100-nanosecond intervals.

### `pdwFlags` [out]

Reserved for future use.

## Return value

This function returns **S_OK** on success or one of the following error codes.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The application did not register for recovery. |
| **E_INVALIDARG** | One or more parameters are not valid. |

## See also

[RegisterApplicationRecoveryCallback](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-registerapplicationrecoverycallback)