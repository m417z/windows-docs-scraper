# IPsecDospStateCreateEnumHandle0 function

## Description

The **IPsecDospStateCreateEnumHandle0** function creates a handle used to enumerate a set of IPsec DoS Protection objects.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumTemplate` [in, optional]

Type: **const [IPSEC_DOSP_STATE_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_dosp_state_enum_template0)***

Template for selectively restricting the enumeration.

### `enumHandle` [out]

Type: **HANDLE***

Address of a **HANDLE** variable. On function return, it contains the handle for the newly created enumeration.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The enumeration was created successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If *enumTemplate* is **NULL**, all IPsec DoS Protection objects are returned.

The caller must call [IPsecDospStateDestroyEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecdospstatedestroyenumhandle0) to free the returned handle.

The caller needs [FWPM_ACTRL_READ_STATS](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) access to the IPsec DoS Protection component. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IPsecDospStateCreateEnumHandle0** is a specific implementation of IPsecDospStateCreateEnumHandle. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_DOSP_STATE_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_dosp_state_enum_template0)

[IPsecDospStateDestroyEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecdospstatedestroyenumhandle0)