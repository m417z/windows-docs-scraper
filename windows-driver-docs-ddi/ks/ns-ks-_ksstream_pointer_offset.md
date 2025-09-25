# _KSSTREAM_POINTER_OFFSET structure

## Description

The KSSTREAM_POINTER_OFFSET structure indexes bytes or mappings within a frame.

## Members

### `Mappings`

A pointer to the first element in an array of [KSMAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksmapping) structures. Specify **Mappings** if the minidriver sets the KSPIN_FLAG_GENERATE_MAPPINGS flag in the **Flags** member of [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex). In this case, the **Mappings** array describes contiguous chunks of physical memory that the client can use to set up a scatter/gather DMA operation with hardware.

### `Data`

A pointer to a buffer containing input data or a buffer to which data is to be output. Specify **Data** if the minidriver does not set the KSPIN_FLAG_GENERATE_MAPPINGS flag in the **Flags** member of [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex).

### `Alignment`

### `Count`

If **Data** is specified above, **Count** contains the total number of bytes of data available in the **Data** buffer. If **Mappings** is specified above, **Count** contains the total number of mappings in the **Mappings** table. **Count** does not change unless the stream pointer moves to a different *Frame*.

### `Remaining`

This member specifies a value of type ULONG that indicates the number of bytes or mappings remaining at and ahead of the given stream pointer. This value is equal to **Count** minus the number of bytes or mappings that have been processed. **Remaining** starts equal to **Count** and decreases as the stream pointer moves forward.

## Remarks

See also [AVStream DMA Services](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-dma-services).

## See also

[KSMAPPING](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksmapping)

[KSSTREAM_POINTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer)