# IWABObject::VCardRetrieve

## Description

Reads a vCard file and creates a MailUser object containing
the vCard properties.

## Parameters

### `lpIAB`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface
that specifies the address book object.

### `ulFlags`

Type: **ULONG**

Value of type **ULONG** that specifies flags
affecting behavior.

#### WAB_VCARD_FILE

Indicates that the *lpszVCard* parameter is
the path name of the file to be read.

#### WAB_VCARD_STREAM

Indicates that the *lpszVCard* parameter
points to a buffer that contains the full contents of the Vcard.

### `lpszVCard`

Type: **LPSTR**

Pointer to a string containing either the complete path name of the
file to be read or the vCard buffer.

### `lppMailUser`

Type: **[IMailUser](https://learn.microsoft.com/windows/desktop/api/wabdefs/nn-wabdefs-imailuser)****

Address of a pointer to an [IMailUser](https://learn.microsoft.com/windows/desktop/api/wabdefs/nn-wabdefs-imailuser) interface that
receives the MailUser object created containing the properties
in the vCard file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Vcard retrieval is extensible. If your client application is using
named properties to store client-specific data in the Windows Address Book (WAB)
and exporting them to vCards, it is possible to extend the
WAB vCard engine to read this data from a vCard.
For more information, see [Importing and
Exporting Named Properties Through vCards](https://msdn.microsoft.com/40638b23-e956-4fe8-b132-245c43df6890). The *lpszVCard*
parameter can be a pointer to a Vcard file name or a pointer to a **NULL**-terminated string containing the full contents of the Vcard. To have the pointer indicate which content it represents, set the *ulFlags* parameter to either
**WAB_VCARD_FILE** or
**WAB_VCARD_STREAM**. The former setting indicates a
file name, and the latter setting indicates a pointer to a buffer with the
Vcard contents.