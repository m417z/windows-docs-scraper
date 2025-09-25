# SEARCH_ITEM_CHANGE structure

## Description

Specifies the changes to an indexed item.

## Members

### `Change`

Type: **[SEARCH_KIND_OF_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_kind_of_change)**

Flag that specifies the kind of change as a value from the
[SEARCH_KIND_OF_CHANGE](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_kind_of_change) enumerated type.

### `Priority`

Type: **[SEARCH_NOTIFICATION_PRIORITY](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_notification_priority)**

Flag that specifies the priority of processing this change as a value from the [SEARCH_NOTIFICATION_PRIORITY](https://learn.microsoft.com/windows/desktop/api/searchapi/ne-searchapi-search_notification_priority) enumerated type.

### `pUserData`

Type: **BLOB***

Pointer to user information.

### `lpwszURL`

Type: **LPWSTR**

Pointer to a null-terminated Unicode string containing the URL of the item in a SEARCH_CHANGE_MOVE_RENAME, SEARCH_CHANGE_ADD, or SEARCH_CHANGE_MODIFY notification. In the case of a move, this member contains the new URL of the item.

### `lpwszOldURL`

Type: **LPWSTR**

Pointer to a null-terminated Unicode string containing the old URL of the item in a SEARCH_CHANGE_MOVE_RENAME or SEARCH_CHANGE_DELETE notification.