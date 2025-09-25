# NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION callback function

## Description

The *NdkControlCqInterruptModeration* (*NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION*) function controls interrupt moderation on an NDK completion queue (CQ).

For more information about interrupt moderation, see [Interrupt Moderation](https://learn.microsoft.com/windows-hardware/drivers/network/interrupt-moderation).

## Parameters

### `pNdkCq` [in]

A pointer to an NDK completion queue object ([NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)).

### `ModerationInterval` [in]

The maximum number of microseconds that a provider can defer interrupting the host CPU after a completion placed into the CQ satisfies an arm request. If *ModerationInterval* is zero, the provider performs no interrupt moderation on the CQ regardless of the value of the *ModerationCount* parameter. If *ModerationInterval* is MAXULONG, the *ModerationCount* controls the interrupt moderation on the CQ. If *ModerationInterval* is larger than the maximum moderation interval that the adapter supports or if the adapter’s timer granularity is larger, the provider can round down the interval value.

### `ModerationCount` [in]

The maximum number of completions that a provider can accumulate in the CQ before interrupting the host CPU to satisfy a CQ arm request. If *ModerationInterval* is zero or one, the provider performs no interrupt moderation on the CQ regardless of the value of the *ModerationInterval* parameter. If *ModerationCount* is MAXULONG or larger than the depth of the CQ, *ModerationInterval* controls the interrupt moderation on the CQ.

## Return value

The
*NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION* function returns one of the following NTSTATUS codes.

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The operation completed successfully. |
| **STATUS_INSUFFICIENT_RESOURCES** | The request failed due to insufficient resources. |
| **STATUS_NOT_SUPPORTED** | The NDK provider does not support CQ interrupt moderation control with [NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/nc-ndkpi-ndk_fn_control_cq_interrupt_moderation). A provider that sets the NDK_ADAPTER_FLAG_CQ_INTERRUPT_MODERATION_SUPPORT flag in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure's **AdapterFlags** member must not return this status code. |
| **STATUS_INVALID_PARAMETER_MIX** | The NDK consumer provided a MAXULONG for *ModerationInterval* and MAXULONG or a value larger than the number of completion entries that the CQ can hold for *ModerationCount* at the same time. |
| **Other status codes** | An error occurred. |

## Remarks

NDK consumers must not call *NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION* unless the provider sets the NDK_ADAPTER_FLAG_CQ_INTERRUPT_MODERATION_SUPPORTED flag in the [NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info) structure's **AdapterFlags** member. For a provider that sets the NDK_ADAPTER_FLAG_CQ_INTERRUPT_MODERATION_SUPPORTED flag, the NDK consumer can call this function at any point after a CQ is created. The default behavior for a CQ is no interrupt moderation. The NDK consumer must not call this function on the same CQ concurrently.

The NDK consumer must not specify a MAXULONG for *ModerationInterval* and MAXULONG or a value larger than the number of completion entries that the CQ can hold (*CqDepth*) for *ModerationCount* at the same time. Otherwise, the provider will return STATUS_INVALID_PARAMETER_MIX.

The NDK consumer can call *NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION* multiple times. A provider might not apply the settings before returning from this function. However, the provider must not delay the application of the settings indefinitely. If the consumer issues another call to this function while the provider has not yet applied the settings from a previous invocation of the function, the provider must make the most recently provided settings effective as soon as possible. That is, either the provider must cancel the application of the previous settings and apply the new settings, or wait for the application of previous settings to complete and apply the new settings.

Providers that indicate support for interrupt moderation with the NDK_ADAPTER_FLAG_CQ_INTERRUPT_MODERATION_SUPPORTED flag must normally handle *NDK_FN_CONTROL_CQ_INTERRUPT_MODERATION* successfully and return STATUS_SUCCESS. However, a provider can fail the request due to a resource shortage such as a memory allocation failure. In this case, the provider must return STATUS_INSUFFICIENT_RESOURCES. Providers cannot return STATUS_PENDING from this function. Providers that do not indicate support for this function with the NDK_ADAPTER_FLAG_CQ_INTERRUPT_MODERATION_SUPPORTED flag must still implement this function. In this case, this function must return STATUS_NOT_SUPPORTED.

## See also

[NDK_ADAPTER_INFO](https://learn.microsoft.com/windows/win32/api/ndkinfo/ns-ndkinfo-ndk_adapter_info)

[NDK_CQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq)

[NDK_CQ_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndkpi/ns-ndkpi-_ndk_cq_dispatch)