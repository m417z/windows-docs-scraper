## Description

Contains information used to handle an [EN_SEARCHWEB](https://learn.microsoft.com/windows/win32/controls/en-searchweb) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-nmhdr)**

An NMHDR structure that contains additional information about this notification.

### `entrypoint`

Type: **[EC_SEARCHWEB_ENTRYPOINT](https://learn.microsoft.com/windows/win32/api/commctrl/ne-commctrl-ec_searchweb_entrypoint)**

An enum value that indicates the entry point of the search.

### `hasQueryText`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

TRUE if there is query text; otherwise, FALSE.

### `invokeSucceeded`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

TRUE if the invoke succeeded; otherwise, FALSE.

## Remarks

## See also

[EN_SEARCHWEB](https://learn.microsoft.com/windows/win32/controls/en-searchweb)