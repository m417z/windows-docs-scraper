# WdfVerifierKeBugCheck function

## Description

[Applies to KMDF and UMDF]

The **WdfVerifierKeBugCheck** function creates a bug check.

## Parameters

### `BugCheckCode` [in]

One of the [bug check codes](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-code-reference2) that are defined in *Bugcodes.h*.

### `BugCheckParameter1` [in]

For information about this parameter, see the specified bug check code's description.

### `BugCheckParameter2` [in]

For information about this parameter, see the specified bug check code's description.

### `BugCheckParameter3` [in]

For information about this parameter, see the specified bug check code's description.

### `BugCheckParameter4` [in]

For information about this parameter, see the specified bug check code's description.

## Remarks

If your Kernel-Mode Driver Framework (KMDF) driver calls **WdfVerifierKeBugCheck**, the operating system halts and displays a [blue screen](https://learn.microsoft.com/windows-hardware/drivers/debugger/blue-screen-data) unless a debugger is running. For more information, see [Getting Started with WinDbg - Kernel Mode](https://learn.microsoft.com/windows-hardware/drivers/debugger/getting-started-with-windbg--kernel-mode-).

If your User-Mode Driver Framework (UMDF) driver (version 2.0 or later) calls **WdfVerifierKeBugCheck**, the framework does not use the parameters that the driver supplies. In this case, the framework breaks into the debugger if one is connected. If a debugger is not connected, the framework generates an exception, and the default UMDF exception handler creates a minidump file. For more information about unhandled exceptions in the driver host process, see [How UMDF Reports Errors](https://learn.microsoft.com/windows-hardware/drivers/wdf/how-umdf-reports-errors).

For more information about debugging your driver, see [Debugging WDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/debugging-a-wdf-driver).

#### Examples

The following code example creates a bug check that uses the [MULTIPLE_IRP_COMPLETE_REQUESTS](https://learn.microsoft.com/windows-hardware/drivers/debugger/bug-check-0x44--multiple-irp-complete-requests) bug check code.

```cpp
WdfVerifierKeBugCheck(
                      MULTIPLE_IRP_COMPLETE_REQUESTS,
                      (ULONG_PTR) irp,
                      (ULONG_PTR) srb,
                      0,
                      0
                      );
```

## See also

[WdfVerifierDbgBreakPoint](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfverifier/nf-wdfverifier-wdfverifierdbgbreakpoint)