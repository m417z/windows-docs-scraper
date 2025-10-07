# DelayLoadFailureHook function

Returns the address of a delay-load failure callback function for the specified DLL and process.

## Parameters

*pszDllName* \[in\]

The name of the DLL.

*pszProcName* \[in\]

The name of the procedure.

## Return value

The address of the callback function.

## Requirements

| Requirement | Value |
|--------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8<br> |
| Minimum supported server<br> | Windows Server 2012<br> |
| Library<br> | Kernel32.lib |
| DLL<br> | Kernel32.dll |

## See also

[Failure Hooks](https://msdn.microsoft.com/library/sfcfb0a3(v=VS.71).aspx)

