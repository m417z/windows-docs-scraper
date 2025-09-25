# PSAPI_WS_WATCH_INFORMATION_EX structure

## Description

Contains extended information about a page added to a process working set.

## Members

### `BasicInfo`

A [PSAPI_WS_WATCH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_ws_watch_information) structure.

### `FaultingThreadId`

The identifier of the thread that caused the page fault.

### `Flags`

This member is reserved for future use.

## See also

[GetWsChangesEx](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getwschangesex)

[PSAPI_WS_WATCH_INFORMATION](https://learn.microsoft.com/windows/desktop/api/psapi/ns-psapi-psapi_ws_watch_information)