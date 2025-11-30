## Description

Closes a cloud authentication handle obtained by calling *[WTSCloudAuthOpen](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtscloudauthopen/)*.

## Parameters

### `cloudAuthHandle` [in]

The cloud authentication handle to close.

## Remarks

This function should be called to free resources associated with a cloud authentication handle when it is no longer needed.

## See also