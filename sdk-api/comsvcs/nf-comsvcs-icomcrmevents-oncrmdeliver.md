# IComCRMEvents::OnCRMDeliver

## Description

Generated when a CRM clerk delivers a record to a CRM compensator.

## Parameters

### `pInfo` [in]

A pointer to a [COMSVCSEVENTINFO](https://learn.microsoft.com/windows/win32/api/comsvcs/ns-comsvcs-comsvcseventinfo) structure.

### `guidClerkCLSID` [in]

The identifier of the CRM clerk.

### `fVariants` [in]

Indicates whether the log record is being written as a **Variant** array.

### `dwRecordSize` [in]

The log record size (approximate).

## Return value

The user verifies the return values from this method.

## See also

[IComCRMEvents](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-icomcrmevents)