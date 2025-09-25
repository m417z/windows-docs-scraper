# RtlInitializeSidEx function

## Description

The **RtlInitializeSidEx** routine initializes a pre-allocated security identifier (SID) structure.

## Parameters

### `Sid` [out]

Pointer to a caller-allocated SID structure to be initialized.

### `IdentifierAuthority` [in]

Pointer to an [SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_identifier_authority) structure to set in the SID structure.

### `SubAuthorityCount` [in]

Number of sub-authorities to set in the SID.

### `...`

The values to set each sub-authority. The caller must specify the SubAuthorityCount argument.

## Return value

**RtlInitializeSid** returns one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The SID was successfully initialized. |
| **STATUS_INVALID_PARAMETER** | The specified *SubAuthorityCount* value is invalid. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlSubAuthoritySid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlsubauthoritysid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)

[SID_IDENTIFIER_AUTHORITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid_identifier_authority)