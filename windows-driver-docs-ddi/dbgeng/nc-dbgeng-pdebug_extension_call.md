# PDEBUG_EXTENSION_CALL callback function

## Description

Callback functions of the type **PDEBUG_EXTENSION_CALL** are called by the engine to execute [extension commands](https://learn.microsoft.com/windows-hardware/drivers/debugger/anatomy-of-a-dbgeng-extension-dll). You can give these functions any name you want, as long as it contains no uppercase letters.

## Parameters

### `Client` [in]

Specifies an interface pointer to the client. This can be used to interact with the engine. Typically, this is the client through which the extension command was issued.

### `Args` [in, optional]

Specifies the arguments passed to the extension command. In particular, if the extension command was called from a command line, *Args* contains the rest of the command line. It can be **NULL** or empty.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The function was successful. |
| **DEBUG_EXTENSION_CONTINUE_SEARCH** | Indicates that the function cannot handle the command, or that other implementations of the same command in other extension DLLs should also run. The engine should continue searching other extension DLLs for another function to handle the command. For example, this can be used to have all help functions run if each one returns CONTINUE_SEARCH. |

All other return values are ignored by the engine.

## Remarks

The name of the function becomes the name of the extension command. When executing an extension command, the engine searches through each of the loaded extension DLLs in turn, looking for an exported function that has the same name as the command. For example, when executing the command **!stack**, the engine will look for an exported function named **stack** in each loaded extension DLL. For information about the order in which extension DLLs are searched, see [Using Debugger Extension Commands](https://learn.microsoft.com/windows-hardware/drivers/debugger/using-debugger-extension-commands).

The extension function should use the client that was passed to it in *Client* for all interaction with the engine, unless it has a specific reason to use another client. The extension function should not maintain the pointer to the client object after it has finished.

DebugExtensionCall is called **PDEBUG_EXTENSION_CALL** in the Dbgeng.h header file.

## See also

[IDebugClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nn-dbgeng-idebugclient)