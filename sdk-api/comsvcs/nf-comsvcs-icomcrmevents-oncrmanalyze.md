# IComCRMEvents::OnCRMAnalyze

## Description

Generated when a CRM clerk receives a record during the analysis phase of recovery.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidClerkCLSID` [in]

The identifier of the CRM clerk.

### `dwCrmRecordType` [in]

The CRM log record type (internal).

### `dwRecordSize` [in]

The log record size (approximate).

## Return value

The user verifies the return values from this method.

## See also

[IComCRMEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomcrmevents)