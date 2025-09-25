## Description

A **DXGK_FEATURE_ID** enumeration value identifies a WDDM feature.

## Constants

### `DXGK_FEATURE_HWSCH`

The hardware accelerated GPU scheduling feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_HWFLIPQUEUE`

The [hardware flip queue](https://learn.microsoft.com/windows-hardware/drivers/display/hardware-flip-queue) feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_LDA_GPUPV`

The linked display adapter in GPU paravirtualization feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_KMD_SIGNAL_CPU_EVENT`

The [signaling of a CPU event by KMD](https://learn.microsoft.com/windows-hardware/drivers/display/signaling-cpu-event-from-kmd) feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_USER_MODE_SUBMISSION`

The user-mode submission feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_SHARE_BACKING_STORE_WITH_KMD`

The [allowing UMD to share the backing store with KMD](https://learn.microsoft.com/windows-hardware/drivers/display/sharing-backing-store-with-kmd) feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_SAMPLE`

Drivers can use this value to test their implementations.

### `DXGK_FEATURE_PAGE_BASED_MEMORY_MANAGER`

The page-based memory management feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_KERNEL_MODE_TESTING`

The [kernel-mode testing](https://learn.microsoft.com/windows-hardware/drivers/display/kernel-mode-testing-of-wddm-features) feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_64K_PT_DEMOTION_FIX`

The OS's 64k page table demotion fix "feature", which indicates that the OS has the fix for 64K page table demotion enabled. 64KB page table demotion happens when a GPU VA range mapped by 64KB pages needs to be partially mapped by 4KB pages. In this case the page table with 64KB entries is converted (demoted) to a page table with 4KB entries. The bug was that the driver protection and allocation handle wasn't preserved during the demotion. The feature category is DXGK_FEATURE_CATEGORY_DRIVER. See Remarks for more information.

### `DXGK_FEATURE_GPUPV_PRESENT_HWQUEUE`

The OS has the fix for the issue in GPU paravirtualization and hardware scheduling enabled. If a DXGK context object had multiple hardware queues and [**D3DKMTPresent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present) was called with a hardware queue that wasn't first in the list of queues, the very first hardware queue was used on the host to handle the Present. The feature category is DXGK_FEATURE_CATEGORY_DRIVER. See Remarks for more information.

### `DXGK_FEATURE_NATIVE_FENCE`

The [native GPU fence](https://learn.microsoft.com/windows-hardware/drivers/display/native-gpu-fence-objects) feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_GPUVAIOMMU`

The GPU virtual address with IoMmu feature. The feature category is DXGK_FEATURE_CATEGORY_DRIVER.

### `DXGK_FEATURE_QUERYSTATISTICS_EXTENSIONS`

The query statistics feature. The feature category is DXGK_FEATURE_CATEGORY_OS.

## Remarks

A WDDM feature is identified by its feature ID (**DXGK_FEATURE_ID**) which is composed of:

* A [**DXGK_FEATURE_CATEGORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_category) value that identifies the feature's category ID. This information is stored in the upper four bits of **DXGK_FEATURE_ID**.
* A [**DXGK_DRIVER_FEATURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_driver_feature) value that identifies the feature itself.

Because the original feature implementations didn't categorize the feature IDs, there are a handful of feature IDs that must remain defined within category 0 for backwards compatibility, but are not driver features. This applies to the following feature IDs:

* DXGK_FEATURE_64K_PT_DEMOTION_FIX
* DXGK_FEATURE_GPUPV_PRESENT_HWQUEUE
* All feature IDs in the range of DXGK_DRIVER_FEATURE_RESERVED_1 through DXGK_DRIVER_FEATURE_RESERVED_25

These feature IDs represent features that have been defined or implemented on older OS builds, and existing software checks must be able to continue to query these features by those IDs. Drivers aren't required to implement support for any of these feature IDs.

For more information, see [Querying WDDM feature support and enablement](https://learn.microsoft.com/windows-hardware/drivers/display/querying-wddm-feature-support-and-enablement).

## See also

[**DXGK_DRIVER_FEATURE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_driver_feature)

[**DXGK_FEATURE_CATEGORY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dukmdt/ne-d3dukmdt-dxgk_feature_category)