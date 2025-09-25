# IComCRMEvents::OnCRMForce

## Description

Generated when a CRM clerk receives a request to force log records to disk, either from the CRM worker or from the CRM compensator.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidClerkCLSID` [in]

The identifier of the CRM clerk.

## Return value

The user verifies the return values from this method.

## See also

[IComCRMEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomcrmevents)