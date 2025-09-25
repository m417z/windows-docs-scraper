# IComCRMEvents::OnCRMBegin

## Description

Generated when a CRM clerk is starting, either due to a client registering a compensator or during recovery.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidClerkCLSID` [in]

The identifier of the CRM clerk.

### `guidActivity` [in]

The activity identifier (NULL if recovery).

### `guidTx` [in]

The identifier of the Transaction Unit Of Work (UOW).

### `szProgIdCompensator` [in]

The ProgID of the CRM compensator.

### `szDescription` [in]

The description (blank if recovery).

## Return value

The user verifies the return values from this method.

## See also

[IComCRMEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomcrmevents)