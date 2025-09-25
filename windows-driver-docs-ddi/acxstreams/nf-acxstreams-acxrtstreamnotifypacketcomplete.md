## Description

The driver calls **AcxRtStreamNotifyPacketComplete** when a packet has completed. The packet completion time and the 0-based Packet index are included to improve client performance. The ACX framework will set any notification events associated with the stream.

## Parameters

### `Stream`

An existing ACXSTREAM Object. An ACXSTREAM object represents an audio stream created by a circuit. The stream is composed of a list of elements created based on the parent circuit's elements.

### `CompletedPacket`

A 0-based Packet index indicating the packet that was just completed.

### `QPCCompletion`

The packet completion time, as returned by [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter). This value should be as close as possible to the actual hardware completion (for example, the driver can call KeQueryPerformanceCounter from in its Interrupt Service Routine).

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

AcxRtStreamNotifyPacketComplete must be called at DISPATCH_LEVEL or below.

### Example

Example usage is shown below.

```cpp
completedPacket = (ULONG)InterlockedIncrement((LONG*)&m_CurrentPacket) - 1;

InterlockedExchange64(&m_LastPacketStart.QuadPart, m_CurrentPacketStart.QuadPart);
InterlockedExchange64(&m_CurrentPacketStart.QuadPart, QPC.QuadPart);

// Tell ACX we've completed the packet.
(void)AcxRtStreamNotifyPacketComplete(m_Stream, completedPacket, QPC.QuadPart);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)