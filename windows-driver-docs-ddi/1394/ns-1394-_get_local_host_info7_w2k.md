# _GET_LOCAL_HOST_INFO7_W2K structure

## Description

The GET_LOCAL_HOST_INFO7 structure contains the data returned by a [REQUEST_GET_LOCAL_HOST_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) request with **u.GetLocalHostInformation.nLevel** set to GET_HOST_DMA_CAPABILITIES.

## Members

### `HostDmaCapabilities`

Always set to zero.

### `MaxDmaBufferSize`

Specifies the maximum size of a single DMA transfer on the 1394 host controller. A value of 0x80001000 indicates that there is no specific maximum size. Otherwise, the value of MaxDmaBufferSize reflects the number of Map Registers that are available to the 1394 host controller to map DMA transfers. MaxDmaBufferSize is the upper limit for the size of the buffer that is described in a single [ISOCH_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_isoch_descriptor).

### `MaxOutstandingXmitRequests`

### `MaxOutstandingXmitResponses`