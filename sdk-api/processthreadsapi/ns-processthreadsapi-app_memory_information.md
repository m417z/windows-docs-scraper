# APP_MEMORY_INFORMATION structure

## Description

Represents app memory usage at a single point in time. This structure is used by the [PROCESS_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class) enumeration.

## Members

### `AvailableCommit`

Total commit available to the app.

### `PrivateCommitUsage`

The app's usage of private commit.

### `PeakPrivateCommitUsage`

The app's peak usage of private commit.

### `TotalCommitUsage`

The app's total usage of private plus shared commit.

## See also

[PROCESS_INFORMATION_CLASS enumeration](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_information_class)