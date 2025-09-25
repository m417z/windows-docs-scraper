# _HW_STREAM_HEADER structure

## Description

The HW_STREAM_HEADER structure describes the kernel streaming semantics supported by the minidriver as a whole, as part of a [HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor) structure.

## Members

### `NumberOfStreams`

The number of [HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information) structures that follow this header.

### `SizeOfHwStreamInformation`

The size, in bytes, of the HW_STREAM_INFORMATION structure.

### `NumDevPropArrayEntries`

The number of entries in the array pointed to by **DevicePropertiesArray**.

### `DevicePropertiesArray`

Pointer to the beginning of the array of property sets that the minidriver as a whole supports. (Property sets supported by individual streams can be found in the **StreamPropertiesArray** member of the stream's [HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information) structure.)

### `NumDevEventArrayEntries`

The number of entries in the array pointed to by **DeviceEventsArray**.

### `DeviceEventsArray`

Pointer to the beginning of the array of event sets supported by the minidriver.

### `Topology`

Pointer to the [KSTOPOLOGY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology) structure that describes the minidriver's internal topology of nodes and pins. The class driver uses this to handle the [KSPROPSETID_Topology](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-topology) property set for the minidriver.

### `DeviceEventRoutine`

Points to the minidriver's [StrMiniEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_event_routine) routine.

### `NumDevMethodArrayEntries`

### `DeviceMethodsArray`

### `Reserved`

Reserved for system use. Do not use.

## See also

[HW_STREAM_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor)

[HW_STREAM_INFORMATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_information)