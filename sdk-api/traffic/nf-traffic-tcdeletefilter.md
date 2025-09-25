# TcDeleteFilter function

## Description

The
**TcDeleteFilter** function deletes a filter previously added with the
[TcAddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddfilter) function.

## Parameters

### `FilterHandle` [in]

Handle to the filter to be deleted, as received in a previous call to the
[TcAddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddfilter) function.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function executed without errors. |
| **ERROR_INVALID_HANDLE** | The filter handle is invalid. |

**Note** Use of the
**TcDeleteFilter** function requires administrative privilege.

## See also

[TcAddFilter](https://learn.microsoft.com/previous-versions/windows/desktop/api/traffic/nf-traffic-tcaddfilter)