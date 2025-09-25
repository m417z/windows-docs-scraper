# PDEBUG_EXTENSION_INITIALIZE callback function

## Description

The **DebugExtensionInitialize** callback function is called by the engine after loading a DbgEng extension DLL.

```cpp
 CALLBACK* PDEBUG_EXTENSION_INITIALIZE DebugExtensionInitialize;
```

## Parameters

### `Version` [out]

Receives the version of the extension. The high 16 bits contain the major version number, and the low 16 bits contain the minor version number.

### `Flags` [out]

Set this to zero. (Reserved for future use.)

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The extension was successfully initialized. |

Any other value indicates that the extension DLL was unable to initialize and the engine will unload it.

## Remarks

The engine looks for this function by name in each extension DLL. This function must be exported by a DbgEng extension DLL.

The version number can be set by using the macro DEBUG_EXTENSION_VERSION found in dbgeng.h, for example:

```
*Version = DEBUG_EXTENSION_VERSION(Major, Minor)
```

Implementations of this function should initialize any global variables required by the extension DLL.

There may or may not be a session active when this function is called, so the extension should not assume that it is able to query session information.

 The function type is defined as PDEBUG_EXTENSION_INITIALIZE in dbgeng.h.

## See also

[DebugExtensionNotify](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_notify)

[DebugExtensionUninitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_uninitialize)

[KnownStructOutput](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgeng/nc-dbgeng-pdebug_extension_known_struct)