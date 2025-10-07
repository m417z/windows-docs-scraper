# CRYPTUI\_SELECTCERTIFICATE\_STRUCT structure

The **CRYPTUI\_SELECTCERTIFICATE\_STRUCT** structure contains information about the dialog box displayed by the [**CryptUIDlgSelectCertificate**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgselectcertificate) function.

## Members

**dwSize**

The size, in bytes, of this structure.

**hwndParent**

The handle of the parent window of the dialog box. If this value is **NULL**, the parent window is the default desktop window.

**dwFlags**

Specifies additional options for the [**CryptUIDlgSelectCertificate**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgselectcertificate) function. This can be zero or a bitwise **OR** of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **CRYPTUI\_SELECTCERT\_ADDFROMDS** | Reserved.<br> |
| **CRYPTUI\_SELECTCERT\_LEGACY** | Specifies that the legacy dialog is to be displayed.<br> |
| **CRYPTUI\_SELECTCERT\_MULTISELECT** | Allows the user to select more than one certificate in the dialog box. If this flag is set, the [**CryptUIDlgSelectCertificate**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgselectcertificate) function always returns **NULL**. The **hSelectedCertStore** member of this structure must contain a handle to a certificate store. The certificates selected by the user will be added to this store.<br> |
| **CRYPTUI\_SELECTCERT\_PUT\_WINDOW\_TOPMOST** | Forces the cryptography UI to be the top window on the screen.<br> |

**szTitle**

The display title for the dialog box. If the value of this member is **NULL**, the default title of "Select Certificate" is used.

**dwDontUseColumn**

Flags that can be combined to exclude columns of the display.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------|
| **CRYPTUI\_SELECT\_ISSUEDTO\_COLUMN**

1 (0x1) | Do not display **ISSUEDTO** information.\ | | **CRYPTUI\_SELECT\_ISSUEDBY\_COLUMN**

2 (0x2) | Do not display **ISSUEDBY** information.\ | | **CRYPTUI\_SELECT\_INTENDEDUSE\_COLUMN**

4 (0x4) | Do not display **IntendedUse** information.\ | | **CRYPTUI\_SELECT\_FRIENDLYNAME\_COLUMN**

8 (0x8) | Do not display name information.\ | | **CRYPTUI\_SELECT\_LOCATION\_COLUMN**

16 (0x10) | Do not display location information.\ | | **CRYPTUI\_SELECT\_EXPIRATION\_COLUMN**

32 (0x20) | Do not display expiration information.\ |

**szDisplayString**

Text that is displayed in the dialog box to instruct the user. If the value of this member is **NULL**, the default string "Select a certificate you want to use" is used.

**pFilterCallback**

A pointer to a [**PFNCFILTERPROC**](https://learn.microsoft.com/windows/desktop/api/Cryptuiapi/nc-cryptuiapi-pfncfilterproc) callback function that filters the certificates that are displayed in the dialog box.

**pDisplayCallback**

A pointer to a [**PFNCCERTDISPLAYPROC**](https://learn.microsoft.com/windows/win32/seccrypto/pfnccertdisplayproc) callback function that displays certificates that the user selects to view.

**pvCallbackData**

Additional data that is passed to the callback functions specified by the **pFilterCallback** and **pDisplayCallback** members.

**cDisplayStores**

The number of certificate stores in the **rghDisplayStores** array.

**rghDisplayStores**

A pointer to an array of stores that contain certificates available for selection in the dialog box.

**cStores**

The number of certificate stores in the **rghStores** array.

**rghStores**

A pointer to an array of certificate stores to search when building a certificate chain and verifying trust for the certificates displayed in the dialog box.

**cPropSheetPages**

The number of property pages in the **rgPropSheetPages** array.

**rgPropSheetPages**

A pointer to an array of **PROPSHEETPAGE** structures that represent property pages that are passed to the certificate viewing dialog box when a certificate is selected for viewing.

**hSelectedCertStore**

A handle to a certificate store created by the caller. The certificates selected by the user are added to this store. If the number of certificates in this store is the same before and after calling [**CryptUIDlgSelectCertificate**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgselectcertificate), the user closed the dialog box without selecting any certificates.

This member is not used if the **dwFlags** member of this structure does not contain the **CRYPTUI\_SELECTCERT\_MULTISELECT** flag.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Unicode and ANSI names<br> | **CRYPTUI\_SELECTCERTIFICATE\_STRUCTW** (Unicode) and **CRYPTUI\_SELECTCERTIFICATE\_STRUCTA** (ANSI)<br> |

## See also

[**CryptUIDlgSelectCertificate**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgselectcertificate)

