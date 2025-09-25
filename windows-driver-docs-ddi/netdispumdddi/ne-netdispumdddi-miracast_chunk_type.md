# MIRACAST_CHUNK_TYPE enumeration

## Description

Specifies the types of wireless display (Miracast) chunk info that is to be processed.

## Constants

### `MIRACAST_CHUNK_TYPE_UNKNOWN`

An unknown or undefined chunk type.

### `MIRACAST_CHUNK_TYPE_COLOR_CONVERT_COMPLETE`

Color conversion has completed on the chunk.

### `MIRACAST_CHUNK_TYPE_ENCODE_COMPLETE`

Encoding has completed on the chunk.

### `MIRACAST_CHUNK_TYPE_FRAME_START`

The chunk is at the start of the Wi-Fi frame.

### `MIRACAST_CHUNK_TYPE_FRAME_DROPPED`

The chunk is in a dropped Wi-Fi frame.

### `MIRACAST_CHUNK_TYPE_ENCODE_DRIVER_DEFINED_1`

Encoding is driver-defined, of type 1.

### `MIRACAST_CHUNK_TYPE_ENCODE_DRIVER_DEFINED_2`

Encoding is driver-defined, of type 2.

### `MIRACAST_CHUNK_TYPE_ENCODE_FORCE_UINT32`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.