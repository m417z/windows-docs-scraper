# WMDRMNET\_POLICY structure

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **WMDRMNET\_POLICY** structure contains the policy to be used for Windows Media DRM for Network Devices operations.

## Members

**ePolicyType**

Member of the [**WMDRMNET\_POLICY\_TYPE**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy-type) enumeration that specifies the type of policy.

**pbPolicy**

Buffer containing the policy. The only type of policy currently supported is **WMDRMNET\_POLICY\_TYPE\_TRANSCRYPTPLAY**. This member is a pointer to a **WMDRMNET\_POLICY\_TRANSCRYPTPLAY** structure.

## Remarks

This structure is used as a parameter for the [**IWMDRMNetTransmitter::GetLeafLicenseResponse**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmnettransmitter-getleaflicenseresponse) method.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmformat/drm-structures)

[**WMDRMNET\_POLICY\_GLOBAL\_REQUIREMENTS**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy-global-requirements)

[**WMDRMNET\_POLICY\_MINIMUM\_ENVIRONMENT**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy-minimum-environment)

[**WMDRMNET\_POLICY\_TRANSCRYPTPLAY**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy-transcryptplay)

[**WMDRMNET\_POLICY\_TYPE**](https://learn.microsoft.com/windows/win32/wmformat/wmdrmnet-policy-type)

