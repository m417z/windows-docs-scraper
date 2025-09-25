# MAPISENDMAIL callback function

## Description

[**MAPISendMail** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions. Instead, use [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw).
]

Sends an ANSI message.

**On Windows 8 and later:** Call [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) to send a message.

**On Windows 7 and earlier:** Use [MAPISendMailHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapiunicodehelp/nf-mapiunicodehelp-mapisendmailhelper) to send a message.

## Parameters

### `lhSession` [in]

Type: **LHANDLE**

For more information, see the [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) function.

### `ulUIParam` [in]

Type: **[ULONG_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

For more information, see the [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) function.

### `lpMessage` [in]

Type: **[lpMapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage)**

For more information, see the [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) function.

### `flFlags` [in]

Type: **FLAGS**

For more information, see the [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) function.

### `ulReserved`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

For more information, see the [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) function.

## Return value

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

For more information, see the [MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw) function.

## See also

[MAPILogon](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapilogon)

[MAPISendDocuments](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisenddocuments)

[MAPISendMailHelper](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapiunicodehelp/nf-mapiunicodehelp-mapisendmailhelper)

[MAPISendMailW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/nc-mapi-mapisendmailw)

[MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage)

[MapiRecipDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapirecipdesc)

[Simple MAPI](https://learn.microsoft.com/previous-versions/dd296734(v=vs.85))