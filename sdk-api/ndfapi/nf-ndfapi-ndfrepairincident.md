# NdfRepairIncident function

## Description

The **NdfRepairIncident** function repairs an incident without displaying a user interface.

## Parameters

### `Handle` [in]

Type: **NDFHANDLE**

Handle to the Network Diagnostics Framework incident. This handle should match the handle passed to [NdfDiagnoseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfdiagnoseincident).

### `RepairEx` [in]

Type: **[RepairInfoEx](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfoex)***

A structure (obtained from [NdfDiagnoseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfdiagnoseincident)) which indicates the particular repair to be performed.

Memory allocated to these structures should later be freed. For an example of how to do this, see the Microsoft Windows Network Diagnostics Samples.

### `dwWait`

Type: **DWORD**

The length of time, in milliseconds, to wait before terminating the diagnostic routine. INFINITE may be passed to this parameter if no timeout is desired.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Repair succeeded. |
| **NDF_E_VALIDATION** | The repair executed successfully, but NDF validation still found a connectivity problem. If this value is returned, the session should be closed by calling [NdfCloseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcloseincident) and another session should be created to continue the diagnosis. |
| **E_HANDLE** | The NDF incident handle is not valid. |
| **WAIT_TIMEOUT** | The repair operation has terminated because it has taken longer than the time-out specified in dwWait. |

Other failure codes are returned if the repair failed to execute. In that case, the client can call **NdfRepairIncident** again with a different repair.

## Remarks

**NdfRepairIncident** can only be called when [NdfDiagnoseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfdiagnoseincident) is used for diagnostics. This is typically the case in scenarios where no user interface is shown, or where the standard Windows experience is not being used (as with Media Center and embedded applications). **NdfRepairIncident** should not be called when [NdfExecuteDiagnosis](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfexecutediagnosis) is used.

Before using this API, an application must call an incident creation function such as [NdfCreateWebIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewebincident) to begin the NDF diagnostics process. The application then calls [NdfDiagnoseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfdiagnoseincident) to diagnose the issue. If the diagnostics process identifies some possible repairs, the application can call **NdfRepairIncident** to repair the problem without displaying a user interface. [NdfCancelIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcancelincident) can optionally be called from a separate thread if the application wants to cancel an ongoing **NdfRepairIncident** call. Finally, the application calls [NdfCloseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcloseincident).

## See also

[NdfDiagnoseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfdiagnoseincident)

[RepairInfoEx](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-repairinfoex)