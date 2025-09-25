# KSALLOCATOR_FRAMING_EX structure

## Description

The KSALLOCATOR_FRAMING_EX structure is the AVStream replacement for KSALLOCATOR_FRAMING. KSALLOCATOR_FRAMING_EX defines allocator requirements on a pin in a kernel level filter.

## Members

### `CountItems`

Specifies the number of framing items that are present in the **FramingItem** array.

### `PinFlags`

Reserved, set to zero.

### `OutputCompression`

Points to a structure of type [KS_COMPRESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_compression) that defines the frame ratio for transforms that change the size of a frame.

### `PinWeight`

This pin framing's weight graph-wide. Reserved, set to zero.

### `FramingItem`

An array of [KS_FRAMING_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_item) structures specifying the actual framing items.

## Remarks

A minidriver can also use DECLARE_SIMPLE_FRAMING_EX to declare an extended framing structure in line with the original structure. This macro is defined in *Ks.h* as follows:

```cpp
#define DECLARE_SIMPLE_FRAMING_EX(FramingExName, MemoryType, Flags, Frames, Alignment, MinFrameSize, MaxFrameSize) const KSALLOCATOR_FRAMING_EX FramingExName
```

DECLARE_SIMPLE_FRAMING_EX declares a KSALLOCATOR_FRAMING_EX structure called **FramingExName** with the specified memory type (often either STATIC_KS_TYPE_DONT_CARE or one of the kernel paged or nonpaged GUIDs). The **Frames** and **Alignment** fields of the macro correspond to the [KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing). **MinFrameSize** and **MaxFrameSize** ensure that frames are within a specific size range. Flags corresponds to the **OptionsFlags** and **RequirementsFlags** in **KSALLOCATOR_FRAMING**.

## See also

[KSALLOCATOR_FRAMING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing)

[KS_COMPRESSION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_compression)

[KS_FRAMING_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_item)

[KS_FRAMING_RANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_range)

[KS_FRAMING_RANGE_WEIGHTED](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ks_framing_range_weighted)