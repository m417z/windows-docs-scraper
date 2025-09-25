# RtlCopyLuid function

## Description

The **RtlCopyLuid** routine copies a locally unique identifier (LUID) to a buffer.

## Parameters

### `DestinationLuid` [out]

Pointer to a caller-allocated buffer to receive a copy of the source LUID structure. The buffer must be at least **sizeof(**LUID**)**.

### `SourceLuid` [in]

Pointer to the source LUID structure to be copied.

## Return value

None

## Remarks

**RtlCopyLuid** does not check whether the LUID at *SourceLuid* is structurally valid.

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[LUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/igpupvdev/ns-igpupvdev-_luid)

[RtlEqualLuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-rtlequalluid)

[SeQueryAuthenticationIdToken](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequeryauthenticationidtoken)