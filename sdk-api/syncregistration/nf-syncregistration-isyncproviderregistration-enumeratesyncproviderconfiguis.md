# ISyncProviderRegistration::EnumerateSyncProviderConfigUIs

## Description

Returns an [IEnumSyncProviderConfigUIInfos](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderconfiguiinfos) enumeration interface that enumerates all registered **ISyncProviderConfigUIInfo** objects for the specified criteria.

## Parameters

### `pguidContentType` [in]

The LPCGUID of the specified content type. If this parameter is **NULL**, all content types will be enumerated.

### `dwSupportedArchitecture` [in]

One, or a combination of, the following flags that represent the architectures of the providers to be enumerated. If **SYNC_32_BIT_SUPPORTED** is specified, all providers that support 32 bits or 32 and 64 bits will be enumerated. If **SYNC_32_BIT_SUPPORTED** | **SYNC_64_BIT_SUPPORTED** is specified, only those providers that support both 32 bits and 64 bits will be enumerated.

* **SYNC_32_BIT_SUPPORTED** ((DWORD)0x00000001)
* **SYNC_64_BIT_SUPPORTED** ((DWORD)0x00000002)

If this parameter is set to zero, synchronization providers for all architectures will be enumerated.

### `ppEnumSyncProviderConfigUIInfos`

A reference to an **IEnumSyncProviderConfigUIInfos**

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to register the provider. |

## See also

[IEnumSyncProviderInfos Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderinfos)

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)