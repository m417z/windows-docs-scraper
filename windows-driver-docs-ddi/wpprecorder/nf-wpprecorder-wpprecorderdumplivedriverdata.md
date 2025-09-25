# WppRecorderDumpLiveDriverData macro

## Description

The [WppRecorderDumpLiveDriverData](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderdumplivedriverdata) method gets the buffer associated with the specified Inflight Trace Recorder log.

## Syntax

```cpp
__drv_maxIRQL(HIGH_LEVEL)
NTSTATUS
WppRecorderDumpLiveDriverData(
    _Out_ __deref_ecount(*OutBufferLength)
        PVOID              * OutBuffer,
    _Out_
        PULONG               OutBufferLength,
    _Out_
        LPGUID               Guid
    );
```

## Parameters

### `OutBuffer` [out]

Pointer to the buffer that was allocated by WppRecorderLogCreate.

### `OutBufferLength` [out]

Pointer to a ULONG that contains the size of the output buffer pointed to by OutBuffer.

### `Guid` [out]

Pointer to the WPP controller GUID that identifies the driver data.

## Remarks

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, one of appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) values