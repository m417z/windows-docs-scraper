# PDEBUG_EXTENSION_UNLOAD callback function

## Description

The *DebugExtensionUnload* callback function unloads the debug extension.

```cpp
 CALLBACK* PDEBUG_EXTENSION_UNLOAD DebugExtensionUnload;
```

## Remarks

If and only if [DebugExtensionCanUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_canunload) is present in the debugger extension, this callback function is called after a successful *DebugExtensionCanUnload* call, immediately before the debugger actually unloads the extension DLL.

*DebugExtensionUnload* is called **PDEBUG_EXTENSION_UNLOAD** in the Dbgeng.h header file.

## See also

[DebugExtensionCanUnload](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_canunload)