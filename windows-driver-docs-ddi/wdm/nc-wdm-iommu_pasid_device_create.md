## Description

**IOMMU_PASID_DEVICE_CREATE** takes an IOMMU_DMA_DEVICE token and spawns a new PASID sub-device representing the newly assigned ASID.

## Parameters

### `DmaDevice`

[in] Pointer to the IOMMU_DMA_DEVICE token from which sub-devices are spawned.

[in] Pointer to the IOMMU_DMA_DEVICE token from which sub-devices are spawned.

### `PasidDeviceOut`

[out] Pointer to an opaque IOMMU_DMA_PASID_DEVICE structure that represents the newly created IOMMU DMA PASID sub-device.

### `AsidOut`

[out] Pointer to hold the system-assigned PASID.

## Return value

**IOMMU_PASID_DEVICE_CREATE** returns an NTSTATUS value. Possible values include:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | The sub-device was successfully created. **PasidDeviceOut** returns a valid pointer. |
| **STATUS_INVALID_PARAMETER_1** | The provided device token is not configured for PASID-tagged DMA or PASIDs are not supported. |
| **STATUS_INSUFFICIENT_RESOURCES** | Not enough memory to allocate an IOMMU_DMA_PASID_DEVICE structure. |
| **STATUS_NONE_MAPPED** | An ASID could not be allocated. |

## Remarks

## See also

[**IOMMU_PASID_DEVICE_DELETE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_delete)

[**IOMMU_DOMAIN_ATTACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_attach_pasid_device)

[**IOMMU_DOMAIN_DETACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_pasid_device)