# DrtGetInstanceName function

## Description

The **DrtGetInstanceName** function retrieves the full name of the Distributed Routing Table instance that corresponds to the specified DRT handle.

## Parameters

### `hDrt` [in]

Handle to the DRT instance.

### `ulcbInstanceNameSize` [in, out]

The length of the *pwzDrtInstanceName* buffer.

### `pwzDrtInstanceName` [out]

Contains the complete name of the DRT instance associated with *hDRT*.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pwzDrtInstanceName* is **NULL**. |
| **E_HANDLE** | *hDrt* is invalid. |
| **DRT_E_INSUFFICIENT_BUFFER** | The *pwzDrtInstanceName* buffer is insufficient in size. |

## See also

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)