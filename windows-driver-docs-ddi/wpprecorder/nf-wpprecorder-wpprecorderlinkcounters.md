# WppRecorderLinkCounters macro

## Description

The **WppRecorderLinkCounters** method uses a sequence number to merge logs captured in different buffers by a driver.

## Syntax

```cpp
__drv_maxIRQL(DISPATCH_LEVEL)
NTSTATUS
WppRecorderLinkCounters(
    _In_
        WPP_RECORDER_COUNTER        CounterOwner
    );
```

## Parameters

### `CounterOwner` [in]

ID of the counter whose current value is to be read.

## Remarks

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, one of appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) values