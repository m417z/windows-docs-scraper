# REPORT_STORE_TYPES enumeration

## Description

Defines the types of [Windows Error Reporting](https://learn.microsoft.com/windows/win32/api/_wer/) (WER) report stores that can be opened.

## Constants

### `E_STORE_USER_ARCHIVE`

User store of archived reports.

### `E_STORE_USER_QUEUE`

User store of queued reports.

### `E_STORE_MACHINE_ARCHIVE`

Machine-wide store of archived reports. You cannot depend on how long reports will be here. Older reports are better obtained through the event log.

### `E_STORE_MACHINE_QUEUE`

Machine-wide store of queued reports.

### `E_STORE_INVALID`

Invalid store archive.

## Remarks

## See also

[Windows Error Reporting](https://learn.microsoft.com/windows/desktop/wer)