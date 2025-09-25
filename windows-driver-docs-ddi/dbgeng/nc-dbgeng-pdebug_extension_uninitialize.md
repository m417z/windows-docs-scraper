# PDEBUG_EXTENSION_UNINITIALIZE callback function

## Description

The **DebugExtensionUninitialize** callback function is called by the engine to uninitialize the DbgEng extension DLL before it is unloaded.

```
 CALLBACK* PDEBUG_EXTENSION_UNINITIALIZE DebugExtensionUninitialize;
```

## Remarks

This function is optional. A DbgEng extension DLL only needs to export **DebugExtensionUninitialize** if it needs to be notified before it is unloaded. The engine looks for this function by name in the extension DLL.

This function can be used by the extension DLL to clean up before it is unloaded.

There may or may not be a session active when this function is called, so the extension should not assume that it is able to query session information.

DebugExtensionUninitialize is called **PDEBUG_EXTENSION_UNINITIALIZE** in the Dbgeng.h header file.

## See also

[DebugExtensionInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_initialize)