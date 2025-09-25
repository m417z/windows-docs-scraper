## Description

Creates an entry identifier for a one-off address.

## Parameters

### `lpszName`

Pointer to a string that specifies the display name of the recipient. The *lpszName* parameter can be NULL.

### `lpszAdrType`

Pointer to a string that specifies the address type of the recipient, such as FAX or SMTP. The *lpszAdrType* parameter cannot be NULL.

### `lpszAddress`

Pointer to a string that specifies the address of the recipient. The *lpszAddress* parameter cannot be NULL.

### `ulFlags`

Value of type ULONG that specifies the bitmask of flags that affect the one-off recipient. The following flags are valid in the Windows Address Book (WAB).

| Flag | Description |
|------|-------------|
| MAPI_SEND_NO_RICH_INFO | Indicates that the recipient cannot handle formatted message content. If **MAPI_SEND_NO_RICH_INFO** is set, MAPI sets the recipient's PR_SEND_RICH_INFO property to FALSE. If **MAPI_SEND_NO_RICH_INFO** is not set, MAPI sets this property to TRUE unless the recipient's messaging address (to which *lpszAddress* points) is interpreted to be an Internet address. In this case, MAPI sets PR_SEND_RICH_INFO to FALSE. |
| MAPI_UNICODE | Displays the name, address type, and address in Unicode format. If the **MAPI_UNICODE** flag is not set, these strings are displayed in ANSI format.

### `lpcbEntryID`

Pointer to a variable of type ULONG that specifies the count of bytes in the entry identifier to which the *lppEntryID* parameter points.

### `lppEntryID`

Address of a pointer to a variable of type **ENTRYID** that receives the entry identifier for the one-off recipient.

## Return value

HRESULT

## Remarks

## See also