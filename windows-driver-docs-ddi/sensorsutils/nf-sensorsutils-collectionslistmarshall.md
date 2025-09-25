# CollectionsListMarshall function

## Description

This routine is similar to [CollectionsListCopyAndMarshall](https://learn.microsoft.com/windows-hardware/drivers/ddi/sensorsutils/nf-sensorsutils-collectionslistcopyandmarshall), except that it marshalls a collection list in-place.

## Parameters

### `Target` [in]

Pointer to a collection list.

## Return value

If the Source Collection list is not large enough to accommodate the marshalled/flattened list, this function fails with STATUS_BUFFER_TOO_SMALL. Returns STATUS_SUCCESS otherwise.

## Remarks

## See also