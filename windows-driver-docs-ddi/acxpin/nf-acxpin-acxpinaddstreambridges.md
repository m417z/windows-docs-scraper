## Description

The **AcxPinAddStreamBridges** function adds an array of stream bridges to the specified pin.

## Parameters

### `Pin` [in]

The pin to which the stream bridges are added.

### `StreamBridges` [in, reads(StreamBridgesCount)]

A pointer to an array of **ACXSTREAMBRIDGE** objects to add to the specified *Pin*.

### `StreamBridgesCount` [in]

The number of **ACXSTREAMBRIDGE** objects in the *StreamBridges* array.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)