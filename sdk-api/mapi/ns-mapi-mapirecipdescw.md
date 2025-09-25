# MapiRecipDescW structure

## Description

A **MapiRecipDescW** structure contains information about a message sender or recipient.

## Members

### `ulReserved`

Reserved; must be zero.

### `ulRecipClass`

Contains a numeric value that indicates the type of recipient. The following values are possible.

| Value | Meaning |
| --- | --- |
| **MAPI_ORIG**<br><br>0 | Indicates the original sender of the message. |
| **MAPI_TO**<br><br>1 | Indicates a primary recipient of the message. |
| **MAPI_CC**<br><br>2 | Indicates the recipient of a copy of the message. |
| **MAPI_BCC**<br><br>3 | Indicates the recipient of a blind copy of the message. |

### `lpszName`

Pointer to the display name of the message recipient or sender.

### `lpszAddress`

Optional pointer to the recipient or sender's address. This address contains provider-specific message delivery data.

Generally, the messaging system provides such addresses for inbound messages. For outbound messages, the **lpszAddress** member can point to an address entered by the user for a recipient that is not in an address book (a custom recipient).

The format of the address is *address type*:*email address*. Two examples of valid addresses are FAX:206-555-1212 and SMTP:M@X.COM.

### `ulEIDSize`

The size, in bytes, of the entry identifier pointed to by the **lpEntryID** member.

### `lpEntryID`

Pointer to an entry identifier that cannot be deciphered by client applications and that is used by a messaging system service provider to identify the message recipient.

These entry identifiers have meaning only for the service provider. The messaging system uses this member to return valid entry identifiers for all recipients or senders listed in the address book.

## See also

[MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw)

[MapiMessageW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessagew)

[MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc)