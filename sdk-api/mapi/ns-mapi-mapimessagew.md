# MapiMessageW structure

## Description

A **MapiMessageW** structure contains information about a message.

## Members

### `ulReserved`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; must be zero.

### `lpszSubject`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the text string describing the message subject, typically limited to 256 characters or less.

If this member is empty or **NULL**, there is no subject text.

### `lpszNoteText`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string containing the message text.

If this member is empty or **NULL**, there is no message text.

### `lpszMessageType`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that indicates the message type of when the message is not an IPM.

If your Client supports Interpersonal Messages (IPMs) exclusively, set the **lpszMessageType** member to empty or **NULL** when sending messages and ignore the member when reading messages.

### `lpszDateReceived`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string indicating the date when the message was received. The format is *YYYY*/*MM*/*DD**HH*:*MM*, using a 24-hour clock.

### `lpszConversationID`

Type: **[PWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string identifying the conversation thread to which the message belongs. Some messaging systems ignore this member.

### `flFlags`

Type: **FLAGS**

Bitmask of message status flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_RECEIPT_REQUESTED**<br><br>0x00000002 | A receipt notification is requested. Client applications set this flag when sending a message. |
| **MAPI_SENT**<br><br>0x00000004 | The message has been sent. |
| **MAPI_UNREAD**<br><br>0x00000001 | The message has not been read. |

### `lpOriginator`

Type: **[lpMapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw)**

Pointer to a [MapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw) structure containing information about the sender of the message.

### `nRecipCount`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of [MapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw) structures in the array pointed to by the **lpRecips** member.

If this member is zero, there are no recipients.

### `lpRecips`

Type: **[lpMapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw)**

Pointer to an array of [MapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw) structures. Each structure contains information about one recipient.

### `nFileCount`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of [MapiFileDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledescw) structures in the array pointed to by the **lpFiles** member.

If this member is zero, there are no file attachments.

### `lpFiles`

Type: **[lpMapiFileDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledescw)**

Pointer to an array of [MapiFileDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledescw) structures. Each structure contains information about one file attachment.

## See also

[MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw)

[MapiFileDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledescw)

[MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage)

[MapiRecipDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdescw)