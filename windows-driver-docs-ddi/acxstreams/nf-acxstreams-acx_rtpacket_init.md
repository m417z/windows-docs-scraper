## Description

The **ACX_RTPACKET_INIT** function initializes the ACX RT packet structure.

## Parameters

### `RtPacket`

An [ACX_RTPACKET](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/ns-acxstreams-acx_rtpacket) structure.
## Remarks

### Example

```cpp
    packets = (PACX_RTPACKET)ExAllocatePool2(POOL_FLAG_NON_PAGED, packetsSize, DRIVER_TAG);
    RETURN_NTSTATUS_IF_TRUE(!packets, STATUS_NO_MEMORY);

    ...

        ACX_RTPACKET_INIT(&packets[i]);
```

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxstreams.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxstreams/)