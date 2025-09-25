# wiauDbgLegacyHresult2 function

## Description

The **wiauDbgLegacyHresult2** function logs a default message containing an HRESULT.

## Parameters

### `hInstance` [in]

Specifies the handle to the DLL instance.

### `hr`

Specifies the HRESULT to be logged.

## Remarks

A call to the **wiauDbgLegacyHresult2** function is equivalent to the following call to the [wiauDbgErrorHr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerrorhr) function:

```cpp
wiauDbgErrorHr(hr, "", "");
```

That is, only one line is output to the log file and/or debugger. The line has the following form:

```cpp
ERROR HRESULT = HRESULT value, Error text for HRESULT
```

## See also

[wiauDbgErrorHr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wiautil/nf-wiautil-wiaudbgerrorhr)