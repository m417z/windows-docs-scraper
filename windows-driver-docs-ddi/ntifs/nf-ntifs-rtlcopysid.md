# RtlCopySid function

## Description

The **RtlCopySid** routine copies the value of a security identifier (SID) to a buffer.

## Parameters

### `DestinationSidLength` [in]

Length, in bytes, of the buffer to receive the copy of the SID.

### `DestinationSid` [in]

Pointer to a caller-allocated buffer to receive a copy of the source SID structure. The buffer must be at least **sizeof**(SID),

### `SourceSid` [in]

Pointer to the source SID structure to be copied.

## Return value

**RtlCopySid** returns STATUS_SUCCESS if the SID was successfully copied. Otherwise, it returns an NTSTATUS value such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_BUFFER_TOO_SMALL** | The *DestinationSid* buffer was not large enough to receive a copy of the SID. |

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Windows SDK.

## See also

[RtlEqualPrefixSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalprefixsid)

[RtlEqualSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlequalsid)

[RtlLengthSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtllengthsid)

[RtlValidSid](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-rtlvalidsid)

[SID](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_sid)