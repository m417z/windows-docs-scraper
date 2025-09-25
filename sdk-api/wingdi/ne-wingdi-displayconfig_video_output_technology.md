# DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY enumeration

## Description

The DISPLAYCONFIG_VIDEO_OUTPUT_TECHNOLOGY enumeration specifies the target's connector type.

## Constants

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER:-1`

Indicates a connector that is not one of the types that is indicated by the following enumerators in this enumeration.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15:0`

Indicates an HD15 (VGA) connector.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO:1`

Indicates an S-video connector.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO:2`

Indicates a composite video connector group.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO:3`

Indicates a component video connector group.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI:4`

Indicates a Digital Video Interface (DVI) connector.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI:5`

Indicates a High-Definition Multimedia Interface (HDMI) connector.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS:6`

Indicates a Low Voltage Differential Swing (LVDS) connector.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN:8`

Indicates a Japanese D connector.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI:9`

Indicates an SDI connector.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL:10`

Indicates an external display port, which is a display port that connects externally to a display device.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED:11`

Indicates an embedded display port that connects internally to a display device.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL:12`

Indicates an external Unified Display Interface (UDI), which is a UDI that connects externally to a display device.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED:13`

Indicates an embedded UDI that connects internally to a display device.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE:14`

Indicates a dongle cable that supports standard definition television (SDTV).

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_MIRACAST:15`

Indicates that the VidPN target is a Miracast wireless display device.

Supported starting in Windows 8.1.

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INDIRECT_WIRED:16`

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INDIRECT_VIRTUAL:17`

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL:0x80000000`

Indicates that the video output device connects internally to a display device (for example, the internal connection in a laptop computer).

### `DISPLAYCONFIG_OUTPUT_TECHNOLOGY_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

Values with "embedded" in their names indicate that the graphics adapter's video output device connects internally to the display device. In those cases, the DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL value is redundant. The caller should ignore DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL and just process the embedded values, DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED and DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED.

An embedded display port or UDI is also known as an integrated display port or UDI.