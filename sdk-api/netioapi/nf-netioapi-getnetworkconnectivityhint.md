## Description

Retrieves the aggregate level and cost of network connectivity that an application or service is likely to experience.

## Parameters

### `ConnectivityHint` [out]

A pointer to a value of type [NL_NETWORK_CONNECTIVITY_HINT](https://learn.microsoft.com/windows/win32/api/nldef/ns-nldef-nl_network_connectivity_hint). The function sets this value to the aggregate connectivity level and cost hints.

## Return value

In user mode, returns **NO_ERROR** on success, and a Win32 error code on failure. In kernel mode, returns **STATUS_SUCCESS** on success, and an NTSTATUS error code on failure.

## Remarks

## See also