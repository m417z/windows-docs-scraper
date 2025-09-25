# DrvQueryDriverInfo function

## Description

The **DrvQueryDriverInfo** function returns requested driver-specific information.

## Parameters

### `dwMode`

Caller-supplied constant value, as indicated in the following table.

| Value | Definition |
| --- | --- |
| DRVQUERY_USERMODE | The caller is querying whether the driver executes in user mode or in kernel mode. |

### `pBuffer` [out]

Caller-supplied pointer to a buffer to receive requested information. The function must supply the following information:

| *dwMode* Value | *pBuffer* Size | Value supplied by **DrvQueryDriverInfo** |
| --- | --- | --- |
| DRVQUERY_USERMODE | One DWORD | **TRUE** if driver executes in user mode; **FALSE** otherwise. |

### `cbBuf`

Caller-supplied value representing the size, in bytes, of the buffer pointed to by *pBuffer*.

### `pcbNeeded` [out]

Caller-supplied pointer to a location to receive the minimum buffer size, in bytes, required to contain the requested information.

## Return value

If the operation succeeds, the function should return **TRUE**; otherwise it should return **FALSE**.

## Remarks

[Printer graphics DLLs](https://learn.microsoft.com/windows-hardware/drivers/print/printer-graphics-dll) that execute in user mode must export a **DrvQueryDriverInfo** function. If the function is not exported, the [local print provider](https://learn.microsoft.com/windows-hardware/drivers/print/local-print-provider) assumes the graphics DLL executes in kernel mode.