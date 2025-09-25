## Description

**IOMMU_DOMAIN_ATTACH_PASID_DEVICE** attaches a PASID sub-device to an existing domain.

## Parameters

### `Domain`

[in] Handle to the domain that the sub-device will attach to.

### `PasidDevice`

[in] Pointer to the IOMMU_DMA_PASID_DEVICE structure that represents the PASID sub-device to be attached.

## Return value

Returns an NTSTATUS value. Possible values include:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | On successful sub-device attachment to the domain. |
| **STATUS_INSUFFICIENT_RESOURCES** | Not enough memory to allocate a cached device for attach/detach bookkeeping. |
| **STATUS_INVALID_PARAMETER_1** | The device is not allowed to attach to the domain type provided. |
| **STATUS_UNSUCCESSFUL** | The sub-device is already attached to a domain. |
| **STATUS_ACCESS_DENIED** | The sub-device is currently not allowed to attach to this domain. |

## Remarks

It is the driver's responsibility to ensure that this function is not called concurrently with any of the following on the same device:

- [**IOMMU_PASID_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_delete)
- [**IOMMU_DOMAIN_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_delete)
- [**IOMMU_DOMAIN_ATTACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_pasid_device)
- [**IOMMU_DOMAIN_DETACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_pasid_device)

## See also

[**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create)

[**IOMMU_DOMAIN_DETACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_pasid_device)