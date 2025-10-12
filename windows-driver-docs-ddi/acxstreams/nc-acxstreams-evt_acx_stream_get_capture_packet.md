## Description

**EvtAcxStreamGetCapturePacket** tells the driver to indicate which packet (0-based) was completely filled most recently, including the QPC value at the time the driver started filling the packet.

## Parameters

### `Stream`

An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements. For more information, see [ACX - Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `LastCapturePacket`

A value indicating the position of the last captured packet. This is a 0-based index indicating how many complete packets of data have been captured.

### `QPCPacketStart`

A value indicating the start time of the last captured packet.

### `MoreData`

Returns TRUE if there is more data ready immediately. The OS may optionally immediately call this routine again after processing the packet to get the next packet information. If the driver returns FALSE, then capture is operating at real time.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

Before reading captured audio data from the audio buffer, the OS calls this routine to get information about the available data.

The packet number identifies a packet within the stream. This resets to zero when [EVT_ACX_STREAM_RELEASE_HARDWARE](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nc-acxstreams-evt_acx_stream_release_hardware) has been called for the stream. The number advances with each captured buffer. From the packet number the OS can derive the packet location within the audio buffer and can also derive the stream position of the packet relative to start of stream.

The OS may call this routine at any time. In normal operation, the OS calls this routine after the driver calls [AcxRtStreamNotifyPacketComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/nf-acxstreams-acxrtstreamnotifypacketcomplete) or after a previous call returns true for MoreData. When the OS calls this routine, the driver may assume that the OS has finished reading all previous packets. If the hardware has captured enough data, the driver may immediately burst the next complete packet to the audio buffer and call AcxRtStreamNotifyPacketComplete again. In the case of capture overflow (when the OS does not read data quickly enough) the audio driver may drop or overwrite some audio data. The audio driver drops or overwrites oldest data first. The audio driver may continue to advance its internal packet counter even though the OS may not have read the data.

### Example

Example usage is shown below.

```cpp
#pragma code_seg("PAGE")
NTSTATUS
CodecC_EvtStreamGetCapturePacket(
    _In_ ACXSTREAM          Stream,
    _Out_ ULONG           * LastCapturePacket,
    _Out_ ULONGLONG       * QPCPacketStart,
    _Out_ BOOLEAN         * MoreData
)
{
    PCODEC_STREAM_CONTEXT ctx;
    CCaptureStreamEngine* streamEngine = nullptr;
    ULONG currentPacket;
    LONGLONG qpcPacketStart;

    PAGED_CODE();

    ctx = GetCodecStreamContext(Stream);
    // Retrieve the current packet that is being written to by the audio hardware
    currentPacket = (ULONG)InterlockedCompareExchange((LONG*)&ctx->CurrentPacket, -1, -1);
    qpcPacketStart = InterlockedCompareExchange64(&ctx->LastPacketStart.QuadPart, -1, -1);

    // The Last capture packet is the packet before the current packet.
    *LastCapturePacket = currentPacket - 1;
    *QPCPacketStart = (ULONGLONG)qpcPacketStart;
    *MoreData = FALSE;

    return STATUS_SUCCESS;
}
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)