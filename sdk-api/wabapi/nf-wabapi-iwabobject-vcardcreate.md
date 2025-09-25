# IWABObject::VCardCreate

## Description

Translates the properties of a given MailUser object into a
vCard file.

## Parameters

### `lpIAB`

Type: **[IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook)***

Pointer to an [IAddrBook](https://learn.microsoft.com/windows/desktop/api/wabiab/nn-wabiab-iaddrbook) interface that
specifies the address book.

### `ulFlags`

Type: **ULONG**

No flags.

### `lpszVCard`

Type: **LPSTR**

Value of type **LPSTR** that specifies the
string containing the complete path name of the file to create.

### `lpMailUser`

Type: **[IMailUser](https://learn.microsoft.com/windows/desktop/api/wabdefs/nn-wabdefs-imailuser)***

Pointer to an [IMailUser](https://learn.microsoft.com/windows/desktop/api/wabdefs/nn-wabdefs-imailuser) interface that
specifies the object whose properties are to be written into
the file.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The complete file name must be specified. If the file already exists,
it will be overwritten. Vcard creation is extensible: if your client
application is using named properties to store client-specific data in the
Windows Address Book (WAB), it may be possible to include this data in the newly
created vCard.

## See also

[IWABObject](https://learn.microsoft.com/windows/desktop/api/wabapi/nn-wabapi-iwabobject)

[Importing and Exporting Named Properties Through vCards](https://learn.microsoft.com/previous-versions/windows/desktop/wab/-wab-vcardprops)