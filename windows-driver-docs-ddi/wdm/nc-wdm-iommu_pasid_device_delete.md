## Description

**IOMMU_PASID_DEVICE_DELETE** deletes a PASID sub-device and frees its ASID.

## Parameters

### `PasidDevice`

[in] Pointer to the IOMMU_DMA_PASID_DEVICE structure that represents the PASID sub-device to be deleted.

## Return value

Returns an NTSTATUS value. Possible values include:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | On successful deletion of the PASID sub-device. |
| **STATUS_RESOURCE_IN_USE** | Device is still attached to a domain. Callers are responsible detaching devices from domains before deleting the device. |

## Remarks

Callers are responsible for detaching devices from domains before deleting the device.

## See also

[**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create)

[**IOMMU_DOMAIN_DETACH_PASID_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_domain_detach_pasid_device)