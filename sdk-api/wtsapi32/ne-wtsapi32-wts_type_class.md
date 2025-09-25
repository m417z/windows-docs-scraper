# WTS_TYPE_CLASS enumeration

## Description

Specifies the type of structure that a Remote Desktop Services function has returned in a buffer.

## Constants

### `WTSTypeProcessInfoLevel0`

The buffer contains one or more [WTS_PROCESS_INFO](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_infoa) structures.

### `WTSTypeProcessInfoLevel1`

The buffer contains one or more [WTS_PROCESS_INFO_EX](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_process_info_exa) structures.

### `WTSTypeSessionInfoLevel1`

The buffer contains one or more [WTS_SESSION_INFO_1](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_session_info_1a) structures.

## See also

[WTSFreeMemory](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememory)

[WTSFreeMemoryEx](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsfreememoryexa)