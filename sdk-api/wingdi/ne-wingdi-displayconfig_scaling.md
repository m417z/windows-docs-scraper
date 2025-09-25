# DISPLAYCONFIG_SCALING enumeration

## Description

The DISPLAYCONFIG_SCALING enumeration specifies the scaling transformation applied to content displayed on a video present network (VidPN) present path.

## Constants

### `DISPLAYCONFIG_SCALING_IDENTITY:1`

Indicates the identity transformation; the source content is presented with no change. This transformation is available only if the path's source mode has the same spatial resolution as the path's target mode.

### `DISPLAYCONFIG_SCALING_CENTERED:2`

Indicates the centering transformation; the source content is presented unscaled, centered with respect to the spatial resolution of the target mode.

### `DISPLAYCONFIG_SCALING_STRETCHED:3`

Indicates the content is scaled to fit the path's target.

### `DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX:4`

Indicates the aspect-ratio centering transformation.

### `DISPLAYCONFIG_SCALING_CUSTOM:5`

Indicates that the caller requests a custom scaling that the caller cannot describe with any of the other DISPLAYCONFIG_SCALING_XXX values. Only a hardware vendor's value-add application should use DISPLAYCONFIG_SCALING_CUSTOM, because the value-add application might require a private interface to the driver. The application can then use DISPLAYCONFIG_SCALING_CUSTOM to indicate additional context for the driver for the custom value on the specified path.

### `DISPLAYCONFIG_SCALING_PREFERRED:128`

Indicates that the caller does not have any preference for the scaling. The [SetDisplayConfig](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdisplayconfig) function will use the scaling value that was last saved in the database for the path. If such a scaling value does not exist, **SetDisplayConfig** will use the default scaling for the computer. For example, stretched (DISPLAYCONFIG_SCALING_STRETCHED) for tablet computers and aspect-ratio centered (DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX) for non-tablet computers.

### `DISPLAYCONFIG_SCALING_FORCE_UINT32:0xFFFFFFFF`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. You should not use this value.

## Remarks

For more information about scaling, see [Scaling the Desktop Image](https://learn.microsoft.com/windows-hardware/drivers/display/scaling-the-desktop-image).