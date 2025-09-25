# StopWatchFlush function

## Description

[**StopWatchFlush** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Writes out performance statistics if performance logging is enabled.

## Return value

Type: **DWORD**

ERROR_SUCCESS on success, or an error code on failure. Possible error codes include the following:

| Return code | Description |
| --- | --- |
| **ERROR_NO_DATA** | No performance logs were collected. |
| **ERROR_INVALID_DATA** | Performance logging is not enabled. |

## Remarks

The performance log is written to the shperf.log file in the Windows directory. If message performance logs are enabled, the message performance log is written to the msgtrace.log file in the Windows directory. If you call **StopWatchFlush**, you must have permission to create and modify files in the Windows directory.

Calling **StopWatchFlush** clears the performance logs after writing them to the shperf.log file.

See the [StopWatchMode](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-stopwatchmode) function for a description of the information that is recorded in the performance log.