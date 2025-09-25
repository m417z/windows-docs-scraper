# CloseClusterGroupSet function

## Description

Closes a groupset handle returned from [OpenClusterGroupSet](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroupset).

## Parameters

### `hGroupSet` [in]

The handle to close

## Return value

| Return code | Description |
| --- | --- |
| **TRUE** | The operation was successful. |
| **FALSE** | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |