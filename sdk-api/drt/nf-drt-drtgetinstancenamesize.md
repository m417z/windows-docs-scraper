# DrtGetInstanceNameSize function

## Description

The **DrtGetInstanceNameSize** function returns the size of the Distributed Routing Table instance name.

## Parameters

### `hDrt` [in]

Handle to the target DRT instance.

### `pulcbInstanceNameSize` [out]

The length of the DRT instance name.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | *pulcbInstanceNameSize* is **NULL**. |
| **E_HANDLE** | *hDrt* handle is invalid. |

## See also

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)