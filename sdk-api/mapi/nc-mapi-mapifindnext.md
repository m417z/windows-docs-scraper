# MAPIFINDNEXT callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPIFindNext** function retrieves the next (or first) message identifier of a specified type of incoming message.

## Parameters

### `lhSession` [in]

Session handle that represents a Simple MAPI session. The value of the *lhSession* parameter must represent a valid session; it cannot be zero.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call, *ulUIParam* is ignored.

### `lpszMessageType` [in]

Pointer to a string identifying the message class to search. To find an interpersonal message (IPM), specify **NULL** in the *lpszMessageType* parameter or have it point to an empty string. Messaging systems whose only supported message class is IPM can ignore this parameter.

### `lpszSeedMessageID` [in]

Pointer to a string containing the message identifier seed for the request. If the *lpszSeedMessageID* parameter is **NULL** or points to an empty string, **MAPIFindNext** retrieves the first message that matches the type specified in the *lpszMessageType* parameter.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_GUARANTEE_FIFO** | The message identifiers returned should be in the order of time received. **MAPIFindNext** calls can take longer if this flag is set. Some implementations cannot honor this request and return the MAPI_E_NO_SUPPORT value. |
| **MAPI_LONG_MSGID** | The returned message identifier can be as long as 512 characters. If this flag is set, the *lpszMessageID* parameter must be large enough to accommodate 512 characters.<br><br>Older versions of MAPI supported smaller message identifiers (64 bytes) and did not include this flag. **MAPIFindNext** will succeed without this flag set as long as *lpszMessageID* is large enough to hold the message identifier. If *lpszMessageID* cannot hold the message identifier, **MAPIFindNext** will fail. |
| **MAPI_UNREAD_ONLY** | Only unread messages of the specified type should be enumerated. If this flag is not set, **MAPIFindNext** can return any message of the specified type. |

### `ulReserved`

Reserved; must be zero.

### `lpszMessageID` [out]

Pointer to the returned message identifier. The caller is responsible for allocating the memory. To ensure compatibility, allocate 512 characters and set MAPI_LONG_MSGID in the *flFlags* parameter. A smaller buffer is sufficient only if the returned message identifier is always 64 characters or less.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred while matching the message type. The call failed before message type matching could take place. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. No message was found. |
| **MAPI_E_INVALID_MESSAGE** | An invalid message identifier was passed in the *lpszSeedMessageID* parameter. No message was found. |
| **MAPI_E_INVALID_SESSION** | An invalid session handle was passed in the *lhSession* parameter. No message was found. |
| **MAPI_E_NO_MESSAGES** | A matching message could not be found. |
| **SUCCESS_SUCCESS** | The call succeeded and the message identifier was returned. |

## Remarks

The **MAPIFindNext** function allows a client application to enumerate messages of a given type. This function can be called repeatedly to list all messages in the folder. Message identifiers returned from **MAPIFindNext** can be used in other Simple MAPI calls to retrieve message contents and delete messages. This function is for processing incoming messages, not for managing received messages.

**MAPIFindNext** looks for messages in the folder in which new messages of the specified type are delivered. **MAPIFindNext** calls can be made only in the context of a valid Simple MAPI session established with the [MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon) function.

When the *lpszSeedMessageID* parameter is **NULL** or points to an empty string, **MAPIFindNext** returns the message identifier for the first message of the type specified by the *lpszMessageType* parameter. When *lpszSeedMessageID* contains a valid identifier, the function returns the next matching message of the type specified by *lpszMessageType*. Repeated calls to **MAPIFindNext** ultimately result in a return of the MAPI_E_NO_MESSAGES value, which means the enumeration is complete.

Message type matching is done against message class strings. All message types whose names match (up to the length specified in *lpszMessageType*) are returned.

Because message identifiers are messaging system-specific and can be invalidated at any time, message identifiers are valid only for the current session. If the message identifier passed in *lpszSeedMessageID* is invalid, **MAPIFindNext** returns the MAPI_E_INVALID_MESSAGE value.

## See also

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))