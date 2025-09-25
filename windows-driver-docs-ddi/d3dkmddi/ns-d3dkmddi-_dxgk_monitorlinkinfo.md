# _DXGK_MONITORLINKINFO structure

## Description

Describes usage hints for the driver and capabilities for driving a monitor that is connected to a particular target, which does not depend on the current display configuration and can therefore be assumed for the lifetime of the connection. This structure was defined in WDDM 2.1.

## Members

### `UsageHints` [in]

Hints to the driver on the intended usage of the display device. See [_DXGK_MONITORLINKINFO_USAGEHINTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_monitorlinkinfo_usagehints).

### `Capabilities` [out]

Flags which describe the capabilities for driving the monitor. See [_DXGK_MONITORLINKINFO_CAPABILITIES structure](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_monitorlinkinfo_capabilities).

### `DitheringSupport` [out]

A D3DKMDT_WIRE_FORMAT_AND_PREFERENCE field containing the flags for each wire-format. The driver should set the wire-format bit for each format where the driver and hardware supports dithering beneficial to image quality when the source pixel format contains is higher precision that than the wire-format.

## Remarks

The usage hints and capabilities structure definitions were nested within DXGK_MONITORLINKINFO. In order to allow the same capabilities structure to be reused in DXGK_QUERYINTEGRATEDDISPLAYOUT, the nested definitions have been extracted into their own structures.

Mode enumeration is typically required to discover if the capability is supported in a particular display configuration. But if the capability is not supported, then mode enumeration is unnecessary.