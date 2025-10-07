# ResolveDelayLoadedAPI function

Locates the target function of the specified import and replaces the function pointer in the import thunk with the target of the function implementation.

## Parameters

*ParentModuleBase* \[in\]

The address of the base of the module importing a delay-loaded function.

*DelayloadDescriptor* \[in\]

The descriptor for the module to be loaded.

*FailureDllHook* \[in, optional\]

The address of the failure hook.

*FailureSystemHook* \[in, optional\]

The address of the system failure hook. See [**DelayLoadFailureHook**](https://learn.microsoft.com/windows/win32/devnotes/delayloadfailurehook).

*ThunkAddress* \[out\]

The thunk data for the target function. Used to find the specific name table entry of the function.

*Flags*

Reserved; must be 0.

## Return value

The address of the import, or the failure stub for it.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Library<br> | Kernel32.lib |
| DLL<br> | Kernel32.dll |

## See also

[Linker Support for Delay-Loaded DLLs](https://msdn.microsoft.com/library/151kt790(v=VS.71).aspx)

