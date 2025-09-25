# _D3DKMT_BRIGHTNESS_INFO_TYPE enumeration

## Description

Indicates the type of information to retrieve or set for the brightness of an integrated display panel.

## Constants

### `D3DKMT_BRIGHTNESS_INFO_GET_POSSIBLE_LEVELS`

Retrieve all possible brightness levels that the integrated display panel supports.

### `D3DKMT_BRIGHTNESS_INFO_GET`

Retrieve the currently active brightness level.

### `D3DKMT_BRIGHTNESS_INFO_SET`

 Set a new brightness level.

### `D3DKMT_BRIGHTNESS_INFO_GET_CAPS`

Retrieve brightness control capabilities of the integrated display panel.

### `D3DKMT_BRIGHTNESS_INFO_SET_STATE`

Enable smooth brightness control.

### `D3DKMT_BRIGHTNESS_INFO_SET_OPTIMIZATION`

Set the level of optimization that the display miniport driver uses to control the brightness of the integrated display panel.

### `D3DKMT_BRIGHTNESS_INFO_GET_REDUCTION`

Retrieve the current level of backlight reduction that is applied to the integrated display panel.

### `D3DKMT_BRIGHTNESS_INFO_BEGIN_MANUAL_MODE`

The user has begun to manually adjust the brightness level.

### `D3DKMT_BRIGHTNESS_INFO_END_MANUAL_MODE`

The user has ended the manual adjustment of the brightness level.

### `D3DKMT_BRIGHTNESS_INFO_TOGGLE_LOGGING`

Enable or disable Event Tracing for Windows (ETW) logging of brightness information.

### `D3DKMT_BRIGHTNESS_INFO_GET_NIT_RANGES`

Retrieves a list of supported nit ranges.

## Syntax

```cpp
typedef enum _D3DKMT_BRIGHTNESS_INFO_TYPE {
  D3DKMT_BRIGHTNESS_INFO_GET_POSSIBLE_LEVELS  = 1,
  D3DKMT_BRIGHTNESS_INFO_GET                  = 2,
  D3DKMT_BRIGHTNESS_INFO_SET                  = 3,
  D3DKMT_BRIGHTNESS_INFO_GET_CAPS             = 4,
  D3DKMT_BRIGHTNESS_INFO_SET_STATE            = 5,
  D3DKMT_BRIGHTNESS_INFO_SET_OPTIMIZATION     = 6,
  D3DKMT_BRIGHTNESS_INFO_GET_REDUCTION        = 7,
  D3DKMT_BRIGHTNESS_INFO_BEGIN_MANUAL_MODE    = 8,
  D3DKMT_BRIGHTNESS_INFO_END_MANUAL_MODE      = 9,
  D3DKMT_BRIGHTNESS_INFO_TOGGLE_LOGGING       = 10
} D3DKMT_BRIGHTNESS_INFO_TYPE;
```