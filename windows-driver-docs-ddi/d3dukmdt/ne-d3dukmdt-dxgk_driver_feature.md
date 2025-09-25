## Description

The **DXGK_DRIVER_FEATURE** enumeration is a list of driver features.

## Constants

### `DXGK_DRIVER_FEATURE_HWSCH:0`

The hardware accelerated GPU scheduling feature.

### `DXGK_DRIVER_FEATURE_HWFLIPQUEUE:1`

The hardware flip queue feature.

### `DXGK_DRIVER_FEATURE_LDA_GPUPV:2`

The linked display adapter in GPU paravirtualization feature.

### `DXGK_DRIVER_FEATURE_KMD_SIGNAL_CPU_EVENT:3`

The signaling of a CPU event by KMD feature.

### `DXGK_DRIVER_FEATURE_USER_MODE_SUBMISSION:4`

The user-mode submission feature.

### `DXGK_DRIVER_FEATURE_SHARE_BACKING_STORE_WITH_KMD:5`

The allowing UMD to share the backing store with KMD feature.

### `DXGK_DRIVER_FEATURE_RESERVED_1:6`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_2:7`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_3:8`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_4:9`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_5:10`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_6:11`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_7:12`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_8:13`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_9:14`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_10:15`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_11:16`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_12:17`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_13:18`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_14:19`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_15:20`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_16:21`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_17:22`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_18:23`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_19:24`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_20:25`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_21:26`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_22:27`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_23:28`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_24:29`

Reserved.

### `DXGK_DRIVER_FEATURE_RESERVED_25:30`

Reserved.

### `DXGK_DRIVER_FEATURE_SAMPLE:31`

### `DXGK_DRIVER_FEATURE_PAGE_BASED_MEMORY_MANAGER:32`

The page-based memory management feature.

### `DXGK_DRIVER_FEATURE_KERNEL_MODE_TESTING:33`

The kernel-mode testing interface feature.

### `DXGK_DRIVER_FEATURE_64K_PT_DEMOTION_FIX:34`

The OS bugfix for 64K page table demotion.

### `DXGK_DRIVER_FEATURE_GPUPV_PRESENT_HWQUEUE:35`

The OS bugfix for GPU paravirtualization and hardware scheduling enabled.

### `DXGK_DRIVER_FEATURE_GPUVAIOMMU:36`

The usage of GPU virtual addresses with IoMmu feature.

### `DXGK_DRIVER_FEATURE_NATIVE_FENCE:37`

The native GPU fence feature.

### `DXGK_DRIVER_FEATURE_MAX`

Maximum value for the enumeration.

## Remarks

A WDDM feature is identified by a [feature ID](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id) value that has a [feature category](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_category) (upper 4 bits) and a sub-ID (bottom 28 bits). The feature sub-ID is one of the values in this enumeration when the feature category is **DXGK_FEATURE_CATEGORY_DRIVER**.

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_FEATURE_CATEGORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_category)

[**DXGK_FEATURE_ID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_id)