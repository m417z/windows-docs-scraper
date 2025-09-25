# _NDK_CQ_DISPATCH structure

## Description

The **NDK_CQ_DISPATCH** structure specifies dispatch function entry points for the NDK completion queue (CQ) object.

## Members

### `NdkCloseCq`

The entry point for the object's [NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object) dispatch function.

### `NdkQueryExtension`

The entry point for the object's [NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface) dispatch function.

### `NdkResizeCq`

The entry point for the object's [NDK_FN_RESIZE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_resize_cq) dispatch function.

### `NdkArmCq`

The entry point for the object's [NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq) dispatch function.

### `NdkGetCqResults`

The entry point for the object's [NDK_FN_GET_CQ_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_cq_results) dispatch function.

### `NdkControlCqInterruptModeration`

The entry point for the object's [NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_control_cq_interrupt_moderation) dispatch function.

### `NdkGetCqResultsEx`

The entry point for the object's [NDK_FN_GET_CQ_RESULTS_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_cq_results_ex) dispatch function.

**Note** This member is supported only in NDKPI 1.2 (Windows Server 2012 R2) and later.

## Remarks

The **NDK_CQ_DISPATCH** structure is used in the [NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq) structure.

## See also

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_FN_ARM_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_arm_cq)

[NDK_FN_CLOSE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_close_object)

[NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_control_cq_interrupt_moderation)

[NDK_FN_GET_CQ_RESULTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_get_cq_results)

[NDK_FN_QUERY_EXTENSION_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_query_extension_interface)

[NDK_FN_RESIZE_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_resize_cq)