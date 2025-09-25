# FwpsAleEndpointSetSecurityInfo0 function

## Description

The
**FwpsAleEndpointSetSecurityInfo0** function sets security information about the application layer
enforcement (ALE) endpoint enumeration session.

**Note** **FwpsAleEndpointSetSecurityInfo0** is a specific version of **FwpsAleEndpointSetSecurityInfo**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Parameters

### `engineHandle` [in]

A handle for an open session with the filter engine. This handle is obtained when a session is
opened by calling
[FwpmEngineOpen0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpmk/nf-fwpmk-fwpmengineopen0).

### `securityInfo` [in]

A set of security information flags. For more information, see the
[SECURITY_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ifs/security-information) description in the
Installable File Systems driver documentation.

### `sidOwner` [in, optional]

The security identifier of the security owner.

### `sidGroup` [in, optional]

The security identifier of the security group.

### `dacl` [in, optional]

The discretionary access control list.

### `sacl` [in, optional]

The system access control list.

## Return value

The
**FwpsAleEndpointSetSecurityInfo0** function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The function succeeded. |
| **Other status codes** | An error occurred. |

## See also

[FwpsAleEndpointEnum0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointenum0)

[FwpsAleEndpointGetById0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointgetbyid0)

[FwpsAleEndpointGetSecurityInfo0](https://learn.microsoft.com/windows-hardware/drivers/ddi/fwpsk/nf-fwpsk-fwpsaleendpointgetsecurityinfo0)