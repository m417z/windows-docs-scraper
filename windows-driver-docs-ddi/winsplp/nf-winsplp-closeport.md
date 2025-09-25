# ClosePort function

## Description

A language or port monitor's **ClosePort** function closes a printer port.

## Parameters

### `hPort` [in]

Caller-supplied pointer to a port handle.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise it should return **FALSE**.

## Syntax

```cpp
BOOL ClosePort(
  _In_ HANDLE hPort
);
```

## Remarks

[Language monitors](https://learn.microsoft.com/windows-hardware/drivers/print/language-monitors) and port monitor server DLLs are required to define a **ClosePort** function and include the function's address in a [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The handle received as the function's *hPort* argument is the port handle that the monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) or [OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85)) function supplied.

The **ClosePort** function should close the port by making the received port handle invalid. It should also free all system resources that were allocated by the monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) or [OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85)) function.

## See also

[OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85))

[MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2)

[OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport)