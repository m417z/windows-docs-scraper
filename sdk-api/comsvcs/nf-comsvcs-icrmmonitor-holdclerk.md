# ICrmMonitor::HoldClerk

## Description

Retrieves a pointer on the specified clerk.

## Parameters

### `Index` [in]

A **VARIANT** string containing the instance CLSID of the required CRM clerk.

### `pItem` [out]

A **VARIANT** [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer returning the interface to the specified CRM clerk.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the arguments is incorrect. |
| **XACT_E_CLERKNOTFOUND** | The specified CRM clerk was not found. It may have completed before it could be held. |

## See also

[ICrmMonitor](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icrmmonitor)