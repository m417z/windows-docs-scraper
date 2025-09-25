# KSCAMERA_PERFRAMESETTING_ITEM_HEADER structure

## Description

This structure contains the header information for a per-frame settings item.

## Members

### `Size`

The size of this header and the item payload that follows.

### `Type`

This contains a [KSCAMERA_PERFRAMESETTING_ITEM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ne-ksmedia-kscamera_perframesetting_item_type) structure.

### `Flags`

This is any one of the capability flags reported in the [KSCAMERA_PERFRAMESETTING_CAP_ITEM_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-kscamera_perframesetting_cap_item_header) Flags field.