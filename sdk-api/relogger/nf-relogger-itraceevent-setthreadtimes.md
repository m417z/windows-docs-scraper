# ITraceEvent::SetThreadTimes (relogger.h)

## Description

Sets the thread times in the current thread.

## Parameters

### `KernelTime`

The time executed in kernel mode, in 100-nanosecond intervals.

### `UserTime`

The time executed in user mode, in 100-nanosecond intervals.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also