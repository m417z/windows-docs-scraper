# HidP_GetLinkCollectionNodes function

## Description

The **HidP_GetLinkCollectionNodes** routine returns a [top-level collection's](https://learn.microsoft.com/windows-hardware/drivers/hid/top-level-collections) [link collection array](https://learn.microsoft.com/windows-hardware/drivers/hid/link-collections).

## Parameters

### `LinkCollectionNodes` [out]

Pointer to a caller-allocated array of HIDP_LINK_COLLECTION_NODE structures in which **HidP_GetLinkCollectionNodes** returns a top-level collection's link collection array.

### `LinkCollectionNodesLength` [in, out]

Specifies, on input, the length, in array elements, of the *LinkCollectionNodes* buffer. On output, the routine sets *LinkCollectionNodesLength* to the number of entries in the array that it set.

### `PreparsedData` [in]

Pointer to the preparsed data of the top-level collection for which this routine returns a link collection array.

## Return value

**HidP_GetLinkCollectionNodes** returns one of the following status codes:

| Return code | Description |
| --- | --- |
| **HIDP_STATUS_SUCCESS** | The routine successfully returned the specified collection's link collection array. |
| **HIDP_STATUS_INVALID_PREPARSED_DATA** | The preparsed data is not valid. |
| **HIDP_STATUS_BUFFER_TOO_SMALL** | The *LinkCollectionNodes* buffer is too small to hold the entire link collection array. |

## Remarks

The required length of the *LinkCollectionNodes* buffer is specified by the **NumberLinkCollectionNodes** member of a collection's [HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps) structure.

If **HidP_GetLinkCollectionNodes** returns the status value HIDP_STATUS_BUFFER_TOO_SMALL, it also sets *LinkCollectionNodesLength* to the length, in array elements, required to hold the link collection nodes information.

For more information, see [HID Collections](https://learn.microsoft.com/windows-hardware/drivers/hid/hid-collections).

## See also

[HIDP_CAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_caps)

[HIDP_LINK_COLLECTION_NODE](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/ns-hidpi-_hidp_link_collection_node)

[HidP_GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidpi/nf-hidpi-hidp_getcaps)

[_HIDP_PREPARSED_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/hidsdi/nf-hidsdi-hidd_getpreparseddata)