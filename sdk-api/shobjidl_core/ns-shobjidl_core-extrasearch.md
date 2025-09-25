# EXTRASEARCH structure

## Description

Used by an [IEnumExtraSearch](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumextrasearch) enumerator object to return information on the search objects supported by a Shell Folder object.

## Members

### `guidSearch`

Type: **GUID**

A search object's GUID.

### `wszFriendlyName`

Type: **WCHAR[80]**

A Unicode string containing the search object's friendly name. It will be used to identify the search engine on the Search Assistant menu.

### `wszUrl`

Type: **WCHAR[2084]**

The URL that will be displayed in the search pane.