## Description

The **MmInitializeMdl** macro initializes the header of an MDL.

## Parameters

### `MemoryDescriptorList` [in]

A pointer to the buffer to initialize as an MDL. For more information, see the following section.

### `BaseVa` [in]

A pointer to the base virtual address of a buffer.

### `Length` [in]

Specifies the length, in bytes, of the buffer to be described by the MDL. This routine supports a maximum buffer length of MAXULONG bytes.

## Remarks

The buffer that _MemoryDescriptorList_ points to must be allocated in nonpaged memory.
The size, in bytes, of this buffer must be at least **sizeof**(MDL) + **sizeof**(PFN_NUMBER) * **ADDRESS_AND_SIZE_TO_SPAN_PAGES**(_BaseVa_, _Length_).