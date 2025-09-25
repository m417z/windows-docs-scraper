# CF_PLATFORM_INFO structure

## Description

Returns information for the cloud files platform. This is intended for sync providers running on multiple versions of Windows.

## Members

### `BuildNumber`

The build number of the Windows platform version. Changes when the platform is serviced by a Windows update.

### `RevisionNumber`

The revision number of the Windows platform version. Changes when the platform is serviced by a Windows update.

### `IntegrationNumber`

The integration number of the Windows platform version. This is indicative of the platform capabilities, both in terms of API contracts and availability of bug fixes.

## Remarks

The platform is a combination of the cloud filter and the placeholder files API library, which are always kept in sync with each other. This API is intended for sync providers that need to make decisions based on the platform capabilities of multiple versions of Windows.

If you are building an app that uses or is aware of placeholder files, this may be useful to you.

## See also

[CfGetPlatformInfo](https://learn.microsoft.com/windows/win32/api/cfapi/nf-cfapi-cfgetplatforminfo)