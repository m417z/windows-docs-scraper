# PrintControlProperties function

## Description

Returns a filled [D2D1_PRINT_CONTROL_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_print_control_properties) structure.

## Parameters

### `fontSubsetMode`

Type: **[D2D1_PRINT_FONT_SUBSET_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_print_font_subset_mode)**

The mode to use for selecting fonts for printing.

### `rasterDpi`

Type: **FLOAT**

DPI for rasterization of all unsupported D2D commands or options, defaults to150.0

### `colorSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

Color space for vector graphics in XPS package

## Return value

Type: **[D2D1_PRINT_CONTROL_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ns-d2d1_1-d2d1_print_control_properties)**

The creation properties for a [ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol) object.