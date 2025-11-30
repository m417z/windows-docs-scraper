## Description

Obtains a cloud authentication handle. To call this function successfully, the calling application must be running within the context of the `NetworkService` or `LocalSystem` account.

## Parameters

### activityId [in]

A pointer to a GUID to uniquely identify events related to this operation in Event Viewer. The caller chooses this GUID for their convenience.

## Return value

If the function succeeds, the return value is a valid cloud authentication handle. It should be closed by calling *[WTSCloudAuthClose](https://learn.microsoft.com/windows/win32/api/wtsapi32/nf-wtsapi32-wtscloudauthclose)*. If the function fails, the return value is `NULL`. To get extended error information, call the [`GetLastError`](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

A cloud authentication handle can be used for remote Entra ID authentication and authorization purposes using the `WTSCloudAuth*` API family.