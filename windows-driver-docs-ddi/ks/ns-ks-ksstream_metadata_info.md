# KSSTREAM_METADATA_INFO structure

## Description

This structure contains the metadata information that is passed down to the driver.

## Members

### `BufferSize`

This value is set by the user mode component and is equal to the MaxMetadataBufferSize supplied by the driver.

### `UsedSize`

The size of the metadata written by the driver in the SystemVa buffer.

### `Data`

The metadata buffer that is passed down by the user mode component. This is mapped to *SystemVa*.

### `SystemVa`

The buffer that is used by the driver to fill with metadata.

### `Flags`

Set to KSCAMERA_EXTENDEDPROP_METADATA_SYSTEMMEMORY if the metadata buffer is allocated from the system memory.

### `Reserved`

Reserved for system use.