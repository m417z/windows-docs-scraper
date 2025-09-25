# VideoPortGetDmaAdapter function

## Description

The **VideoPortGetDmaAdapter** function returns a pointer to a **VP_DMA_ADAPTER** structure, which is used in subsequent calls to other DMA-related functions.

## Parameters

### `HwDeviceExtension` [in]

Pointer to the miniport driver's device extension.

### `VpDeviceDescription` [in]

Pointer to a [VP_DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_device_description) structure, which describes the attributes of the physical device.

## Return value

**VideoPortGetDmaAdapter** returns a pointer to a [VP_DMA_ADAPTER](https://learn.microsoft.com/previous-versions/ff570570(v=vs.85)) structure on success; if it is unsuccessful in obtaining information about the DMA adapter, it returns **NULL**.

## Remarks

The **VP_DMA_ADAPTER** structure contains attribute information about a particular DMA adapter. This structure is an opaque data type that is used internally by the video port driver.

A video miniport driver should call the video port driver's **VideoPortGetDmaAdapter** to obtain information about a DMA adapter.

```cpp
typedef struct __VP_DMA_ADAPTER* PVP_DMA_ADAPTER;
```

This structure has no public members.

This structure is available in Windows XP and later.

## See also

[VP_DEVICE_DESCRIPTION](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/ns-video-_vp_device_description)

[VideoPortCompleteDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportcompletedma)

[VideoPortPutDmaAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportputdmaadapter)

[VideoPortStartDma](https://learn.microsoft.com/windows-hardware/drivers/ddi/video/nf-video-videoportstartdma)