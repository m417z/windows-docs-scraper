# WppRecorderGetTriageInfo macro

## Description

The **WppRecorderGetTriageInfo** method returns the WPP log for WER reporting.

## Syntax

```cpp
__drv_maxIRQL(DISPATCH_LEVEL)
NTSTATUS WppRecorderGetTriageInfo(
  _Out_ PWPP_TRIAGE_INFO WppTriageInfo
);
```

## Parameters

### `WppTriageInfo` [out]

Pointer to a [WPP_TRIAGE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/ns-wpprecorder-_wpp_triage_info) structure.

## Remarks

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, one of appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) values