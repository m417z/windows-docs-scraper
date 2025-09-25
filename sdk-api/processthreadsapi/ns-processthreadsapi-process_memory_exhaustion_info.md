# PROCESS_MEMORY_EXHAUSTION_INFO structure

## Description

Allows applications to configure a process to terminate if an allocation fails to commit memory. This structure is used by the [PROCESS_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/mt767996(v=vs.85)) class.

## Members

### `Version`

Version should be set to **PME_CURRENT_VERSION**.

### `Reserved`

Reserved.

### `Type`

Type of failure.

Type should be set to **PMETypeFailFastOnCommitFailure** (this is the only type available).

### `Value`

Used to turn the feature on or off.

|  |  |
| --- | --- |
| Function | Setting |
| Enable | PME_FAILFAST_ON_COMMIT_FAIL_ENABLE |
| Disable | PME_FAILFAST_ON_COMMIT_FAIL_DISABLE |

## See also

[PROCESS_INFORMATION_CLASS](https://learn.microsoft.com/previous-versions/mt767996(v=vs.85))

[PROCESS_MEMORY_EXHAUSTION_TYPE](https://learn.microsoft.com/windows/win32/api/processthreadsapi/ne-processthreadsapi-process_memory_exhaustion_type)