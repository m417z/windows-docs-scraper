# _DXGK_DEVICE_DESCRIPTOR structure

## Description

The DXGK_DEVICE_DESCRIPTOR structure is used by the display port driver to request that the display miniport driver return all or a portion of a monitor's Extended Display Identification Data (EDID).

## Members

### `DescriptorOffset`

An integer that indicates an offset, in bytes, into the EDID. This member specifies the beginning of the requested data.

### `DescriptorLength`

An integer that indicates the length, in bytes, of the buffer pointed to by **DescriptorBuffer**.

### `DescriptorBuffer`

A pointer to a buffer that receives all or a portion of the monitor's EDID. This buffer is allocated by the display port driver and filled in by the display miniport driver. The display miniport driver must not write more than **DescriptorLength** bytes to this buffer.

## Remarks

The display port driver passes a DXGK_DEVICE_DESCRIPTOR structure to [DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor) to request that the display miniport driver return all or a portion of a monitor's EDID. The desired portion of the EDID is specified by the **DescriptorOffset** and **DescriptorLength** members. For example, to request 256 bytes, starting at an offset of 128 bytes into a monitor's EDID, the display port driver would set **DescriptorOffset** to 128, and **DescriptorLength** to 256.

## See also

[DXGK_GENERIC_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_generic_descriptor)

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[DxgkDdiQueryDeviceDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_device_descriptor)