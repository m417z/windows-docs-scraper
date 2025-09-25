# _DXGK_QUERYINTEGRATEDDISPLAYOUT2 structure

## Description

Used during a query for the integrated display output.

## Members

### `Flags` [out]

Pointer to a [DXGK_INTEGRATEDDISPLAYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_integrateddisplayflags) structure that describes simple properties of an integrated display. Orientation values of 0 degrees indicate no override from the descriptor.

### `NativeTiming` [out]

Pointer to a [D3DKMDT_VIDEO_SIGNAL_INFO]/d3dkmdt/ns-d3dkmdt-_d3dkmdt_video_signal_info.md) structure that contains information about a native timing of the integrated display. Should be zeroed to indicate no override. This value overrides the native timing in the descriptor. Since the driver is responsible for providing the descriptor, the only expected usage of this override is to describe a timing which cannot be described by an EDID, most obviously, a display which has more than 4095 addressable pixels in either direction.
If a NativeTiming override is provided, the OS will not call [DxgkDdiRecommendMonitorModes](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_recommendmonitormodes) for this target. Generally, integrated panels do not support a large set of timings and the driver should be well matched to the EDID provided. If the driver needs to describe multiple overrides for monitor modes, it should leave the NativeTiming structure zeroed and report all the overrides using DxgkDdiRecommendMonitorModes.

### `LinkCapabilities` [out]

Pointer to a [DXGK_MONITORLINKINFO_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_dxgk_monitorlinkinfo_capabilities) structure that describes the link capabilities for driving the monitor. This is the same link capabilities as the OS would query from an external display after hot-plug. Since an integrated display is exposed during adapter driver initialization, the capabilities are described directly rather make an additional DDI call.

Starting in WDDM 2.6, this member is used to report synchronization support.

### `Colorimetry` [out]

Colorimetry related overrides for the display. See the description of [DXGK_COLORIMETRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_colorimetry) for the field definitions and restrictions on the combinations of fields.

### `DisplayTechnology` [out]

Value that represents the technology of the display. Used to optimize experience, for example enabling a darker theme with reduced blue content on DXGK_DT_OLED displays.

### `IntendedUsage` [out]

Value that indicates the manufacturer’s intended usage of the display. The value reported should be DXGK_DU_GENERIC, unless the driver has information indicating a more specific usage. The expectation is that if the integrated display is intended to be used for AR, VR or auxiliary output, the driver would have to have enough specific handling that it would be able to report the correct usage.

### `Instance` [out]

A zero-based integer for the instance of integrated panel. Used to order multiple integrated panels. Values must be unique and contiguous across integrated targets but are not required to be reported in order.

### `DescriptorType` [out]

Value to indicate the type of descriptor. For WDDM 2.4 this value must be DXGK_DDT_EDID. From WDDM 2.5 and later, either DXGK_DDT_EDID or DXGK_DDT_DISPLAYID is allowed.

### `DitheringSupport` [out]

A [D3DKMDT_WIRE_FORMAT_AND_PREFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmdt/ns-d3dkmdt-_d3dkmdt_wire_format_and_preference) field that contains the flags for each wire-format. The driver should set the wire-format bit for each format where the driver and hardware supports dithering beneficial to image quality when the source pixel format contains higher precision than the wire-format.

## Remarks

The fields provide overrides attributes of the display which could be provided by a descriptor, but either can't be described by an EDID or have commonly missing or incorrect in EDIDs. Where there is a conflict between the descriptor and these override fields, the OS will use the overrides when valid.

The OS will sanity check the fields and will fail driver start if any fields are found to be inconsistent or invalid. For most fields, sanity checking simply means verifying that reported values are in range but the Colorimetry, Instance and Descriptor fields have further validation applied. For Colorimetry, see the description of DXGK_COLORIMETRY for validation. Instance values are verified to be consistent across all integrated displays as noted above. The Descriptor must be a valid EDID.

## See also