# DrtClose function

## Description

The **DrtClose** function closes the local instance of the DRT.

## Parameters

### `hDrt` [in]

Handle to the DRT instance.

## Return value

This function returns S_OK on success. Other possible values include:

| Return code | Description |
| --- | --- |
| **E_HANDLE** | The *hDrt* handle is invalid. |

## See also

[DrtOpen](https://learn.microsoft.com/windows/desktop/api/drt/nf-drt-drtopen)