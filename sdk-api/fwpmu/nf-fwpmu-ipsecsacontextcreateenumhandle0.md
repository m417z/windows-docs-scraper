# IPsecSaContextCreateEnumHandle0 function

## Description

The **IPsecSaContextCreateEnumHandle0** function creates a handle used to enumerate a set of IPsec security association (SA) context objects.

## Parameters

### `engineHandle` [in]

Type: **HANDLE**

Handle for an open session to the filter engine. Call [FwpmEngineOpen0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmengineopen0) to open a session to the filter engine.

### `enumTemplate` [in, optional]

Type: **const [IPSEC_SA_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_context_enum_template0)***

Template to selectively restrict the enumeration.

### `enumHandle` [out]

Type: **HANDLE***

Address of a **HANDLE** variable. On function return, it contains the handle for SA context enumeration.

## Return value

Type: **DWORD**

| Return code/value | Description |
| --- | --- |
| **ERROR_SUCCESS**<br><br>0 | The enumerator was created successfully. |
| **FWP_E_* error code**<br><br>0x80320001—0x80320039 | A Windows Filtering Platform (WFP) specific error. See [WFP Error Codes](https://learn.microsoft.com/windows/desktop/FWP/wfp-error-codes) for details. |
| **RPC_* error code**<br><br>0x80010001—0x80010122 | Failure to communicate with the remote or local firewall engine. |

## Remarks

If *enumTemplate* is **NULL**, all IPsec SA objects are returned.

The caller must call [IPsecSaContextDestroyEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextdestroyenumhandle0) to free the returned handle.

The caller needs [FWPM_ACTRL_ENUM](https://learn.microsoft.com/windows/desktop/FWP/access-right-identifiers) and **FWPM_ACTRL_READ** access to the IPsec security associations database. See [Access Control](https://learn.microsoft.com/windows/desktop/FWP/access-control) for more information.

**IPsecSaContextCreateEnumHandle0** is a specific implementation of IPsecSaContextCreateEnumHandle. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[IPSEC_SA_CONTEXT_ENUM_TEMPLATE0](https://learn.microsoft.com/windows/win32/api/ipsectypes/ns-ipsectypes-ipsec_sa_context_enum_template0)

[IPsecSaContextDestroyEnumHandle0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-ipsecsacontextdestroyenumhandle0)