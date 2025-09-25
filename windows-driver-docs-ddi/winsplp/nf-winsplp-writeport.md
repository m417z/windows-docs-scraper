# WritePort function

## Description

A port monitor's `WritePort` function writes data to a printer port.

## Parameters

### `hPort` [in]

Caller-supplied port handle.

### `pBuffer` [in]

Caller-supplied pointer to a buffer containing data to be written to the port.

### `cbBuf`

Caller-supplied size, in bytes, of *pBuffer*.

### `pcbWritten` [out]

Caller-supplied pointer to a location to receive the number of bytes successfully written to the port.

## Return value

If the operation succeeds, the function should return **TRUE**. Otherwise it should return **FALSE**.

## Syntax

```cpp
BOOL WritePort(
  _In_  HANDLE  hPort,
  _In_  LPBYTE  pBuffer,
        DWORD   cbBuf,
  _Out_ LPDWORD pcbWritten
);
```

## Remarks

[Language monitors](https://learn.microsoft.com/windows-hardware/drivers/print/language-monitors) and port monitor server DLLs are required to define a `WritePort` function and include the function's address in a [MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2) structure.

The handle received as the function's *hPort* argument is the port handle that the monitor's [OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport) or [OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85)) function supplied.

Typically, a language monitor's `WritePort` function adds language-specific commands to the data stream contained in the buffer pointed to by *pBuffer*, and then passes the modified data stream to the port monitor's `WritePort` function.

A port monitor server DLL's `WritePort` function usually calls **WriteFile** (described in the Microsoft Windows SDK documentation) to send the data stream to the kernel-mode port driver.

A typical print job consists of multiple calls to `WritePort`. Each call can have a different *cbBuf* value.

The function should return the number of bytes successfully written by placing the number in the location pointed to by *pcbWritten*. For language monitors, this number must not include the number of extra, language-specific bytes added to the data stream.

The spooler determines the success or failure of the write operation by checking `WritePort`'s return value, not the returned byte count. So a returned byte count of zero does not represent a failed write unless the function returns **FALSE**.

Some sort of system-implemented or monitor-implemented time-out mechanism must ensure that the `WritePort` function will return within a reasonable amount of time, to avoid stalling the spooler.

It is acceptable for a language monitor to call a port monitor's `WritePort` routine outside of a [StartDocPort](https://learn.microsoft.com/previous-versions/ff562710(v=vs.85))/[EndDocPort](https://learn.microsoft.com/previous-versions/ff548742(v=vs.85)) pair. However, some port monitors might fail such a call, so the language monitor must be written to handle this failure.

## See also

[StartDocPort](https://learn.microsoft.com/previous-versions/ff562710(v=vs.85))

[OpenPortEx](https://learn.microsoft.com/previous-versions/ff559596(v=vs.85))

[OpenPort](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/nf-winsplp-openport)

[MONITOR2](https://learn.microsoft.com/windows-hardware/drivers/ddi/winsplp/ns-winsplp-_monitor2)

[EndDocPort](https://learn.microsoft.com/previous-versions/ff548742(v=vs.85))