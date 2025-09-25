# IDebugControl2::GetSystemVersion

## Description

The **GetSystemVersion** method returns information that identifies the operating system on the computer that is running the current target.

## Parameters

### `PlatformId` [out]

Receives the platform ID. *PlatformId* is always VER_PLATFORM_WIN32_NT for NT-based Windows.

### `Major` [out]

Receives 0xF if the target's operating system is a [free build](https://learn.microsoft.com/windows-hardware/drivers/), or 0xC if the operating system is a [checked build](https://learn.microsoft.com/windows-hardware/drivers/).

### `Minor` [out]

Receives the build number for the target's operating system.

### `ServicePackString` [out, optional]

Receives the string for the service pack level of the target computer. If *ServicePackString* is **NULL**, this information is not returned. If no service pack is installed, *ServicePackString* can be empty.

### `ServicePackStringSize` [in]

Specifies the size, in characters, of the buffer that *ServicePackString* specifies. This size includes the space for the '\0' terminating character.

### `ServicePackStringUsed` [out, optional]

Receives the size, in characters, of the string of the service pack level. This size includes the space for the '\0' terminating character. If *ServicePackStringUsed* is **NULL**, this information is not returned.

### `ServicePackNumber` [out]

Receives the service pack level of the target's operating system.

### `BuildString` [out, optional]

Receives the string that identifies the build of the system. If *BuildString* is **NULL**, this information is not returned.

### `BuildStringSize` [in]

Specifies the size, in characters, of the buffer that *BuildString* specifies. This size includes the space for the '\0' terminating character.

### `BuildStringUsed` [out, optional]

Receives the size, in characters, of the string that identifies the build. This size includes the space for the '\0' terminating character. If *BuildStringUsed* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the *ServicePackString* buffer or the *BuildString* buffer were too small and the corresponding string was truncated. |

## Remarks

For more information, see [Target Information](https://learn.microsoft.com/windows-hardware/drivers/debugger/target-information).

## See also

[GetSystemVersionString](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getsystemversionstring)

[GetSystemVersionValues](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugcontrol4-getsystemversionvalues)

[IDebugControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol)

[IDebugControl2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol2)

[IDebugControl3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugcontrol3)