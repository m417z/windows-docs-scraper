# RtlInitializeSid function

## Description

The **RtlInitializeSid** routine initializes a security identifier (SID) structure.

## Parameters

### `Sid` [out]

Pointer to a caller-allocated SID structure to be initialized.

### `IdentifierAuthority` [in]

Pointer to an SID_IDENTIFIER_AUTHORITY structure to set in the SID structure.

### `SubAuthorityCount` [in]

Number of subauthorities to set in the SID. Subauthority values must be set separately, as described in the following Remarks section.

## Return value

**RtlInitializeSid** returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The SID was successfully initialized. |
| **STATUS_INVALID_PARAMETER** | The specified *SubAuthorityCount* value is invalid. |

## Remarks

Although **RtlInitializeSid** sets the number of subauthorities for the SID, it does not set the subauthority values. This must be done separately by calling **RtlSubAuthoritySid**.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlSubAuthoritySid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsubauthoritysid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_identifier_authority)