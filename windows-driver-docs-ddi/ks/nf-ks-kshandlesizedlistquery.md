# KsHandleSizedListQuery function

## Description

The **KsHandleSizedListQuery** function, depending on the length of the system buffer, returns either the size of the buffer needed, number of entries in the specified data list, or copies the entries themselves. This assumes the structure of KSMULTIPLE_ITEM to be a Size followed by a Count.

## Parameters

### `Irp` [in]

Specifies the IRP with the identifier list request.

### `DataItemsCount` [in]

Specifies the number of items in the identifier list.

### `DataItemSize` [in]

Specifies the size of a data item.

### `DataItems` [in]

Specifies the list of data items.

## Return value

The **KsHandleSizedListQuery** function returns STATUS_SUCCESS if the number of entries and the data can be copied. If the buffer is larger than the size to store just the size and the count of entries but too small to contain all the entries, the function returns status STATUS_BUFFER_TOO_SMALL.

## Remarks

Use the **KsHandleSizedListQuery** function when implementing properties that are to return information in the multiple item format.