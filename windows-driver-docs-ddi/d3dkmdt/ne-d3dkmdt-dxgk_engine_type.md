# DXGK_ENGINE_TYPE enumeration

## Description

The **DXGK_ENGINE_TYPE** enumeration indicates the type of engine on a GPU node. Note the selection rules discussed in Remarks.

## Constants

### `DXGK_ENGINE_TYPE_OTHER`

The engine does not match any of the other **DXGK_ENGINE_TYPE** enumeration values. This value is used for proprietary or unique functionality that is not exposed by typical adapters, as well as for an engine that performs work that doesn't fall under another category.

### `DXGK_ENGINE_TYPE_3D`

The adapter's 3-D processing engine. All adapters that are not a display-only device have one 3-D engine.

### `DXGK_ENGINE_TYPE_VIDEO_DECODE`

The engine that handles video decoding, including decompression of video frames from an input stream into typical YUV surfaces.

The workload packets for an H.264 video codec workload test must appear on either the decode engine or the 3-D engine.

### `DXGK_ENGINE_TYPE_VIDEO_ENCODE`

The engine that handles video encoding, including compression of typical video frames into an encoded video format.

### `DXGK_ENGINE_TYPE_VIDEO_PROCESSING`

The engine that is responsible for any video processing that is done after a video input stream is decoded. Such processing can include RGB surface conversion, filtering, stretching, color correction, deinterlacing, or other steps that are required before the final image is rendered to the display screen.

The workload packets for workload tests must appear on either the video processing engine or the 3-D engine.

### `DXGK_ENGINE_TYPE_SCENE_ASSEMBLY`

The engine that performs vertex processing of 3-D workloads as a preliminary pass prior to the remainder of the 3-D rendering. This engine also stores vertices in bins that tile-based rendering engines use.

### `DXGK_ENGINE_TYPE_COPY`

The engine that is a copy engine used for moving data. This engine can perform subresource updates, blitting, paging, or other similar data handling.

The workload packets for calls to **CopySubresourceRegion** or **UpdateSubResource** methods of Direct3D 10 and Direct3D 11 must appear on either the copy engine or the 3-D engine.

### `DXGK_ENGINE_TYPE_OVERLAY`

The virtual engine that is used to manager overlay operations.

### `DXGK_ENGINE_TYPE_CRYPTO`

The engine that is used for cryptographic operations.

### `DXGK_ENGINE_TYPE_VIDEO_CODEC`

The engine that is used for video codec operations.

### `DXGK_ENGINE_TYPE_MAX`

The maximum value for this enumeration.

## Remarks

The display miniport driver should follow these rules to determine the engine type:

* If the engine performs the adapter's 3-D workloads, the driver must specify only **DXGK_ENGINE_TYPE_3D**. The driver must expose exactly one 3-D engine per adapter.

* If the engine's functionality can be described by any of the **DXGK_ENGINE_TYPE** enumeration values (except for **DXGK_ENGINE_TYPE_OTHER**), the driver must select that value.
* If more than one **DXGK_ENGINE_TYPE** enumeration value describes the engine type, the driver should select the one that reflects the dominant capability of that engine. If two capabilities are roughly equal, such as when an engine is used equally for video decode and encode, than the driver can choose either value.
* If none of the conditions in steps 1-3 are met, only then should the driver select a value of **DXGK_ENGINE_TYPE_OTHER**.

For more information on how to use this enumeration, see [Enumerating GPU engine capabilities](https://learn.microsoft.com/windows-hardware/drivers/display/enumerating-gpu-nodes).