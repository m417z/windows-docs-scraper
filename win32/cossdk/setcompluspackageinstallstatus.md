# SetComPlusPackageInstallStatus function

Sets a value indicating whether the 64-bit Common Language Runtime (CLR) is installed.

## Parameters

### ComPlusPackage

A **ULONG** with one of the following values.

| Value | Description |
|-------|-------------|
| 0 | The 32-bit Common Language Runtime (CLR) is installed. |
| 0x00000001 | The 64-bit Common Language Runtime (CLR) is installed. |

## Return value

**TRUE** is the call was successful; otherwise, **FALSE**.

## Remarks

This function is not defined in an SDK header and must be declared by the caller. This function is exported from kernel32.dll.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client | Windows 10 |
| Minimum supported server | Windows 10 |
| DLL | wldp.dll |

## See also

