# D3D12_FEATURE_VIDEO enumeration

## Description

Specifies a Direct3D 12 video feature or feature set to query about. When you want to query for the level to which an adapter supports a feature, pass one of these values to [ID3D12VideoDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/d3d12video/nf-d3d12video-id3d12videodevice-checkfeaturesupport).

## Constants

### `D3D12_FEATURE_VIDEO_DECODE_SUPPORT`

Check if a decode profile, bitstream encryption, resolution, and format are supported. The result is a [D3D12_VIDEO_DECODE_TIER](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_decode_tier) indicating the level of support. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_DECODE_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_support).

### `D3D12_FEATURE_VIDEO_DECODE_PROFILES`

Retrieve the list of decode profiles supported by the adapter. Call **CheckFeatureSupport** specifying the feature D3D12_FEATURE_VIDEO_DECODE_PROFILE_COUNT to get the number of profiles before calling **CheckFeatureSupport** for the D3D12_FEATURE_VIDEO_DECODE_PROFILES feature. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_DECODE_PROFILES](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_profiles).

### `D3D12_FEATURE_VIDEO_DECODE_FORMATS`

Retrieves the list of supported decode formats for a [D3D12_VIDEO_DECODE_CONFIGURATION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_decode_configuration). Call **CheckFeatureSupport** specifying the feature D3D12_FEATURE_VIDEO_DECODE_FORMAT_COUNT to get the number of profiles before calling **CheckFeatureSupport** for the D3D12_FEATURE_VIDEO_DECODE_PROFILES feature.The associated data structure is [D3D12_FEATURE_DATA_VIDEO_DECODE_FORMATS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_formats).

### `D3D12_FEATURE_VIDEO_DECODE_CONVERSION_SUPPORT`

Check if a colorspace conversion, format conversion, and scale are supported. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_DECODE_CONVERSION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_conversion_support).

### `D3D12_FEATURE_VIDEO_PROCESS_SUPPORT`

Retrieves the video processor capabilities. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_PROCESS_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_process_support).

### `D3D12_FEATURE_VIDEO_PROCESS_MAX_INPUT_STREAMS`

Retrieves the maximum number of streams that can be enabled at the same time. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_PROCESS_MAX_INPUT_STREAMS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_process_max_input_streams).

### `D3D12_FEATURE_VIDEO_PROCESS_REFERENCE_INFO`

Retrieves the number of past and future frames required for a given deinterlace mode, filters, frame rate conversion, and features. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_PROCESS_REFERENCE_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_process_reference_info).

### `D3D12_FEATURE_VIDEO_DECODER_HEAP_SIZE`

Checks the allocation size of a video decoder heap. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_DECODER_HEAP_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decoder_heap_size). For information on residency budgeting for heaps, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `D3D12_FEATURE_VIDEO_PROCESSOR_SIZE`

Checks the allocation size of a video processor heap. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_PROCESSOR_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_processor_size). For information on residency budgeting for heaps, see [Residency](https://learn.microsoft.com/windows/win32/direct3d12/residency).

### `D3D12_FEATURE_VIDEO_DECODE_PROFILE_COUNT`

Retrieves the number of supported decoder profiles. The returned count is used when querying for **D3D12_FEATURE_VIDEO_DECODE_PROFILES**.

### `D3D12_FEATURE_VIDEO_DECODE_FORMAT_COUNT`

Retrieves the number of supported decoder profiles. The returned count is used when querying for **D3D12_FEATURE_VIDEO_DECODE_FORMATS**.

### `D3D12_FEATURE_VIDEO_ARCHITECTURE`

Indicates if the video engine is IO coherent with the CPU.

### `D3D12_FEATURE_VIDEO_DECODE_HISTOGRAM`

Retrieves the supported components, bin count, and counter bit depth for the a decode histogram with the specified decode profile, resolution, and format. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_DECODE_HISTOGRAM](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_decode_histogram).

### `D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR:20`

Retrieves the supported resolutions, search block sizes, and precision for motion estimation. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_MOTION_ESTIMATOR](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_motion_estimator).

### `D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR_SIZE:21`

Checks the allocation size of a motion estimator heap. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_MOTION_ESTIMATOR_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_motion_estimator_size).

### `D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_COUNT:22`

Retrieves the supported number of video extension commands. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_command_count).

### `D3D12_FEATURE_VIDEO_EXTENSION_COMMANDS:23`

Retrieves a list of [D3D12_VIDEO_EXTENSION_COMMAND_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_extension_command_info) structures describing video extension commands. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_command_count).

### `D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT:24`

Retrieves the parameter count for the specified parameter stage. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_PARAMETER_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_command_parameter_count).

### `D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_PARAMETERS:25`

Retrieves a list of [D3D12_VIDEO_EXTENSION_COMMAND_PARAMETER_INFO](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_video_extension_command_parameter_info) structures describing video extension command parameters for the specified parameter stage. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_PARAMETERS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_command_parameters).

### `D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_SUPPORT:26`

Queries for command-defined support information. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_command_support).

### `D3D12_FEATURE_VIDEO_EXTENSION_COMMAND_SIZE:27`

Checks the allocation size of a video extension command. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_EXTENSION_COMMAND_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_extension_command_size).

### `D3D12_FEATURE_VIDEO_MOTION_ESTIMATOR_PROTECTED_RESOURCES:30`

Checks support for motion estimation with protected resources. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_MOTION_ESTIMATOR_PROTECTED_RESOURCES](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_motion_estimator_protected_resources).

## Remarks

| Field | Value | Description |
|-----------|-----------|------------|
| D3D12_FEATURE_VIDEO_ENCODER_CODEC | 33 | Checks support for a given codec. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_CODEC](https://learn.microsoft.com/windows/win32/api/d3d12video/ne-d3d12video-d3d12_video_encoder_levels_hevc).|
| D3D12_FEATURE_VIDEO_ENCODER_PROFILE_LEVEL | 34 | Checks support for a given profile and returns the supported levels range for that profile. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_PROFILE_LEVEL](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_profile_level).|
| D3D12_FEATURE_VIDEO_ENCODER_OUTPUT_RESOLUTION_RATIOS_COUNT | 35 | Checks support for the number of resolution ratios available. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_OUTPUT_RESOLUTION_RATIOS_COUNT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_output_resolution_ratios_count).|
| D3D12_FEATURE_VIDEO_ENCODER_OUTPUT_RESOLUTION | 36 | Checks support for the rules that resolutions must meet. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_OUTPUT_RESOLUTION](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_output_resolution).|
| D3D12_FEATURE_VIDEO_ENCODER_INPUT_FORMAT | 37 | Checks support for a given input format. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_INPUT_FORMAT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_input_format).|
| D3D12_FEATURE_VIDEO_ENCODER_RATE_CONTROL_MODE | 38 | Checks support for a given rate control mode. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_RATE_CONTROL_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_rate_control_mode).|
| D3D12_FEATURE_VIDEO_ENCODER_INTRA_REFRESH_MODE | 39 | Checks support for a given intra refresh mode. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_INTRA_REFRESH_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_intra_refresh_mode).|
| D3D12_FEATURE_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE | 40 | Checks support for a given subregion layout mode. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_FRAME_SUBREGION_LAYOUT_MODE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_frame_subregion_layout_mode).|
| D3D12_FEATURE_VIDEO_ENCODER_HEAP_SIZE | 41 | Retrieves the memory requirements of a video encoder heap created with the given encoder heap properties. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_HEAP_SIZE](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_heap_size).|
| D3D12_FEATURE_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT | 42 | Retrieves a set of codec specific configuration limits. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_CODEC_CONFIGURATION_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_codec_configuration_support).|
| D3D12_FEATURE_VIDEO_ENCODER_SUPPORT | 43 | Retrieves the feature support details on the requested configuration. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_support).|
| D3D12_FEATURE_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT | 44 | Retrieves the codec specific capabilities related to the reference picture management limitations. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_CODEC_PICTURE_CONTROL_SUPPORT](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_codec_picture_control_support).|
| D3D12_FEATURE_VIDEO_ENCODER_RESOURCE_REQUIREMENTS | 45 | Retrieves the requirements for alignment for resource access. The associated data structure is [D3D12_FEATURE_DATA_VIDEO_ENCODER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows/win32/api/d3d12video/ns-d3d12video-d3d12_feature_data_video_encoder_resource_requirements).|

## See also