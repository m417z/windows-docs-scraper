# IDebugAdvanced3::GetSystemObjectInformation

## Description

The **GetSystemObjectInformation** method returns information about operating system objects on the target.

## Parameters

### `Which` [in]

Specifies the type of object and the type of information to return about that object. *Which* can take the following value.

| Value | Information returned |
| --- | --- |
| DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION | Returns details of the thread specified by engine thread ID. |

### `Arg64` [in]

Specifies a 64-bit argument. This parameter has the following interpretations depending on the value of *Which*:

#### DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION

Not used.

### `Arg32` [in]

Specifies a 32-bit argument. This parameter has the following interpretations depending on the value of *Which*:

#### DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION

The engine thread ID of the desired thread.

### `Buffer` [out, optional]

Receives the requested information. The type of data returned in *Buffer* depends on the value of *Which*.

| Value | Return type |
| --- | --- |
| DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION | [DEBUG_THREAD_BASIC_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/ns-dbgeng-_debug_thread_basic_information) |

### `BufferSize` [in]

Specifies the size, in bytes, of the buffer *Buffer*.

### `InfoSize` [out, optional]

Receives the size of the information that is returned.

##### - Arg32.DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION

The engine thread ID of the desired thread.

##### - Arg64.DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION

Not used.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, the information would not fit in the buffer *Buffer*, so the information was truncated. |

## See also

[IDebugAdvanced2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced2)

[IDebugAdvanced3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugadvanced3)

[IDebugSystemObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugsystemobjects)