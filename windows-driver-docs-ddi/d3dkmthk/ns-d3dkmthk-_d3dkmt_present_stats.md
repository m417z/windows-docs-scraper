# _D3DKMT_PRESENT_STATS structure

## Description

The D3DKMT_PRESENT_STATS structure describes present status for a rendering device.

## Members

### `PresentCount` [out]

A UINT value that indicates the number of times that the OpenGL installable client driver (ICD) called the [D3DKMTPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtpresent) function on a rendering device or swap chain. After the maximum value is reached, **PresentCount** starts over at zero. When a new rendering device is created, **PresentCount** is initialized to zero. The operating system maintains a present counter for each swap chain that is created.

### `PresentRefreshCount` [out]

A UINT value that indicates the number of times the display controller outputs a new video frame, which occurs at the beginning of each vertical retrace period. The operating system maintains a present refresh counter for each video display controller output in the operating system. **PresentRefreshCount** is initialized to an unspecified value.

### `SyncRefreshCount` [out]

A UINT value that indicates the number of the most recent capture of the timing information in the **SyncQPCTime** and **SyncGPUTime** members.

### `SyncQPCTime` [out]

The computer processing unit (CPU) time that the current video frame was output at (that is, the CPU time that the vertical retrace started).

### `SyncGPUTime` [out]

The graphics processing unit (GPU) time that the current video frame was output at (that is, the GPU time that the vertical retrace started).

## Remarks

When a present operation is retired, the operating system maintains a correspondence (mapping) between the value in **PresentCount** and the value in **PresentRefreshCount**; that is, when the operating system finishes a present operation as a scanned out video frame, the value in **PresentRefreshCount** that the present operation was finished with is associated with the value in **PresentCount** of the retired present operation.

The operating system maintains timing information within a rendering device and associates the timing information with a display output. When the GPU can maintain the GPU time (**SyncGPUTime**), the GPU time operates at a device-specific frequency. To let applications relate GPU time to other operations in the system, the operating system maintains a correspondence between GPU time and CPU time (**SyncQPCTime**). When the GPU cannot maintain such GPU time, the operating system maintains only CPU time and the associated GPU time is always zero.

Present statistics cannot work for windowed-mode devices. For windowed mode, each structure member is set to zero.

**Note** The operating system might not update the **SyncRefreshCount**, **SyncQPCTime**, and **SyncGPUTime** members on every frame.

## See also

[D3DKMTPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtpresent)

[D3DKMT_DEVICEPRESENT_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_devicepresent_state)