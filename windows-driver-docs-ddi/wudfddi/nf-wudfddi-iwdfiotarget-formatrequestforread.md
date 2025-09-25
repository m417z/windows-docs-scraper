# IWDFIoTarget::FormatRequestForRead

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **FormatRequestForRead** method formats an I/O request object for a read operation.

## Parameters

### `pRequest` [in]

A pointer to the [IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest) interface for the request object to format.

### `pFile` [in, optional]

A pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the file object that is associated with the read request. For the default I/O target, this parameter must be non-NULL.

### `pOutputMemory` [in, optional]

A pointer to the [IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory) interface that is used to access the buffer that is used for the read request. This parameter is optional.

### `pOutputMemoryOffset` [in, optional]

A pointer to a [WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdfmemory_offset) structure that describes the output memory offset that is used for the read. This parameter is optional.

### `DeviceOffset` [in, optional]

A pointer to the device offset that is used for the read. This parameter is optional.

## Return value

**FormatRequestForRead** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## See also

[IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)

[IWDFIoTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiotarget)

[IWDFMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfmemory)

[WDFMEMORY_OFFSET](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wdfmemory_offset)