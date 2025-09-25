# CollectionsListUpdateMarshalledPointer function

## Description

This routine update embedded pointers. It should be called when marshalled collection list pass between processes.

> [!WARNING]
> This method assumes the structure sizes stay the same during marshalling. Avoid using this method if passing the data between processes that can have different bit-ness values (e.g. 32 bit <-> 64 bit). Use CollectionsListDeserializeFromBuffer instead.

## Parameters

### `Collection` [in/out]

A pointer to a sensor collection list.

## Return value

This function returns STATUS_INVALID_PARAMETER if:

* The Collection is null.
* The AllocatedSizeInBytes member of Collection is less than the acceptable minimum size (in bytes) for a sensor collection list.

Returns STATUS_SUCCESS otherwise.

## Remarks

## See also