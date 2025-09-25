# SyncProviderConfiguration structure

## Description

Represents the information for a synchronization provider configuration. This structure is passed to the [ISyncProviderRegistration::CreateSyncProviderRegistrationInstance](https://learn.microsoft.com/windows/win32/api/syncregistration/nf-syncregistration-isyncproviderregistration-createsyncproviderregistrationinstance) method when a registration instance is created.

## Members

### `dwVersion`

The version of the synchronization provider. The constant value **SYNC_PROVIDER_CONFIGURATION_VERSION.**

### `guidInstanceId`

The unique instance ID of the synchronization provider.

### `clsidProvider`

The COM CLSID of the synchronization provider.

### `guidConfigUIInstanceId`

The instance ID of the configuration UI used to create this synchronization provider, or **GUID_NULL** if no configuration UI was used.

### `guidContentType`

The GUID that identifies the content type.

### `dwCapabilities`

One of the following constants that represent the capabilities of the synchronization provider.

* **SPC_DEFAULT** ((DWORD)0x00000000)

### `dwSupportedArchitecture`

One of the following constants that represent the architectures supported by the synchronization provider. This value corresponds to the architectures that the synchronization provider CLSID (**clsidProvider**) is registered for. These values can be combined, and can be used as bitmasks.

* **SYNC_32_BIT_SUPPORTED** ((DWORD)0x00000001)
* **SYNC_64_BIT_SUPPORTED** ((DWORD)0x00000002)

## See also

[Windows Sync Registration Structures](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-registration-structures)