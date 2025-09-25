## Description

The **SeLocateProcessImageName** routine returns the full process image name for the specified process.

## Parameters

### `Process`

[in/out] Pointer to the process value for which to acquire the name.

### `pImageFileName`

[out] Pointer to an allocated buffer that receives the full image name of the process. The buffer contains a Unicode string followed by the image name string.

## Return value

**SeLocateProcessImageName** returns an NTSTATUS value such as the following.

| Return code | Description |
| ----------- | ----------- |
| STATUS_SUCCESS | The routine successfully returned the process image name. |
| STATUS_NOT_FOUND | The routine could not find the process image name. |

## Remarks

The caller is responsible for freeing the buffer that **pImageFileName** points to, using the **ExFree*Xxx*** routine that corresponds to the routine used to allocate the buffer.

## See also

[**ExAllocatePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepool2)

[**ExAllocatePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exallocatepoolwithtag)

[**ExFreePool2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepool2)

[**ExFreePoolWithTag**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exfreepoolwithtag)