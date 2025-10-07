# ResolveDelayLoadsFromDll function

Forwards the work in resolving delay-loaded imports from the parent binary to a target binary.

## Parameters

*ParentBase* \[in\]

The base address of the module that delay loads another binary.

*TargetDllName* \[in\]

The name of the target DLL.

*Flags*

Reserved; must be 0.

## Return value

Returns an **NTSTATUS** or error code.

| Return code | Description |
|--------------|--------------|
| STATUS_SUCCESS | The operation completed successfully |
| STATUS_DLL_NOT_FOUND | The Target DLL could not be found |

The forms and significance of **NTSTATUS** error codes are listed in the Ntstatus.h header file available in the WDK, and are described in the WDK documentation.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Library<br> | Kernel32.lib |
| DLL<br> | Kernel32.dll |

## See also

[Linker Support for Delay-Loaded DLLs](https://msdn.microsoft.com/library/151kt790(v=VS.71).aspx)

