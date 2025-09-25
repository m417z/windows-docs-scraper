# _DXGK_QUERYSEGMENTOUT4 structure

## Description

The **DXGK_QUERYSEGMENTOUT4** structure contains memory segment information returned from the driver.

## Members

### `NbSegment`

Number of elements in the **pSegmentDescriptor** array. The [DxgkDdiQueryAdapterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) (**DXGKQAITYPE_QUERYSEGMENT4**) will be called twice. First time, **NbSegment** will be set to 0. The driver should return **STATUS_SUCCESS** and set **NbSegment** to the number of GPU memory segments in the adapter without accessing any other member of the structure. Second time, the driver will be called with the reported number of segments and the driver should fill all required information.

### `pSegmentDescriptor`

Pointer to the array of [DXGK_SEGMENTDESCRIPTOR4](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_segmentdescriptor4) structures. The size of the array element is defined by **SegmentDescriptorStride**. The **pSegmentDescriptor** type has been changed to a **BYTE*** to help enforce the use of the stride as the method of iterating the array. The driver fills the array with information about each memory segment.

### `PagingBufferSegmentId`

Segment identifier of the paging buffer. This is the index (starting from 1) of the segment in the **pSegmentDescriptor** array.

### `PagingBufferSize`

Paging buffer size.

### `PagingBufferPrivateDataSize`

Size, in bytes, of the driver-private data that will be provided with each paging buffer.

### `SegmentDescriptorStride`

Size of the elements in the **pSegmentDescriptor** array in bytes.

## See also

[DXGK_QUERYSEGMENTIN4](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentin4)