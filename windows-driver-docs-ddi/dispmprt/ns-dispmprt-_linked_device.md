# _LINKED_DEVICE structure

## Description

The LINKED_DEVICE structure holds information that describes a linked display adapter configuration.

## Members

### `ChainUid`

A unique identifier for this chain of display adapters.

### `NumberOfLinksInChain`

The expected number of linked adapters that the operating system should enumerate.

### `LeadLink`

A value that indicates the leading link in the chain of linked adapters. The value is **TRUE** only for the adapter that will be allowed to enumerate child adapters. Otherwise, the value is **FALSE**.

## Remarks

Prior to a call to [DxgkDdiLinkDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_link_device), the display miniport driver should fill the LINKED_DEVICE structure with information about the linked adapter configuration.

## See also

[DxgkDdiLinkDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_link_device)