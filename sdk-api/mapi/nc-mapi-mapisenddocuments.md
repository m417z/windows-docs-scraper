# MAPISENDDOCUMENTS callback function

## Description

[The use of this function is discouraged. It may be altered or unavailable in subsequent versions of Windows.]

The **MAPISendDocuments** function sends a standard message with one or more attached files and a cover note. The cover note is a dialog box that allows the user to enter a list of recipients and an optional message. **MAPISendDocuments** differs from the [MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail) function in that it allows less flexibility in message generation.

## Parameters

### `ulUIParam` [in]

Parent window handle or zero, indicating that if a dialog box is displayed, it is application modal. If the *ulUIParam* parameter contains a parent window handle, it is of type HWND (cast to a ULONG_PTR). If no dialog box is displayed during the call, *ulUIParam* is ignored.

### `lpszDelimChar` [in]

Pointer to a character that the caller uses to delimit the names pointed to by the *lpszFullPaths* and *lpszFileNames* parameters. The caller should select a character for the delimiter that is not used in operating system filenames.

### `lpszFilePaths` [in]

Pointer to a string containing a list of full paths (including drive letters) to attachment files. This list is formed by concatenating correctly formed file paths separated by the character specified in the *lpszDelimChar* parameter and followed by a **null** terminator. An example of a valid list is:

C:\TMP\TEMP1.DOC;C:\TMP\TEMP2.DOC

The files specified in this parameter are added to the message as file attachments. If this parameter is **NULL** or contains an empty string, the Send Note dialog box is displayed with no attached files.

### `lpszFileNames` [in]

Pointer to a **null**-terminated list of the original filenames as they should appear in the message. When multiple names are specified, the list is formed by concatenating the filenames separated by the character specified in the *lpszDelimChar* parameter and followed by a **null** terminator. An example is:

TEMP3.DOC;TEMP4.DOC

If there is no value for the *lpszFileNames* parameter or if it is empty, **MAPISendDocuments** sets the filenames set to the filename values indicated by the *lpszFullPaths* parameter.

### `ulReserved`

Reserved; must be zero.

## Return value

This function returns one of the following values.

| Return code | Description |
| --- | --- |
| **MAPI_E_ATTACHMENT_OPEN_FAILURE** | One or more files in the *lpszFilePaths* parameter could not be located. No message was sent. |
| **MAPI_E_ATTACHMENT_WRITE_FAILURE** | An attachment could not be written to a temporary file. Check directory permissions. |
| **MAPI_E_FAILURE** | One or more unspecified errors occurred while sending the message. It is not known if the message was sent. |
| **MAPI_E_INSUFFICIENT_MEMORY** | There was insufficient memory to proceed. |
| **MAPI_E_LOGIN_FAILURE** | There was no default logon, and the user failed to log on successfully when the logon dialog box was displayed. No message was sent. |
| **MAPI_E_USER_ABORT** | The user canceled one of the dialog boxes. No message was sent. |
| **SUCCESS_SUCCESS** | The call succeeded and the message was sent. |

## Remarks

The **MAPISendDocuments** function sends a standard message, always displaying a cover note dialog box so the user can provide recipients and other sending options. This function tries to establish a session using the messaging system's shared session. If no shared session exists, it prompts the user for logon information to establish a session. Before **MAPISendDocuments** returns, it ends the session.

Message attachments can include the active document or all the currently open documents in the client application that called **MAPISendDocuments**. This function is used primarily for calls from a macro or scripting language, often found in applications such as spreadsheet or word-processing programs.

**MAPISendDocuments** creates as many file attachments as there are paths specified by the *lpszFullPaths* parameter in spite of the fact that there can be different numbers of paths and filenames. The caller is responsible for deleting temporary files created when using **MAPISendDocuments**.

## See also

[MAPISendMail](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmail)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))