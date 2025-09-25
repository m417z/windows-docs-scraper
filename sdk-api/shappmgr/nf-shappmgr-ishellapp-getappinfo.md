# IShellApp::GetAppInfo

## Description

Gets general information about an application.

## Parameters

### `pai` [out]

Type: **[APPINFODATA](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-appinfodata)***

A pointer to an [APPINFODATA](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-appinfodata) structure that returns the application information.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**Note** Add/Remove Programs in the Control Panel sets the cbSize and dwMask members of the [APPINFODATA](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-appinfodata) structure.

Your implementation should validate cbSize by comparing it with the size of [APPINFODATA](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-appinfodata). If cbSize does not equal the size of **APPINFODATA**, this method should return a COM error value like E_FAIL.

Add/Remove Programs in the Control Panel will set the dwMask member of the [APPINFODATA](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-appinfodata) structure to indicate that you should return AIM_DISPLAYNAME and AIM_SUPPORTURL. For each value that you return in APPINFODATA, you must set the corresponding bit in dwMask. All other bits should be cleared.

#### Examples

Here is a sample of how to use the dwMask bits::

```cpp
HRESULT CPubApp::GetAppInfo(APPINFODATA *pData)
{
    if (sizeof(APPINFODATA) != pData->cbSize)
        return E_FAIL;

    // First save off the mask of requested data items.

    const DWORD dwMask = pData->dwMask;

    // Zero-out the mask.  Bits will be set as items are obtained.

    pData->dwMask = 0;

    // Call an internal function that obtains data and sets
    // bits in pData->dwMask for each item obtained.

    return get_app_info_data(pData, dwMask);

}
```

## See also

[APPINFODATA](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-appinfodata)

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)

[IPublishedApp::GetPublishedAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-getpublishedappinfo)

[IShellApp](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-ishellapp)