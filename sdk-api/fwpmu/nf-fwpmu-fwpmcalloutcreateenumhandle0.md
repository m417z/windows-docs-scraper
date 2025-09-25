# FwpmCalloutCreateEnumHandle0 function

## Description

The **FwpmCalloutCreateEnumHandle0** function creates a handle used to enumerate a set of callout objects.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumTemplate` [in, optional]

Type: [FWPM_CALLOUT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout_enum_template0)*

Template to selectively restrict the enumeration.

### `enumHandle` [out]

Type: **HANDLE***

Handle of the newly created enumeration.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The enumerator was created successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If *enumTemplate* is **NULL**, all callout objects are returned.

The enumerator is not "live", meaning it does not reflect changes made to the system after the call to **FwpmCalloutCreateEnumHandle0** returns. If you need to ensure that the results are current, you must call **FwpmCalloutCreateEnumHandle0** and [FwpmCalloutEnum0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutenum0) from within the same explicit transaction.

The caller must call [FwpmCalloutDestroyEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmcalloutdestroyenumhandle0) to free the returned handle.

The caller needs [FWPM_ACTRL_ENUM](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the callouts' containers and **FWPM_ACTRL_READ** access to the callouts. Only callouts to which the caller has **FWPM_ACTRL_READ** access will be returned. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**FwpmCalloutCreateEnumHandle0** is a specific implementation of FwpmCalloutCreateEnumHandle. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CALLOUT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_callout_enum_template0)