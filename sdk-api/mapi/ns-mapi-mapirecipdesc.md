# MapiRecipDesc structure

## Description

A **MapiRecipDesc** structure contains information about a message sender or recipient. For Unicode support, use the [MapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw) structure.

## Members

### `ulReserved`

Reserved; must be zero.

### `ulRecipClass`

Contains a numeric value that indicates the type of recipient. Possible values are as follow.

| Value | Meaning |
| --- | --- |
| **MAPI_ORIG**<br><br>0 | Indicates the original sender of the message. |
| **MAPI_TO**<br><br>1 | Indicates a primary message recipient. |
| **MAPI_CC**<br><br>2 | Indicates a recipient of a message copy. |
| **MAPI_BCC**<br><br>3 | Indicates a recipient of a blind copy. |

### `lpszName`

Pointer to the display name of the message recipient or sender.

### `lpszAddress`

Optional pointer to the recipient or sender's address; this address is provider-specific message delivery data. Generally, the messaging system provides such addresses for inbound messages. For outbound messages, the **lpszAddress** member can point to an address entered by the user for a recipient not in an address book (that is, a custom recipient).

The format of the address is *address type*:*email address*. Examples of valid addresses are FAX:206-555-1212 and SMTP:M@X.COM.

### `ulEIDSize`

The size, in bytes, of the entry identifier pointed to by the **lpEntryID** member.

### `lpEntryID`

Pointer to an opaque entry identifier used by a messaging system service provider to identify the message recipient. Entry identifiers have meaning only for the service provider; client applications will not be able to decipher them. The messaging system uses this member to return valid entry identifiers for all recipients or senders listed in the address book.

## See also

[MAPIAddress](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiaddress)

[MAPIDetails](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapidetails)

[MAPIResolveName](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapiresolvename)

[MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage)

[MapiMessageW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessagew)

[MapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw)