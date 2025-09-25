# MAPIREADMAIL callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPIReadMail** function retrieves a message for reading.

## Parameters

### `lhSession` [in]

Handle to a Simple MAPI session. The value of the *lhSession* parameter must represent a valid session; it cannot be zero.

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call,  *ulUIParam* is ignored.

### `lpszMessageID` [in]

Pointer to a message identifier string for the message to be read. The string is allocated by the caller.

### `flFlags` [in]

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_BODY_AS_FILE** | **MAPIReadMail** should write the message text to a temporary file and add it as the first attachment in the attachment list. |
| **MAPI_ENVELOPE_ONLY** | **MAPIReadMail** should read the message header only. File attachments are not copied to temporary files, and neither temporary file names nor message text is written. Setting this flag enhances performance. |
| **MAPI_PEEK** | **MAPIReadMail** does not mark the message as read. Marking a message as read affects its appearance in the user interface and generates a read receipt. If the messaging system does not support this flag, **MAPIReadMail** always marks the message as read. If **MAPIReadMail** encounters an error, it leaves the message unread. |
| **MAPI_SUPPRESS_ATTACH** | **MAPIReadMail** should not copy file attachments but should write message text into the [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure. **MAPIReadMail** ignores this flag if the calling application has set the MAPI_ENVELOPE_ONLY flag. Setting the MAPI_SUPPRESS_ATTACH flag enhances performance. |

### `ulReserved`

Reserved; must be zero.

### `*lppMessage` [out]

Pointer to the location where the message is written. Messages are written to a [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure which can be freed with a single call to the [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer) function.

When MAPI_ENVELOPE_ONLY and MAPI_SUPPRESS_ATTACH are not set, attachments are written to temporary files pointed to by the **lpFiles** member of the [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure. It is the caller's responsibility to delete these files when they are no longer needed.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_ATTACHMENT_WRITE_FAILURE** | An attachment could not be written to a temporary file. Check directory permissions. |
| **MAPI_E_DISK_FULL** | An attachment could not be written to a temporary file because there was not enough space on the disk. |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred while reading the message. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to read the message. |
| **MAPI_E_INVALID_MESSAGE** | An invalid message identifier was passed in the *lpszMessageID* parameter. |
| **MAPI_E_INVALID_SESSION** | An invalid session handle was passed in the *lhSession* parameter. No message was retrieved. |
| **MAPI_E_TOO_MANY_FILES** | There were too many file attachments in the message. The message could not be read. |
| **MAPI_E_TOO_MANY_RECIPIENTS** | There were too many recipients of the message. The message could not be read. |
| **SUCCESS_SUCCESS** | The call succeeded and the message was read. |

## Remarks

The **MAPIReadMail** function returns one message, breaking the message content into the same parameters and structures used in the [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) function. **MAPIReadMail** fills a block of memory with the [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure containing message elements, such as the subject, message class, delivery time, and the sender. File attachments are saved to temporary files, and the names are returned to the caller in the message structure. Recipients, attachments, and contents are copied from the message before **MAPIReadMail** returns to the caller, so later changes to the files do not affect the contents of the message.

A flag is provided to specify that only envelope information is to be returned from the call. Another flag (in the [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure) specifies whether the message is marked as sent or unsent.

The caller is responsible for freeing the [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure by calling the [MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer) function and deleting any files associated with attachments included with the message.

Before calling **MAPIReadMail**, use the [MAPIFindNext](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapifindnext) function to verify that the message to be read is the one you want to be read. Because message identifiers are system-specific and opaque and can be invalidated at any time, **MAPIReadMail** considers a message identifier to be valid only for the current Simple MAPI session.

## See also

[MAPIFreeBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nf-mapi-mapifreebuffer)

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))