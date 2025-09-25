# IMDSPDevice3::FindStorage

## Description

The **FindStorage** method finds a storage with the given persistent unique identifier. The persistent unique identifier of a storage is described by the **g_wszWMDMPersistentUniqueID** property of that storage.

## Parameters

### `findScope` [in]

Scope of the find operation. It must be one of the following values.

| Value | Description |
| --- | --- |
| WMDM_FIND_SCOPE_GLOBAL | Search the whole device. |
| WMDM_FIND_SCOPE_IMMEDIATE_CHILDREN | Search only in the immediate children of the current storage. |

### `pwszUniqueID` [in]

Persistent unique identifier of the storage.

### `ppStorage` [out]

Pointer to the returned storage specified by the *pwszUniqueID* parameter.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The service provider returns a persistent unique identifier through the **g_wszWMDMPersistentUniqueID** property of the storage. For a specific storage, the persistent unique identifier supplied by service provider should be same across different device connect sessions.

The application may call **FindStorage** with this persistent unique identifier at a later point. In response, Windows Media Device Manager calls this method on the service provider (SP).

A persistent unique identifier is used to uniquely identify content stored on a particular device. It does not represent a content-specific globally unique identifier that remains identical across all devices. Thus, the same content stored in different storages will have different persistent unique identifiers.

Windows Media Device Manager calls this method only for devices that are registered to enable synchronization with Windows Media Player. For more information, see [Enabling Synchronization with Windows Media Player](https://learn.microsoft.com/windows/desktop/WMDM/enabling-synchronization-with-windows-media-player).

## See also

[Enabling Synchronization with Windows Media Player](https://learn.microsoft.com/windows/desktop/WMDM/enabling-synchronization-with-windows-media-player)

[IMDSPDevice3 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice3)

[IMDSPStorage3::GetMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage3-getmetadata)

[IMDSPStorage4::FindStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage4-findstorage)

[IMDSPStorage4::GetSpecifiedMetadata](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage4-getspecifiedmetadata)

[Metadata Constants](https://learn.microsoft.com/windows/desktop/WMDM/metadata-constants)

[WMDM_FIND_SCOPE](https://learn.microsoft.com/windows/desktop/WMDM/wmdm-find-scope)