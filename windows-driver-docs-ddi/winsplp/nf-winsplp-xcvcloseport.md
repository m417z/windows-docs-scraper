# XcvClosePort function

## Description

A port monitor server DLL's `XcvClosePort` function closes a printer port that was opened by [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport).

## Parameters

### `hXcv` [in]

Caller-supplied printer handle obtained by calling **OpenPrinter** (described in the Microsoft Windows SDK documentation). This handle is created and returned by [XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport).

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise it should return **FALSE**.

## Syntax

```cpp
BOOL XcvClosePort(
  _In_ HANDLE hXcv
);
```

## Remarks

Port monitor server DLLs are required to define an `XcvClosePort` function and include its address in a [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The spooler's **ClosePrinter** function calls `XcvClosePort` if the printer name that was specified with a previous call to the **OpenPrinter** function included either of the strings "XcvPort" or "XcvMonitor". For more information, see [AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui). For more information about the **OpenPrinter** and **ClosePrinter** functions, see the Windows SDK documentation.

The function should close the port specified by the handle, and it should make the handle invalid.

## See also

[XcvOpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-xcvopenport)

[AddPortUI](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-addportui)