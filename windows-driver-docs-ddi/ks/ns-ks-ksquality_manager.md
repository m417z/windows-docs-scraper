# KSQUALITY_MANAGER structure

## Description

The KSQUALITY_MANAGER structure is used with the [KSPROPERTY_STREAM_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-stream-quality) property and contains the handle of the quality manager sink and a context to pass in the quality complaints.

## Members

### `QualityManager`

Specifies a handle to the quality manager sink receiving the [KSQUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksquality) complaint structures.

### `Context`

Specifies the context parameter to use when reporting quality problems. The context is used by the quality manager to distinguish between various clients that can send complaints to the same file object.

## See also

[KSPROPERTY_STREAM_QUALITY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-stream-quality)

[KSQUALITY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksquality)