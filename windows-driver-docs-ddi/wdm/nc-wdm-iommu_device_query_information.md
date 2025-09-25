## Description

**IOMMU_DEVICE_QUERY_INFORMATION** takes an IOMMU_DMA_DEVICE token and returns the device info.

## Parameters

### `DmaDevice`

[in] Pointer to the IOMMU_DMA_DEVICE token.

### `Size`

[in] Supplies the size in bytes of the provided buffer.

### `BytesWritten`

[out] Pointer to receive the number of bytes written to the buffer.

### `Buffer`

[out] Pointer to a [**IOMMU_DMA_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_device_information) structure that receives the device information.

## Return value

Returns an NTSTATUS value. Possible values include:

| Return code | Description |
|--|--|
| **STATUS_SUCCESS** | If the device info was successfully written into the buffer. |
| **STATUS_BUFFER_TOO_SMALL** | If the provided buffer does not meet minimum size requirements. |

## Remarks

## See also

[**IOMMU_PASID_DEVICE_CREATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-iommu_pasid_device_create)

[**IOMMU_DMA_DEVICE_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-iommu_dma_device_information)