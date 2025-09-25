## Description

**IOMMU_DOMAIN_DETACH_PASID_DEVICE** detaches a PASID sub-device from the domain it is currently attached to.

## Parameters

### `PasidDevice`

[in] Pointer to the IOMMU_DMA_PASID_DEVICE structure that represents the PASID sub-device to be detached.

## Return value

Returns an NTSTATUS value. Possible values include:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | On successful sub-device detachment from the domain. |
| **STATUS_INVALID_PARAMETER_1** | The sub-device could not be detached because it was never attached. |

## Remarks

It is the driver's responsibility to ensure that this function is not called concurrently with any of the following on the same device:

- [**IOMMU_PASID_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_delete)
- [**IOMMU_DOMAIN_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_delete)
- [**IOMMU_DOMAIN_ATTACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_pasid_device)
- [**IOMMU_DOMAIN_DETACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_pasid_device)

## See also

[**IOMMU_DOMAIN_ATTACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_pasid_device)

[**IOMMU_PASID_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_delete)