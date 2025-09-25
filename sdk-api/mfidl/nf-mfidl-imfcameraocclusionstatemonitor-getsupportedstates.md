## Description

Gets the occlusion states supported by the current device.

## Return value

A **DWORD** containing a bitwise OR combination of values from the [MFCameraOcclusionState](https://learn.microsoft.com/windows/win32/api/mfidl/ne-mfidl-mfcameraocclusionstate) enumeration.

## Remarks

To get the current occlusion state, call the [IMFCameraOcclusionStateReport::GetOcclusionState](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraocclusionstatereport-getocclusionstate) method on the [IMFCameraOcclusionStateReport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameraocclusionstatereport) passed to the [IMFCameraOcclusionStateReportCallback::OnOcclusionStateReport](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraocclusionstatereportcallback-onocclusionstatereport) callback.

## See also

[IMFCameraOcclusionStateReport](https://learn.microsoft.com/windows/win32/api/mfidl/nn-mfidl-imfcameraocclusionstatereport)
[IMFCameraOcclusionStateReportCallback::OnOcclusionStateReport](https://learn.microsoft.com/windows/win32/api/mfidl/nf-mfidl-imfcameraocclusionstatereportcallback-onocclusionstatereport)