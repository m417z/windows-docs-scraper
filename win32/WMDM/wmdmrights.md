# WMDMRIGHTS structure

The **WMDMRIGHTS** structure describes content-use rights.

## Members

**cbSize**

Size of the structure, in bytes.

**dwContentType**

**DWORD** containing the type of content.

**fuFlags**

Bit field specifying the rights options in use for the content.

| Value | Description |
|------------------------------|----------------------------------------------|
| WMDM\_RIGHTS\_PLAYBACKCOUNT | Number of times that the file can be played. |
| WMDM\_RIGHTS\_EXPIRATIONDATE | Expiration date of the file. |
| WMDM\_RIGHTS\_FREESERIALIDS | Free serial identifier of the file. |
| WMDM\_RIGHTS\_GROUPID Group | Identifier of the file. |
| WMDM\_RIGHTS\_NAMEDSERIALIDS | Named serial identifier of the file. |

**fuRights**

Bit field containing the rights bits for the content.

| Value | Description |
|-------------------------------------------|-----------------------------------------------|
| WMDM\_RIGHTS\_PLAY\_ON\_PC | Content can be played on a personal computer. |
| WMDM\_RIGHTS\_COPY\_TO\_NON\_SDMI\_DEVICE | Content can be copied to a non-SDMI device. |
| WMDM\_RIGHTS\_COPY\_TO\_CD | Content can be copied to a CD. |
| WMDM\_RIGHTS\_COPY\_TO\_SDMI\_DEVICE | Content can be copied to an SDMI device. |

**dwAppSec**

Byte array that specifies the minimum level of application security.

**dwPlaybackCount**

**DWORD** containing the number of remaining times that the content can be rendered.

**ExpirationDate**

[**WMDMDATETIME**](https://learn.microsoft.com/windows/win32/wmdm/wmdmdatetime) structure containing the expiration date and time for the content. If the license has no expiration date, the **wYear** member is set to 0xFFFF, and all other members of **WMDMDATETIME** are ignored.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**IMDSPStorage::GetRights**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getrights)

[**IWMDMStorage::GetRights**](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorage-getrights)

[**WMDMDATETIME**](https://learn.microsoft.com/windows/win32/wmdm/wmdmdatetime)

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

