# WIC8BIMResolutionInfoProperties enumeration

## Description

Specifies the identifiers of the metadata items in an 8BIMResolutionInfo block.

## Constants

### `WIC8BIMResolutionInfoPString:0x1`

[VT_LPSTR] A name that identifies the 8BIM block.

### `WIC8BIMResolutionInfoHResolution:0x2`

[VT_UI4] The horizontal resolution of the image.

### `WIC8BIMResolutionInfoHResolutionUnit:0x3`

[VT_UI2] The units that the horizontal resolution is specified in; a 1 indicates pixels per inch and a 2 indicates pixels per centimeter.

### `WIC8BIMResolutionInfoWidthUnit:0x4`

[VT_UI2] The units that the image width is specified in; a 1 indicates inches, a 2 indicates centimeters, a 3 indicates points, a 4 specifies picas, and a 5 specifies columns.

### `WIC8BIMResolutionInfoVResolution:0x5`

[VT_UI4] The vertical resolution of the image.

### `WIC8BIMResolutionInfoVResolutionUnit:0x6`

[VT_UI2] The units that the vertical resolution is specified in; a 1 indicates pixels per inch and a 2 indicates pixels per centimeter.

### `WIC8BIMResolutionInfoHeightUnit:0x7`

[VT_UI2] The units that the image height is specified in; a 1 indicates inches, a 2 indicates centimeters, a 3 indicates points, a 4 specifies picas, and a 5 specifies columns.

### `WIC8BIMResolutionInfoProperties_FORCE_DWORD:0x7fffffff`