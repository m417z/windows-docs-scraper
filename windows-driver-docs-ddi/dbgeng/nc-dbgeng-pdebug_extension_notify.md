# PDEBUG_EXTENSION_NOTIFY callback function

## Description

The engine calls the **DebugExtensionNotify** callback function to inform the extension [DLL](https://learn.microsoft.com/windows-hardware/drivers/) when a session changes its active or accessible status.

```cpp
 CALLBACK* PDEBUG_EXTENSION_NOTIFY DebugExtensionNotify;
```

## Parameters

### `Notify` [in]

Can be any of the following values:

| Value | Description |
| --- | --- |
| DEBUG_NOTIFY_SESSION_ACTIVE | A debugging session is active. The session may not necessarily be suspended. |
| DEBUG_NOTIFY_SESSION_INACTIVE | No debugging session is active. |
| DEBUG_NOTIFY_SESSION_ACCESSIBLE | The debugging session has suspended and is now accessible. |
| DEBUG_NOTIFY_SESSION_INACCESSIBLE | The debugging session has started running and is now inaccessible. |

### `Argument` [in]

Set to zero. (Reserved for future use.)

## Remarks

This function is optional. A DbgEng extension DLL only needs to export **DebugExtensionNotify** if it wants to be notified when the session state changes. The engine looks for this function by name in the extension DLL.

This function allows the extension DLL to cache information about the session without needing to register explicit callbacks. It is called at the beginning and end of a session, and each time a target starts or stops executing.

After the extension DLL is initialized, the engine will use this function to notify the DLL if it has started a session. If the current session is suspended, the engine will call this function a second time to notify the DLL that the session is accessible.

## See also

[DebugExtensionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_initialize)