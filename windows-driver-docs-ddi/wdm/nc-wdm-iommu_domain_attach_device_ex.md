## Description

Attaches an **IOMMU_DMA_DEVICE** to an existing DMA device domain.

## Parameters

### `Domain`

[*In*] A handle to the domain that the **IOMMU_DMA_DEVICE** will attach to.

### `DmaDevice`

[*In*] A pointer to the **IOMMU_DMA_DEVICE** to be attached.

## Return value

**STATUS_SUCCESS** if the operation is successful. Possible error return values include the following status codes.

| Return code | Description |
| --- | --- |
| **STATUS_INSUFFICIENT_RESOURCES** | The routine failed to allocate required resources. |
| **STATUS_INVALID_PARAMETER** | The device is already attached to a domain. |
| **STATUS_ACCESS_DENIED** | The device is currently not allowed to attach to this domain type. |

For more information, see [NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values).

## Remarks

The caller is responsible for ensuring that the **IOMMU_DMA_DEVICE** is first detached, using [**IOMMU_DOMAIN_DETACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device_ex), from any previously attached domain before attempting to attach it to another domain.

It is the driver's responsibility to ensure that this function is not called concurrently with any [**IOMMU_DOMAIN_DETACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device_ex) or [**IOMMU_SET_DEVICE_FAULT_REPORTING_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_set_device_fault_reporting_ex) calls on the same device.

If `STATUS_ACCESS_DENIED` is returned, then it is likely the domain type is not currently available for the device to attach to. It is recommended to utilize [**IOMMU_DEVICE_QUERY_DOMAIN_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_query_domain_types) to determine what domain types are available for the specified device. The types available can vary depending on the DMA Guard policy and the device characteristics. To be notified of when domain types are available, consider using [**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback) to register a notification callback whenever the available domain types change.

## See also

[**IOMMU_DOMAIN_DETACH_DEVICE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_device_ex)

[**IOMMU_SET_DEVICE_FAULT_REPORTING_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_set_device_fault_reporting_ex)

[**IOMMU_DEVICE_QUERY_DOMAIN_TYPES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_device_query_domain_types)

[**IOMMU_REGISTER_INTERFACE_STATE_CHANGE_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_register_interface_state_change_callback)

[**DMA_IOMMU_INTERFACE_V2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_v2)

[**DMA_IOMMU_INTERFACE_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-dma_iommu_interface_ex)