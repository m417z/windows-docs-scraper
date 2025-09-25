# CfGetPlatformInfo function

## Description

Gets version information for the cloud files platform.

## Parameters

### `PlatformVersion` [out]

The platform version information. See [CF_PLATFORM_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_platform_info) for more details.

## Return value

If this function succeeds, it returns `S_OK`. Otherwise, it returns an **HRESULT** error code.

## Remarks

The *platform* is defined as the combination of the filter and the API library, which are always kept in sync with each other. This API is mainly intended for sync providers that run on multiple Windows versions and need to make decisions based on the platform capabilities. The platform version information consists of three parts: build number, revision number, and integration number. The build number and revision number change when the platform is serviced by Windows Update. The integration number on its own is indicative of the platform capability, both in terms of the API contracts and the availability of critical bug fixes. The integration number increments monotonically. The platform never loses capability with the increment of the integration number. Applications that are cloud files aware may also find this API useful.

## See also

[CF_PLATFORM_INFO](https://learn.microsoft.com/windows/win32/api/cfapi/ns-cfapi-cf_platform_info)