# _DXVAHDDDI_DEVICE_DESC structure

## Description

The DXVAHDDDI_DEVICE_DESC structure describes a decode device.

## Members

### `pContentDesc` [in]

A pointer to a [DXVAHDDDI_CONTENT_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_content_desc) structure that describes how the device decodes content.

### `Usage` [in]

A [DXVAHDDDI_DEVICE_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_device_usage)-typed value that indicates how the decode device plays video.

## Remarks

The driver considers the value in the **Usage** member and the information to which **pContentDesc** points to optimize its capabilities.

## See also

[DXVAHDDDI_CONTENT_DESC](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvahdddi_content_desc)

[DXVAHDDDI_DEVICE_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_dxvahdddi_device_usage)