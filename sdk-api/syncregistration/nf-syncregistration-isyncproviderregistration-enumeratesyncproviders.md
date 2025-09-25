# ISyncProviderRegistration::EnumerateSyncProviders

## Description

Returns an [IEnumSyncProviderInfos](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderinfos) enumeration interface that enumerates all registered **ISyncProviderInfo** objects for the specified criteria.

## Parameters

### `pguidContentType` [in]

The LPCGUID of the specified content type. If this parameter is **NULL**, all content types will be enumerated.

### `dwStateFlagsToFilterMask` [in]

A synchronization provider state flag that can be used to mask (preserve or remove) the existing state. If this parameter is set to zero, all synchronization provider states will be enumerated. See the *dwStateFlagsToFilter* parameter description for a list of flags.

### `dwStateFlagsToFilter` [in]

One of the following flags that represent the synchronization provider state.

* **SYNC_PROVIDER_STATE_ENABLED** ((DWORD)0x00000001)The provider is enabled and available for synchronization.
* **SYNC_PROVIDER_STATE_DIRTY** ((DWORD)0x00000002)The active provider has been updated and has new data to synchronize.

If this parameter is set to zero, all synchronization provider states will be enumerated.

### `refProviderClsId` [in]

The REFCLSID of a particular provider. If this parameter is set to **CLSID_NULL**, all providers will be enumerated.

### `dwSupportedArchitecture` [in]

One, or a combination of, the following flags that represent the architectures of the providers to be enumerated. If **SYNC_32_BIT_SUPPORTED** is specified, all providers that support 32 bits or 32 and 64 bits will be enumerated. If **SYNC_32_BIT_SUPPORTED** | **SYNC_64_BIT_SUPPORTED** is specified, only those providers that support both 32 bits and 64 bits will be enumerated.

* **SYNC_32_BIT_SUPPORTED** ((DWORD)0x00000001)
* **SYNC_64_BIT_SUPPORTED** ((DWORD)0x00000002)

If this parameter is set to zero, synchronization providers for all architectures will be enumerated.

### `ppEnumSyncProviderInfos` [out]

The **IEnumSyncProviderInfos** enumeration interface that will enumerate all **ISyncProviderInfo** objects that match the specified criteria.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** | There was not enough memory available to return the enumeration interface. |

## See also

[IEnumSyncProviderInfos Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-ienumsyncproviderinfos)

[ISyncProviderRegistration Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/syncregistration/nn-syncregistration-isyncproviderregistration)