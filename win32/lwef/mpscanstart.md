# MpScanStart function

Starts a scanning operation.

## Parameters

*hMpHandle* \[in\]

Type: **MPHANDLE**

Handle to the malware protection manager interface. This handle is returned by the [**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen) function.

*ScanType* \[in\]

Type: **[**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type)**

Specifies the type of scan. This parameter must be one of the members of the [**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type) enumeration.

*dwScanOptions* \[in\]

Type: **DWORD**

Specifies various options for scanning operation.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **MPSCAN\_OPTION\_NONE** | No specific option is requested.<br> |
| **MPSCAN\_OPTION\_ASYNC** | The scan operation is to be asynchronous, where **MpScanStart** returns immediately after the successful initiation of scanning. (By default the scan operation is synchronous, meaning **MpScanStart** will return only after the scan is finished.)<br> |
| **MPSCAN\_OPTION\_PROGRESS** | The caller is interested in receiving scan progress information via a callback.<br> |
| **MPSCAN\_OPTION\_LOWPRIORITY** | Perform the scan with low priority. (By default the scan operation is performed with normal priority.)<br> |
| **MPSCAN\_OPTION\_PACKEDEXES** | Scan packed executables for possible threats.<br> |
| **MPSCAN\_OPTION\_ARCHIVES** | Scan archive contents for possible threats. Archives are files with extensions such as .zip, .cab, or .tar.<br> |
| **MPSCAN\_OPTION\_HEURISTICS** | Enable heuristics-based scanning. This will scan for threats with detection type set to heuristics.<br> |
| **MPSCAN\_OPTION\_REPORTFRIENDLY** | Report friendly items in a resource scan. This is intended for internal use only.<br> |
| **MPSCAN\_OPTION\_REPORTUNKNOWN** | Report unknown items in a resource scan. This is intended for internal use only.<br> |
| **MPSCAN\_OPTION\_NOCONSOLIDATE** | Do not consolidate scan results with global threat view. This is useful for a client (such as an email client) which wants to control cleaning UX by itself rather than allowing default anti-malware cleaning UX. This is intended for internal use only.<br> |

*pScanResources* \[in, optional\]

Type: **PMPSCAN\_RESOURCES**

A pointer to the scan resource information. This parameter must be **NULL** for a quick scan. This is an optional parameter for a full scan. For a resource scan this parameter must be specified with at least one resource information structure. To scan specific resources the caller must have **GENERIC\_READ** permission for the resource. See [**MPSCAN\_RESOURCES**](https://learn.microsoft.com/windows/win32/lwef/mpscan-resources).

*pCallbackInfo* \[in, optional\]

Type: **PMPCALLBACK\_INFO**

A pointer to the callback information used to feed the client with scan state changes (such as start and complete) and progress information. The [**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data) passed back in the callback function reports actual scan state and progress-related information. The following is a list of possible callbacks:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **MPNOTIFY\_SCAN\_START** | Scan operation started.<br> |
| **MPNOTIFY\_SCAN\_COMPLETE** | Scan operation completed. Additional information is available via [**MPSCAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpscan-data) structure.<br> |
| **MPNOTIFY\_SCAN\_PAUSED** | Scan operation is paused.<br> |
| **MPNOTIFY\_SCAN\_RESUMED** | Scan operation resumed from pause.<br> |
| **MPNOTIFY\_SCAN\_CANCEL** | Scan operation was cancelled.<br> |
| **MPNOTIFY\_SCAN\_PROGRESS** | Scan progress information. Additional information (such as resource statistics) is available via [**MPSCAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpscan-data) structure.<br> |
| **MPNOTIFY\_SCAN\_ERROR** | Scan error information for a specific resource. The specific resource information is available via [**MPSCAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpscan-data) structure.<br> |
| **MPNOTIFY\_SCAN\_INFECTED** | Scan found an infected resource. Note that in most of the cases this will result in some threat reported at the end of the scan. Sometimes it may not materialize as a threat because of exclusions. Additional infected resource information is available via [**MPSCAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpscan-data) structure.<br> |
| **MPNOTIFY\_SCAN\_MEMORYSTART** | Quick scan portion of the full scan has started.<br> |
| **MPNOTIFY\_SCAN\_MEMORYCOMPLETE** | Quick scan portion of the full scan has completed.<br> |
| **MPNOTIFY\_INTERNAL\_FAILURE** | Scan operation has encountered a generic failure. The *hResult* in [**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data) has the specific error code.<br> |

*phScanHandle* \[out\]

Type: **PMPHANDLE**

Returned scan handle which identifies the currently initiated scan. This handle can be used in subsequent function calls, such as to retrieve a scan result. The handle must be closed with the [**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose) function.

## Return value

Type: **HRESULT**

If the function succeeds the return value is **S\_OK**.

If the function fails then the return value is a failed **HRESULT** code. The caller can use the [**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat) function to get a generic description of the error message.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |
| DLL<br> | MpClient.dll |

## See also

[**MpErrorMessageFormat**](https://learn.microsoft.com/windows/win32/lwef/mperrormessageformat)

[**MpHandleClose**](https://learn.microsoft.com/windows/win32/lwef/mphandleclose)

[**MpManagerOpen**](https://learn.microsoft.com/windows/win32/lwef/mpmanageropen)

[**MPCALLBACK\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpcallback-data)

[**MPSCAN\_DATA**](https://learn.microsoft.com/windows/win32/lwef/mpscan-data)

[**MPSCAN\_RESOURCES**](https://learn.microsoft.com/windows/win32/lwef/mpscan-resources)

[**MPSCAN\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpscan-type)

