# CollectionsListCopyAndMarshall function

## Description

This routine copies and marshalls a collection list from source to target.

## Parameters

### `Target` [in]

A pointer to a collection list.

### `Source` [out]

A pointer to a collection list.

## Return value

This function returns NTSTATUS.

## Remarks

> [!WARNING]
> This method assumes the structure sizes stay the same during marshalling. Avoid using this method if passing the data between processes that can have different bit-ness values (e.g. 32 bit <-> 64 bit). Use [CollectionsListSerializeToBuffer](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsutils/nf-sensorsutils-collectionslistserializetobuffer) instead.

## See also