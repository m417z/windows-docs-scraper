# MapiFileTagExt structure

## Description

A **MapiFileTagExt** structure specifies a message attachment's type at its creation and its current form of encoding so that it can be restored to its original type at its destination.

## Members

### `ulReserved`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; must be zero.

### `cbTag`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the value defined by the **lpTag** member.

### `lpTag`

Type: **[LPBYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to an X.400 object identifier indicating the type of the attachment in its original form, for example "Microsoft Excel worksheet".

### `cbEncoding`

Type: **[ULONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size, in bytes, of the value defined by the **lpEncoding** member.

### `lpEncoding`

Type: **[LPBYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to an X.400 object identifier indicating the form in which the attachment is currently encoded, for example MacBinary, UUENCODE, or binary.

## Remarks

A **MapiFileTagExt** structure defines the type of an attached file for purposes such as encoding and decoding the file, choosing the correct application to launch when opening it, or any use that requires full information regarding the file type. Client applications can use information in the **lpTag** and **lpEncoding** members of this structure to determine what to do with an attachment.

## See also

[MapiFileDesc](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledesc)

[MapiFileDescW](https://learn.microsoft.com/previous-versions/windows/desktop/api/mapi/ns-mapi-mapifiledescw)

[PidTagAttachEncoding Canonical Property](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc815513(v=office.12))

[PidTagAttachTag Canonical Property](https://learn.microsoft.com/previous-versions/office/developer/office-2007/cc765770(v=office.12))