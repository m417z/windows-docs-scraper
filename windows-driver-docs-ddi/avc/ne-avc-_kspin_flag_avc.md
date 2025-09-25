# _KSPIN_FLAG_AVC enumeration

## Description

The KSPIN_FLAG_AVC enumeration type is used for connection management and in the **AVC_FUNCTION_GET_CONNECTINFO** function code.

## Constants

### `KSPIN_FLAG_AVCMASK`

The mask to isolate the AV/C defined bit flags

### `KSPIN_FLAG_AVC_PERMANENT`

Part of the AV/C Connect Status bitmask. Represents a permanent connection between two subunits within the same unit.

### `KSPIN_FLAG_AVC_CONNECTED`

Part of the AV/C Connect Status bitmask. Represents a connection that is currently active, but not necessarily permanent.

### `KSPIN_FLAG_AVC_PCRONLY`

No subunit plug control. Only unit input and output plugs are available, and this AVCPRECONNECTINFO structure represents one of them.

### `KSPIN_FLAG_AVC_FIXEDPCR`

Represents a permanent connection between a subunit plug and a unit (serial bus) plug. Specifying this flag implies KSPIN_FLAG_AVC_PERMANENT, although that bit is not set if this one is set.

## Remarks

These bit flags are used by the intersect handler to determine plug compatibility, as well as to indicate whether the intersect handler is responsible for obtaining a plug handle from *61883.sys*.

## See also

[AV/C Intersect Handler](https://learn.microsoft.com/windows-hardware/drivers/ddi/avc/nc-avc-pfnavcintersecthandler)

[AVC_FUNCTION_GET_CONNECTINFO](https://learn.microsoft.com/windows-hardware/drivers/stream/avc-function-get-connectinfo)