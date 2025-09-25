# NdfCancelIncident function

## Description

The **NdfCancelIncident** function is used to cancel unneeded functions which have been previously called on an existing incident.

## Parameters

### `Handle` [in]

Type: **NDFHANDLE**

Handle to the Network Diagnostics Framework incident. This handle should match the handle of an existing incident.

## Return value

Type: **HRESULT**

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation succeeded. |

 Any result other than S_OK should be interpreted as an error.

## Remarks

Before using this API, an application must call an incident creation function such as [NdfCreateWebIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcreatewebincident).

**NdfCancelIncident** is primarily used to cancel calls to functions such as [NdfDiagnoseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfdiagnoseincident) or [NdfRepairIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfrepairincident) which have been previously called, but are no longer needed. When **NdfCancelIncident** is called, NDF will stop the diagnosis/repair as soon as possible rather than calling the other functions (unless results have already been returned from those functions, in which case **NdfCancelIncident** will have no effect).

[NdfCloseIncident](https://learn.microsoft.com/windows/desktop/api/ndfapi/nf-ndfapi-ndfcloseincident) should be used to close an incident once it has been resolved, as **NdfCancelIncident** does not actually close the incident itself.