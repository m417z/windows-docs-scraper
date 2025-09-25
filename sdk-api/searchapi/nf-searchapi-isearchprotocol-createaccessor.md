# ISearchProtocol::CreateAccessor

## Description

Creates and initializes an [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object.

## Parameters

### `pcwszURL` [in]

Type: **LPCWSTR**

Pointer to a null-terminated Unicode string containing the URL of the item being accessed.

### `pAuthenticationInfo` [in]

Type: **[AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-authentication_info)***

Pointer to an [AUTHENTICATION_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-authentication_info) structure that contains authentication information necessary for accessing this item in the content source.

### `pIncrementalAccessInfo` [in]

Type: **[INCREMENTAL_ACCESS_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-incremental_access_info)***

Pointer to an [INCREMENTAL_ACCESS_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-incremental_access_info) structure that contains incremental access information, such as the last time the file was accessed by the gatherer.

### `pItemInfo` [in]

Type: **[ITEM_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-item_info)***

Pointer to an [ITEM_INFO](https://learn.microsoft.com/windows/desktop/api/searchapi/ns-searchapi-item_info) structure that contains information about the URL item, such as the name of the item's workspace catalog.

### `ppAccessor` [out]

Type: **[IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor)****

Receives the address of a pointer to the [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object created by this method. This object contains information about the URL item, such as the item's file name.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The protocol host calls this method on the protocol handler once for every URL processed by the gatherer and retrieves a pointer to the [IUrlAccessor](https://learn.microsoft.com/windows/desktop/api/searchapi/nn-searchapi-iurlaccessor) object. This method creates and initializes an **IUrlAccessor** object to process an item currently being accessed by the gatherer.