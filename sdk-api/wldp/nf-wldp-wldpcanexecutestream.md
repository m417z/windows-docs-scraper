## Description

Queries whether the execution policy allows execution of the code in the supplied stream.

## Parameters

### `host` [in]

A GUID specifying the calling program. For the list of pre-defined GUIDs that can be used for this parameter, see [WLDP Host GUIDs](https://learn.microsoft.com/windows/win32/devnotes/wldp-host-guids). For hosts for which a specific value is not defined, use GUID WLDP_HOST_GUID_OTHER.

### `options` [in]

A value from the [WLDP_EXECUTION_EVALUATION_OPTIONS](https://learn.microsoft.com/windows/win32/api/wldp/ne-wldp-wldp_execution_evaluation_options) specifying options for the execution authorization request.

### `[in]`

The stream of script code to be validated.

> [!IMPORTANT]
> If a file is in the stream, callers should pass only open file handles to WldpCanExecuteStream and should not cache the security authorization on a specific file. It should be assumed that authorization to run a particular file is revoked when its file handle is closed. These measures are necessary to prevent [TOC/TOU vulnerabilities](https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use) that could subvert script enforcement policy.

### `auditInfo` [in, optional]

A string that should include relevant contextual information for the caller to use in debugging. If an authorization request fails this string will be recorded in the event log, under “Applocker/MSI and Scripts/Operational”. Callers should note that, while the *AuditInfo* is not size limited, the string should be less than 4K bytes in size because it will be placed in the event log.

### `result` [out]

Receives a pointer to a value from the [WLDP_EXECUTION_POLICY](https://learn.microsoft.com/windows/win32/api/wldp/ne-wldp-wldp_execution_policy) enumeration, indicating the execution policy result of the query.

## Return value

Returns S_OK on success and a failure code otherwise.

## Remarks

This method is provided as a replacement for [WldpGetLockdownPolicy](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpgetlockdownpolicy). This interface is differentiated from **WldpGetLockdownPolicy** in the following ways:

- Encourages callers to ensure that the subject (file, buffer, or stream) passes os execution policy.
- Allows calling apps to provide additional audit information for diagnostic purposes.
- Allows verification of buffers and streams of code.
- Simplifies the calling pattern.
- Supports fine grained execution policies like for example interactive mode in cmd or powershell

## See also

- [WldpCanExecuteBuffer](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutebuffer)
- [WldpCanExecuteFile](https://learn.microsoft.com/windows/win32/api/wldp/nf-wldp-wldpcanexecutefile)