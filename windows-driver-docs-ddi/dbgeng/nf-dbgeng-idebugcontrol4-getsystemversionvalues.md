# IDebugControl4::GetSystemVersionValues

## Description

The **GetSystemVersionValues** method returns version number information for the current target.

## Parameters

### `PlatformId` [out]

Receives the platform ID. *PlatformId* is always VER_PLATFORM_WIN32_NT for NT-based Windows.

### `Win32Major` [out]

Receives the major version number of the target's operating system. For Windows 2000, Windows XP, and Windows Server 2003, this number is 5. For Windows Vista, Windows 7, and Windows 8, this number is 6.

### `Win32Minor` [out]

Receives the minor version number for the target's operating system. For Windows 2000 this is 0; for Windows XP, 1; for Windows Server 2003, 2. For Windows Vista, this is 0; for Windows 7, 1; for Windows 8, 2.

### `KdMajor` [out, optional]

Receives 0xF if the target's operating system is a free build, and 0xC if it is a checked build.

### `KdMinor` [out, optional]

Receives the build number for the target's operating system.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetSystemVersion](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol3-getsystemversion)

[GetSystemVersionString](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getsystemversionstring)

[IDebugControl4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol4)