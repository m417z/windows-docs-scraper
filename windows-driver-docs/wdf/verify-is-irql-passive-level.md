# VERIFY_IS_IRQL_PASSIVE_LEVEL macro

[Applies to KMDF only]

The **VERIFY_IS_IRQL_PASSIVE_LEVEL** macro breaks into the kernel debugger if the driver is not executing at IRQL = PASSIVE_LEVEL.

## Parameters

This macro has no parameters.

## Return value

None

## Remarks

The code for the **VERIFY_IS_IRQL_PASSIVE_LEVEL** macro is included in your driver's binary when you build your driver in a release configuration or a debug configuration.

The **VERIFY_IS_IRQL_PASSIVE_LEVEL** code breaks into a kernel debugger if one of the following is true:

- **DbgBreakOnError** is set to a non-zero value in the registry.
- **VerifierOn** is set to a non-zero value and **DbgBreakOnError** is not set.
- Driver Verifier is enabled, the driver was built with framework version 1.9 or later, and neither **VerifierOn** nor **DbgBreakOnError** is set.

For more information about registry entries that you can use to debug your driver, see [Registry Entries for Debugging Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/registry-values-for-debugging-kmdf-drivers).

For more information about debugging your driver, see [Debugging a KMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-universal-drivers---step-by-step-lab--echo-kernel-mode-).

## Examples

The following code example breaks into the kernel debugger if the driver is not executing at IRQL = PASSIVE_LEVEL.

```cpp
VERIFY_IS_IRQL_PASSIVE_LEVEL();
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.0 |
| Header | Wdfassert.h (include Wdf.h) |

## See also

[**WDFVERIFY**](https://learn.microsoft.com/windows-hardware/drivers/wdf/wdfverify)