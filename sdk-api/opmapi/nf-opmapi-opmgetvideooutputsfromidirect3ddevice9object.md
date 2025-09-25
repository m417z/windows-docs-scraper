# OPMGetVideoOutputsFromIDirect3DDevice9Object function

## Description

Creates an Output Protection Manager (OPM) object for each physical monitor that is associated with a particular Direct3D device.

## Parameters

### `pDirect3DDevice9` [in]

Pointer to the **IDirect3DDevice9** interface of a Direct3D device.

### `vos` [in]

A member of the [OPM_VIDEO_OUTPUT_SEMANTICS](https://learn.microsoft.com/windows/desktop/api/opmapi/ne-opmapi-opm_video_output_semantics) enumeration.

| Value | Meaning |
| --- | --- |
| **OPM_VOS_OPM_SEMANTICS** | The returned [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointers will use OPM semantics. |
| **OPM_VOS_COPP_SEMANTICS** | The returned [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointers will use Certified Output Protection Protocol (COPP) semantics. |

### `pulNumVideoOutputs` [out]

Receives the number of [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointers returned in the *pppOPMVideoOutputArray* parameter.

### `pppOPMVideoOutputArray` [out]

Receives a pointer to an array of [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointers. Each **IOPMVideoOutput** pointer is associated with a single physical monitor. The caller must release each pointer in the array, and call [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the array.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

A single Direct3D device can be associated with several physical monitors. Each physical monitor has its own connector. The application must set the protection mechanism individually for each physical monitor, by using the [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) pointers returned in *pppOPMVideoOutputArray*.

The [IOPMVideoOutput](https://learn.microsoft.com/windows/desktop/api/opmapi/nn-opmapi-iopmvideooutput) interface has two modes of behavior, depending on the value of the *vos* parameter. If *vos* is OPM_VOS_COPP_SEMANTICS, **IOPMVideoOutput** uses COPP semantics. This mode is intended for backward compatibility with COPP. If *vos* is OPM_VOS_OPM_SEMANTICS, **IOPMVideoOutput** uses the newer OPM semantics. Differences in behavior are noted on the reference page for each method. The mode does not change during the lifetime of the object.

## See also

[OPM Functions](https://learn.microsoft.com/windows/desktop/medfound/opm-functions)