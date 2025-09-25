# NdfDiagnoseIncident function

## Description

The **NdfDiagnoseIncident** function diagnoses the root cause of an incident without displaying a user interface.

## Parameters

### `Handle` [in]

Type: **NDFHANDLE**

A handle to the Network Diagnostics Framework incident.

### `RootCauseCount` [out]

Type: **ULONG***

The number of root causes that could potentially have caused this incident. If diagnosis does not succeed, the contents of this parameter should be ignored.

### `RootCauses` [out]

Type: **[RootCauseInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-rootcauseinfo)****

A collection of [RootCauseInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-rootcauseinfo) structures that contain a detailed description of the root cause. If diagnosis succeeds, this parameter contains both the leaf root causes identified in the diagnosis session and any non-leaf root causes that have an available repair. If diagnosis does not succeed, the contents of this parameter should be ignored.

Memory allocated to these structures should later be freed. For an example of how to do this, see the Microsoft Windows Network Diagnostics Samples.

### `dwWait`

Type: **DWORD**

The length of time, in milliseconds, to wait before terminating the diagnostic routine. INFINITE may be passed to this parameter if no time-out is desired.

### `dwFlags`

Type: **DWORD**

Possible values:

| Value | Meaning |
| --- | --- |
| **NDF_ADD_CAPTURE_TRACE**<br><br>0x0001 | Turns on network tracing during diagnosis. Diagnostic results will be included in the Event Trace Log (ETL) file returned by [NdfGetTraceFile](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfgettracefile). |
| **NDF_APPLY_INCLUSION_LIST_FILTER**<br><br>0x0002 | Applies filtering to the returned root causes so that they are consistent with the in-box scripted diagnostics behavior. Without this flag, root causes will not be filtered. This flag must be set by the caller, so existing callers will not see a change in behavior unless they explicitly specify this flag.<br><br>**Note** Available only in Windows 8 and Windows Server 2012. |

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |
| **E_HANDLE** | The NDF incident handle is not valid. |
| **WAIT_TIMEOUT** | The diagnostic routine has terminated because it has taken longer than the time-out specified in dwWait. |

## Remarks

This function is intended for use with scenarios where no user interface is shown, or where the standard Windows experience is not being used (as with Media Center and embedded applications). [NdfExecuteDiagnosis](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfexecutediagnosis) will launch the diagnostics user interface, and should be used in scenarios using the standard Windows experience. You can call either **NdfExecuteDiagnosis** or **NdfDiagnoseIncident**, but not both.

Before using this API, an application must call an incident creation function such as [NdfCreateWebIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewebincident) to begin the NDF diagnostics process. The application then calls **NdfDiagnoseIncident** to diagnose the issue. If the diagnostics process identifies some possible repairs, the application can call [NdfRepairIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfrepairincident) to repair the problem without displaying a user interface. [NdfCancelIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcancelincident) can optionally be called from a separate thread if the application wants to cancel an ongoing **NdfDiagnoseIncident** call. Finally, the application calls [NdfCloseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcloseincident).

The following table shows some examples of root causes and their corresponding repairs.

|  |  |  |  |
| --- | --- | --- | --- |
| Root cause GUID | Repair GUID | Root cause description | Repair description |
| {4DA030B8-86E5-4b6a-A879-2FFF8443B527} | {1296DFF0-D04E-4be1-A512-90F04DDFA3E6} | A network cable is not properly plugged in or may be broken. | Plug an Ethernet cable into this computer.\nAn Ethernet cable looks like a telephone cable but with larger connectors on the ends. Plug this cable into the opening on the back or side of the computer.\nMake sure the other end of the cable is plugged into the router. If that does not help, try using a different cable. |
| {60372FD2-AD60-45c2-BD83-6B827FC438DF} | {07d37f7b-fa5e-4443-bda7-ab107b29afb6} | The %InterfaceName% adapter is disabled. | Enable the %FriendlyInterfaceName% adapter. |
| {245A9D66-AE9C-4518-A5B4-655752B0A5BD} | {07d37f7b-fa5e-4443-bda7-ab107b29afb9} | %InterfaceName%"" doesn't have a valid IP configuration. | Reset the ""%InterfaceName%"" adapter.\nThis can sometimes resolve an intermittent problem. |

## See also

[NdfExecuteDiagnosis](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfexecutediagnosis)

[NdfGetTraceFile](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfgettracefile)

[RootCauseInfo](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-rootcauseinfo)