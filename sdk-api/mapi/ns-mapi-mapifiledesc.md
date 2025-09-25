# MapiFileDesc structure

## Description

A **MapiFileDesc** structure contains information about a file containing a message attachment stored as a temporary file. That file can contain a static OLE object, an embedded OLE object, an embedded message, and other types of files. For Unicode support, use the [MapiFileDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledescw) structure.

## Members

### `ulReserved`

Reserved; must be zero.

### `flFlags`

Bitmask of option flags. The following flags can be set.

| Value | Meaning |
| --- | --- |
| **MAPI_OLE** | The attachment is an OLE object. If MAPI_OLE_STATIC is also set, the attachment is a static OLE object. If MAPI_OLE_STATIC is not set, the attachment is an embedded OLE object. |
| **MAPI_OLE_STATIC** | The attachment is a static OLE object. |

If neither flag is set, the attachment is treated as a data file.

### `nPosition`

An integer used to indicate where in the message text to render the attachment. Attachments replace the character found at a certain position in the message text. That is, attachments replace the character in the [MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage) structure field **NoteText**[**nPosition**]. A value of -1 (0xFFFFFFFF) means the attachment position is not indicated; the client application will have to provide a way for the user to access the attachment.

### `lpszPathName`

Pointer to the fully qualified path of the attached file. This path should include the disk drive letter and directory name.

### `lpszFileName`

Pointer to the attachment filename seen by the recipient, which may differ from the filename in the **lpszPathName** member if temporary files are being used. If the **lpszFileName** member is empty or **NULL**, the filename from **lpszPathName** is used.

### `lpFileType`

Pointer to the attachment file type, which can be represented with a [MapiFileTagExt](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiletagext) structure. A value of **NULL** indicates an unknown file type or a file type determined by the operating system.

## Remarks

Simple MAPI works with three kinds of embedded attachments:

* Data file attachments
* Editable OLE object file attachments
* Static OLE object file attachments

Data file attachments are simply data files. OLE object file attachments are OLE objects that are displayed in the message text. If the OLE attachment is editable, the recipient can double-click it and its source application will be started to handle the edit session. If the OLE attachment is static, the object cannot be edited. The flag set in the **flFlags** member of the **MapiFileDesc** structure determines the kind of a particular attachment. Embedded messages can be identified by a .MSG extension in the **lpszFileName** member.

OLE object files are file representations of OLE object streams. The client application can re-create an OLE object from the file by calling the OLE function [OleLoadFromStream](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-oleloadfromstream) with an OLESTREAM object that reads the file contents. If an OLE file attachment is included in an outbound message, the OLE object stream should be written directly to the file used as the attachment.

When using the **MapiFileDesc** member **nPosition**, the client application should not place two attachments in the same location. Client applications might not display file attachments at positions beyond the end of the message text.

## See also

[MapiFileDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledescw)

[MapiMessage](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessage)

[MapiMessageW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapimessagew)