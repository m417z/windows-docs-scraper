# IDebugControl4::GetSystemVersionStringWide

## Description

The **GetSystemVersionStringWide** method returns a string that describes the target's operating system version.

## Parameters

### `Which` [in]

Specifies which version string to return. The possible values are listed in the following table.

| Value | Version string |
| --- | --- |
| DEBUG_SYSVERSTR_SERVICE_PACK | Returns a description of the service pack for the target's operating system. For example, "Service Pack 1". |
| DEBUG_SYSVERSTR_BUILD | Returns a description of the target's operating system build version. For example, "kernel32.dll version: 5.1.2600.1106 (xpsp1.020828-1920)". |

### `Buffer` [out, optional]

Receives the version string. If *Buffer* is **NULL**, this information is not returned.

### `BufferSize` [in]

Specifies the size, in characters, of the buffer that *Buffer* specifies. This size includes the space for the '\0' terminating character.

### `StringSize` [out, optional]

Receives the size, in characters, of the string that identifies the build. This size includes the space for the '\0' terminating character. If *SizeString* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was too small, so the string was truncated. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetSystemVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getsystemversion)

[GetSystemVersionValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getsystemversionvalues)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)