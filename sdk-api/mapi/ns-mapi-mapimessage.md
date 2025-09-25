# MapiMessage structure

## Description

A **MapiMessage** structure contains information about a message. For Unicode support, use the [MapiMessageW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessagew) structure.

## Members

### `ulReserved`

Reserved; must be zero or **CP_UTF8**. If **CP_UTF8**, the following are UTF-8 instead of ANSI strings: **lpszSubject**, **lpszNoteText**, **lpszMessageType**, **lpszDateReceived**, **lpszConversationID**.

### `lpszSubject`

Pointer to the text string describing the message subject, typically limited to 256 characters or less. If this member is empty or **NULL**, the user has not entered subject text.

### `lpszNoteText`

Pointer to a string containing the message text. If this member is empty or **NULL**, there is no message text.

### `lpszMessageType`

Pointer to a string indicating a non-IPM type of message. Client applications can select message types for their non-IPM messages. Clients that only support IPM messages can ignore the **lpszMessageType** member when reading messages and set it to empty or **NULL** when sending messages.

### `lpszDateReceived`

Pointer to a string indicating the date when the message was received. The format is YYYY/MM/DD HH:MM, using a 24-hour clock.

### `lpszConversationID`

Pointer to a string identifying the conversation thread to which the message belongs. Some messaging systems can ignore and not return this member.

### `flFlags`

Bitmask of message status flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_RECEIPT_REQUESTED** | A receipt notification is requested. Client applications set this flag when sending a message. |
| **MAPI_SENT** | The message has been sent. |
| **MAPI_UNREAD** | The message has not been read. |

### `lpOriginator`

Pointer to a [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) structure containing information about the sender of the message.

### `nRecipCount`

The number of message recipient structures in the array pointed to by the **lpRecips** member. A value of zero indicates no recipients are included.

### `lpRecips`

Pointer to an array of [MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc) structures, each containing information about a message recipient.

### `nFileCount`

The number of structures describing file attachments in the array pointed to by the **lpFiles** member. A value of zero indicates no file attachments are included.

### `lpFiles`

Pointer to an array of [MapiFileDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledesc) structures, each containing information about a file attachment.

## See also

[MAPIReadMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapireadmail)

[MAPISaveMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisavemail)

[MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail)

[MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw)

[MapiMessageW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessagew)