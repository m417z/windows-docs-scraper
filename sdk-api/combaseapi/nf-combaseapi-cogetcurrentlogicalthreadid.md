# CoGetCurrentLogicalThreadId function

## Description

Returns the logical thread identifier of the current physical thread.

## Parameters

### `pguid` [out]

A pointer to a GUID that contains the logical thread ID on return.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The logical thread ID was retrieved successfully. |
| **E_INVALIDARG** | An invalid pointer was passed in for the *pguid* parameter. |
| **E_OUTOFMEMORY** | A memory allocation failed during the operation of the function. |

## Remarks

This function retrieves the identifier of the current logical thread under which this physical thread is operating. The current physical thread takes on the logical thread identifier of any client thread that makes a COM call into this application. Similarly, the logical thread identifier of the current physical thread is used to denote the causality for outgoing COM calls from this physical thread.