# SyncProviderConfigUIConfiguration structure

## Description

Represents the information for a synchronization provider configuration UI.

## Members

### `dwVersion`

The version of the configuration UI.

### `guidInstanceId`

The unique instance ID of the configuration UI.

### `clsidConfigUI`

The COM CLSID of the configuration UI.

### `guidContentType`

The GUID that identifies the content type supported by the synchronization provider that is created by the configuration UI.

### `dwCapabilities`

One of the following constants that represent the capabilities of the synchronization provider configuration UI. These values are masks that can be combined.

* **SCC_DEFAULT** ((DWORD)0x00000000) The configuration UI supports the default capabilities of creating and modifying a synchronization provider with a UI displayed.
* **SCC_CAN_CREATE_WITHOUT_UI** ((DWORD)0x00000001) The configuration UI creates providers without displaying the UI. This value is not compatible with **SCC_CREATE_NOT_SUPPORTED**.
* **SCC_CAN_MODIFY_WITHOUT_UI** ((DWORD)0x00000002) The configuration UI modifies providers without displaying the UI. This value is not compatible with **SCC_MODIFY_NOT_SUPPORTED**.
* **SCC_CREATE_NOT_SUPPORTED** ((DWORD)0x00000004) The configuration UI cannot create new configured providers. This value is not compatible with **SCC_CAN_CREATE_WITHOUT_UI**.
* **SCC_MODIFY_NOT_SUPPORTED** ((DWORD)0x00000008) The configuration UI cannot modify providers. This value is not compatible with **SCC_CAN_MODIFY_WITHOUT_UI**.

### `dwSupportedArchitecture`

One of the following constants that represent the architectures supported by the synchronization provider configuration UI. This value corresponds to the architectures that the synchronization provider configuration UI CLSID (**clsidConfigUI**) is registered for. These values can be combined, and can be used as bitmasks.

* **SYNC_32_BIT_SUPPORTED** ((DWORD)0x00000001)
* **SYNC_64_BIT_SUPPORTED** ((DWORD)0x00000002)

### `fIsGlobal`

Reserved for future use. At this time, the value should always be **FALSE**.

## See also

[Windows Sync Registration Structures](https://learn.microsoft.com/previous-versions/windows/desktop/winsync/windows-sync-registration-structures)