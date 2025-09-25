# PFSCE_FREE_INFO callback function

## Description

The [PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info) callback function frees the memory for buffers allocated by the Security Configuration tool set when it calls
[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info).

## Parameters

### `pvServiceInfo` [in]

Specifies a pointer to the buffer allocated by the Security Configuration tool set.

## Return value

If the function succeeds, it returns SCESTATUS_SUCCESS. Otherwise, an error code is returned. This can be the following.

| Return code | Description |
| --- | --- |
| **SCESTATUS_INVALID_PARAMETER** | One of the parameters passed into the function was not valid. |

## See also

[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info)