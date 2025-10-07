# WDFVERIFY macro

\[Applies to KMDF only\]

The **WDFVERIFY** macro tests a logical expression and, if the expression evaluates to **FALSE**, breaks into the kernel debugger.

## Parameters

*exp*
A logical expression that WDFVERIFY tests.

## Return value

None

## Remarks

The code for the **WDFVERIFY** macro is included in your driver's binary when you build your driver in a release configuration or a debug configuration.

The **WDFVERIFY** code breaks into a kernel debugger only if the **VerifyOn** value is set in the registry. For more information about registry entries that you can use to debug your driver, see [Registry Entries for Debugging Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/registry-values-for-debugging-kmdf-drivers).

For more information about debugging your driver, see [Debugging a KMDF Driver](https://learn.microsoft.com/windows-hardware/drivers/debugger/debug-universal-drivers---step-by-step-lab--echo-kernel-mode-).

## Examples

The following code example breaks into the debugger if an attempt to reuse a request object fails.

```cpp
status = WdfRequestReuse(Request, &params);
WDFVERIFY(NT_SUCCESS(status));
```

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://go.microsoft.com/fwlink/p/?linkid=531356) |
| Minimum KMDF version | 1.0 |
| Header | Wdfassert.h (include Wdf.h) |

## See also

[**VERIFY_IS_IRQL_PASSIVE_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/wdf/verify-is-irql-passive-level)

