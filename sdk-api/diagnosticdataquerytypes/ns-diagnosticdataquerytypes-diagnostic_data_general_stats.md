## Description

This resource contains general statistics about a set of diagnostic data records.

## Members

### `optInLevel`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
This identifies the device's current diagnostic data opt-in level (Security = 0, Basic = 1, Enhanced = 2, and Full = 3). See remarks for more details.

### `transcriptSizeBytes`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The collective size in bytes for the diagnostic data records.

### `oldestEventTimestamp`

Type: **[UINT64](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The timestamp of the oldest event among the diagnostic data records.

### `totalEventCountLast24Hours`

Type: **[UINT32](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
Total number of events among the diagnostic data records within the last 24 hours.

### `averageDailyEvents`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**
The average number of events sent per day in this set of diagnostic data records.

## Remarks

See our [**privacy statement**](https://learn.microsoft.com/windows/privacy/windows-diagnostic-data) for information about diagnostic data opt-in levels.

## See also