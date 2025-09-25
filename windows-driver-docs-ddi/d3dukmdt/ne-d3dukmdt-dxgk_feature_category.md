## Description

The **DXGK_FEATURE_CATEGORY** enumeration specifies the category of a WDDM feature.

## Constants

### `DXGK_FEATURE_CATEGORY_DRIVER:0`

Indicates a feature that requires additional driver support. For ease of implementation, the driver category is category 0 (meaning all 4 upper category ID bits are 0). This layout makes it easier for drivers to implement by allowing feature data to be store in static and/or linear arrays of data.

### `DXGK_FEATURE_CATEGORY_OS:1`

Indicates a feature that is internal or specific to the OS.

### `DXGK_FEATURE_CATEGORY_BUGFIX:2`

Indicates a bugfix. This value allows the driver or another component to trivially ask the OS if a bugfix is present. Drivers then don't have to do any fancy workarounds with build numbers, which can be confusing when backporting fixes.

### `DXGK_FEATURE_CATEGORY_TEST:3`

Reserved for testing purposes. No feature IDs in this category are used in production.

### `DXGK_FEATURE_CATEGORY_RESERVED4:4`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED5:5`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED6:6`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED7:7`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED8:8`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED9:9`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED10:10`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED11:11`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED12:12`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED13:13`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED14:14`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_RESERVED15:15`

Reserved for future use. No feature IDs are defined in this category.

### `DXGK_FEATURE_CATEGORY_MAX:16`

Maximum value for this enumeration.

## Remarks

A WDDM feature is identified by a [feature ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) value that has a feature category (one of this enumeration's values in the upper 4 bits) and a sub-ID (bottom 28 bits).

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_DRIVER_FEATURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_driver_feature)

[**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id)