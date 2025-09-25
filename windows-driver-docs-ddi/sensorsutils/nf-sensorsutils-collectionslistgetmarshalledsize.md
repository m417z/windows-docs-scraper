# CollectionsListGetMarshalledSize function

## Description

This routine is maintained for compatibility. It returns the size needed to accommodate serializing and marshaling a collection list, including embedded memory. It does the same thing as [CollectionsListGetSerializedSize](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsutils/nf-sensorsutils-collectionslistgetserializedsize).

## Parameters

### `Collection` [in]

Pointer to a sensor collection list.

## Return value

This function returns a ULONG that represents the size of the data.

## Remarks

## See also