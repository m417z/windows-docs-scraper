# OPMGetVideoOutputForTarget function

## Description

Returns a video output object for the VidPN target on the specified adapter.

## Parameters

### `pAdapterLuid` [in]

The LUID for the adapter where the target is located.

### `VidPnTarget` [in]

Target ID for the target on the specified adapter.

### `vos` [in]

A member of the [OPM_VIDEO_OUTPUT_SEMANTICS](https://learn.microsoft.com/windows/desktop/api/opmapi/ne-opmapi-opm_video_output_semantics) enumeration.

| Value | Meaning |
| --- | --- |
| **OPM_VOS_OPM_SEMANTICS** | The returned [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointer will use OPM semantics. |
| **OPM_VOS_COPP_SEMANTICS** | The returned [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointer will use Certified Output Protection Protocol (COPP) semantics. |

### `ppOPMVideoOutput` [out]

Receives a pointer to an [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointer. The caller must release this pointer.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) interface has two modes of behavior, depending on the value of the *vos* parameter. If *vos* is **OPM_VOS_COPP_SEMANTICS**, **IOPMVideoOutput** uses COPP semantics. This mode is intended for backward compatibility with COPP. If *vos* is **OPM_VOS_OPM_SEMANTICS**, **IOPMVideoOutput** uses the newer OPM semantics. Differences in behavior are noted on the reference page for each method. The mode does not change during the lifetime of the object.

## See also

[OPM Functions](https://learn.microsoft.com/windows/desktop/medfound/opm-functions)