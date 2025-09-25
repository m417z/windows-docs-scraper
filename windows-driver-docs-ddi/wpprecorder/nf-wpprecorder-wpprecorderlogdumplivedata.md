## Description

The **WppRecorderLogDumpLiveData** method returns an opaque pointer to a log buffer header and data so that they can be saved in a live crashdump.

## Syntax

```cpp
__drv_maxIRQL(HIGH_LEVEL)
NTSTATUS
WppRecorderLogDumpLiveData(
    _In_
        RECORDER_LOG         RecorderLog,
    _Out_ __deref_ecount(*OutBufferLength)
        PVOID              * OutBuffer,
    _Out_
        PULONG               OutBufferLength,
    _Out_
        LPGUID               Guid
    );
```

## Parameters

### `RecorderLog` [in]

A recorder log handle returned in a previous call to [**WppRecorderLogCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-wpprecorderlogcreate) or [**WppRecorderLogGetDefault**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wpprecorder/nf-wpprecorder-imp_wpprecorderloggetdefault).

### `OutBuffer` [out]

Pointer to the beginning of the combined header and log buffer.

### `OutBufferLength` [out]

Pointer to a ULONG that contains the length of the combined data.

### `Guid` [out]

Reserved.

## Remarks

Returns STATUS_SUCCESS if the operation succeeds. If not successful, the out parameters are invalid.

## See also