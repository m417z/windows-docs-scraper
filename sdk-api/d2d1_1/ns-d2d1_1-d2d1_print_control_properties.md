# D2D1_PRINT_CONTROL_PROPERTIES structure

## Description

The creation properties for a [ID2D1PrintControl](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1printcontrol) object.

## Members

### `fontSubset`

Type: **[D2D1_PRINT_FONT_SUBSET_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_print_font_subset_mode)**

The mode to use for subsetting fonts for printing, defaults to [D2D1_PRINT_FONT_SUBSET_MODE_DEFAULT](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_print_font_subset_mode).

### `rasterDPI`

Type: **FLOAT**

DPI for rasterization of all unsupported Direct2D commands or options, defaults to 150.0.

### `colorSpace`

Type: **[D2D1_COLOR_SPACE](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space)**

Color space for vector graphics, defaults to [D2D1_COLOR_SPACE_SRGB](https://learn.microsoft.com/windows/desktop/api/d2d1_1/ne-d2d1_1-d2d1_color_space).