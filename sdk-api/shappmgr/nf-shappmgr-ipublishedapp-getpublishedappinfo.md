# IPublishedApp::GetPublishedAppInfo

## Description

Gets publishing-related information about an application published by an application publisher.

## Parameters

### `ppai` [out]

Type: **[PUBAPPINFO](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo)***

A pointer to an [PUBAPPINFO](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo) structure that returns the application information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The dwMask member of the [PUBAPPINFO](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo) structure indicates which members have been requested. Note that Add/Remove Programs will not set the PAI_SCHEDULEDTIME and PAI_EXPIREDTIME bits. However, the corresponding values stScheduled and stExpired will be used when applicable if the implementation provides them. A publisher should provide this data if it is available.

#### Examples

The example shows a sample implementation:

```cpp
HRESULT CPubApp::GetPublishedAppInfo(PUBAPPINFO *pInfo)
{
    if (sizeof(PUBAPPINFO) != pInfo->cbSize)
        return E_FAIL;
		
    // Add/Remove Programs will use these items but will not ask for them.

    pInfo->dwMask |= (PAI_EXPIRETIME | PAI_SCHEDULEDTIME);

    // First save off the mask of requested data items.

    const DWORD dwMask = pInfo->dwMask;

    // Zero-out the mask.  The bits should be set as items are retrieved.

    pInfo->dwMask = 0;

    // Call an internal function that obtains data and sets
    // bits in pInfo->dwMask for each item obtained.

    return get_pub_app_info(pInfo, dwMask);
}

					
```

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IEnumPublishedApps](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ienumpublishedapps)

[IPublishedApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ipublishedapp)

[PUBAPPINFO](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo)