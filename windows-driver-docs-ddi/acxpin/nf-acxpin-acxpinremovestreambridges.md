## Description

The **AcxPinRemoveStreamBridges** function removes ACXSTREAMBRIDGE objects from the specified pin.

## Parameters

### `Pin` [in]

The ACXPIN handle from which to remove the stream bridges.

### `StreamBridges` [in, reads(StreamBridgesCount)]

A pointer to an array of ACXSTREAMBRIDGE handles representing the steam bridges to remove from the *Pin*.

### `StreamBridgesCount`

The number of steam bridges to remove from the *Pin*. This parameter must not equal zero.

## Return value

The method returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method might return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Remarks

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxpin.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxpin/)