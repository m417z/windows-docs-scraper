# IDebugRegisters::GetDescription

## Description

The **GetDescription** method returns the description of a register.

## Parameters

### `Register` [in]

Specifies the index of the register for which the description is requested.

### `NameBuffer` [out, optional]

Specifies the buffer in which to store the name of the register. If *NameBuffer* is **NULL**, this information is not returned.

### `NameBufferSize` [in]

Specifies the size, in characters, of the buffer that *NameBuffer* specifies. This size includes the space for the '\0' terminating character.

### `NameSize` [out, optional]

Receives the size, in characters, of the register's name in *NameBuffer* buffer. This size includes the space for the '\0' terminating character. If *NameSize* is **NULL**, this information is not returned.

### `Desc` [out, optional]

Receives the description of the register. See [DEBUG_REGISTER_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_register_description) for more details.

## Return value

This list does not contain all the errors that might occur. For a list of possible errors, see [HRESULT Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values).

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the buffer was not large enough to hold the register's name, so it was truncated. |
| **E_UNEXPECTED** | No target machine has been specified, or a description of the register could not be found. |
| **E_INVALIDARG** | The index of the register requested is greater than the total number of registers on the target's machine. |

## Remarks

For an overview of the [IDebugRegisters](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugregisters) interface and other register-related methods, see [Registers](https://learn.microsoft.com/windows-hardware/drivers/debugger/registers).