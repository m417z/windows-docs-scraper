# IDebugClient2::GetRunningProcessDescription

## Description

The **GetRunningProcessDescription** method returns a description of the process that includes the executable image name, the service names, the MTS package names, and the command line.

## Parameters

### `Server` [in]

Specifies the process server to query for the process description. If *Server* is zero, the engine will query information about the local process directly.

### `SystemId` [in]

Specifies the process ID of the process whose description is desired.

### `Flags` [in]

Specifies a bit-set containing options that affect the behavior of this method. *Flags* can contain the following bit flags:

| Flag | Description |
| --- | --- |
| DEBUG_PROC_DESC_NO_PATHS | Return only file names without path names. |
| DEBUG_PROC_DESC_NO_SERVICES | Do not look up service names. |
| DEBUG_PROC_DESC_NO_MTS_PACKAGES | Do not look up MTS package names. |
| DEBUG_PROC_DESC_NO_COMMAND_LINE | Do not retrieve the command line. |

### `ExeName` [out, optional]

Receives the name of the executable file used to start the process. If *ExeName* is **NULL**, this information is not returned.

### `ExeNameSize` [in]

Specifies the size in characters of the buffer *ExeNameSize*. This size includes the space for the '\0' terminating character.

### `ActualExeNameSize` [out, optional]

Receives the size in characters of the executable file name. This size includes the space for the '\0' terminating character. If *ExeNameSize* is **NULL**, this information is not returned.

### `Description` [out, optional]

Receives extra information about the process, including service names, MTS package names, and the command line. If *Description* is **NULL**, this information is not returned.

### `DescriptionSize` [in]

Specifies the size in characters of the buffer *Description*. This size includes the space for the '\0' terminating character.

### `ActualDescriptionSize` [out, optional]

Receives the size in characters of the extra information. This size includes the space for the '\0' terminating character. If *ActualDescriptionSize* is **NULL**, this information is not returned.

## Return value

This method may also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **S_FALSE** | The method was successful. However, either *ExeNameSize* or *DescriptionSize* were smaller than the size of the respective string and the string was truncated to fit inside the buffer. |

## Remarks

This method is available only for live user-mode debugging.

For more information about creating and attaching to live user-mode targets, see [Live User-Mode Targets](https://learn.microsoft.com/windows-hardware/drivers/debugger/live-user-mode-targets).

## See also

[AttachProcess](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-attachprocess)

[ConnectProcessServer](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-connectprocessserver)

[CreateProcessAndAttach2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-createprocessandattach2)

[GetRunningProcessSystemIdByExecutableName](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemidbyexecutablename)

[GetRunningProcessSystemIds](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nf-dbgeng-idebugclient5-getrunningprocesssystemids)

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)

[IDebugClient2](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient2)

[IDebugClient3](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient3)

[IDebugClient4](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient4)

[IDebugClient5](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient5)