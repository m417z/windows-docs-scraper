## Description

This structure describes the number of profile strings in a buffer.

## Members

### `BufferSize`

The size in bytes of the buffer that follows this **PosProfileType**, including the size of the **PosProfileType** structure.

### `ProfileCount`

Indicates the number of statistics that follow this header.

## Remarks

The buffer of profile *PosStringType* strings follows this structure in memory.