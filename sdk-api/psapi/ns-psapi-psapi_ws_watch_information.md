# PSAPI_WS_WATCH_INFORMATION structure

## Description

Contains information about a page added to a process working set.

## Members

### `FaultingPc`

A pointer to the instruction that caused the page fault.

### `FaultingVa`

A pointer to the page that was added to the working set.

## See also

[GetWsChanges](https://learn.microsoft.com/windows/desktop/api/psapi/nf-psapi-getwschanges)