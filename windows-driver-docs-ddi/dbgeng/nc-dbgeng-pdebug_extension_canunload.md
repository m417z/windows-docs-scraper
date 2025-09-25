# PDEBUG_EXTENSION_CANUNLOAD callback function

## Description

The *DebugExtensionCanUnload* callback function checks whether a debug extension can unload after the uninitialization call.

```cpp
 CALLBACK* PDEBUG_EXTENSION_CANUNLOAD DebugExtensionCanUnload;
```

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The extension was successfully initialized. |

Any other value indicates that the extension DLL was unable to initialize and the engine will unload it.

## Remarks

If present, this callback function is called between the [DebugExtensionUninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_uninitialize) callback function and actual unload of the DLL. The extension should return either **S_OK**, if no objects are present which would prevent unload of the extension, or **S_FALSE**, if there are still outstanding references to model objects in the debugger extension.

This callback function is the debugger's equivalent of [DllCanUnloadNow](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-dllcanunloadnow) for extensions which manipulate the object model of the debugger.

*DebugExtensionCanUnload* is called **PDEBUG_EXTENSION_CANUNLOAD** in the Dbgeng.h header file.

## See also

[DebugExtensionUninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_uninitialize)

[DllCanUnloadNow](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-dllcanunloadnow)