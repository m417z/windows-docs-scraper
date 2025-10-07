# CRYPTUI\_VIEWSIGNERINFO\_STRUCT structure

\[The **CRYPTUI\_VIEWSIGNERINFO\_STRUCT** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.\]

The **CRYPTUI\_VIEWSIGNERINFO\_STRUCT** structure contains information for the [**CryptUIDlgViewSignerInfo**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgviewsignerinfo) function.

> [!Note]
> This structure is not declared in a published header file. To use this structure, declare it in the exact format shown.

## Members

**dwSize**

The size, in bytes, of this structure.

**hwndParent**

The handle of the window to be the parent of the dialog box. This member can be **NULL** if the dialog box should have no parent.

**dwFlags**

A set of flags that modifies the behavior of the [**CryptUIDlgViewSignerInfo**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgviewsignerinfo) function. There are no flags currently defined, so this member must be zero.

**szTitle**

A pointer to a null-terminated string that contains the title to be displayed in the dialog box. If this member is **NULL**, a default title is used.

**pSignerInfo**

A pointer to a [**CMSG\_SIGNER\_INFO**](https://learn.microsoft.com/windows/desktop/api/Wincrypt/ns-wincrypt-cmsg_signer_info) structure that contains the signer information to display.

**hMsg**

The handle of the message that the signer information was extracted from.

**pszOID**

A pointer to a null-terminated ANSI string that contains the string representation of the [*object identifier*](https://learn.microsoft.com/windows/win32/secgloss/o-gly) (OID) that signifies what the certificate that did the signing should be validated for. For example, if this is being called to view the signature of a [*certificate trust list*](https://learn.microsoft.com/windows/win32/secgloss/c-gly) (CTL), the **szOID\_KP\_CTL\_USAGE\_SIGNING** OID string should be passed in. If this member is **NULL**, the certificate is not validated for usages.

**dwReserved**

This parameter is not currently used. This member must be **NULL**.

**cStores**

The number of elements in the **rghStores** array.

**rghStores**

An array of **HCERTSTORE** values that represent the other certificate stores to search for the certificate that signed the message. If this member is **NULL**, no additional stores are searched. The **cStores** member contains the number of elements in this array.

**cPropSheetPages**

The number of elements in the **rgPropSheetPages** array.

**rgPropSheetPages**

An array of [**PROPSHEETPAGE**](https://learn.microsoft.com/windows/win32/api/prsht/ns-prsht-propsheetpagea_v2) structure pointers that define any extra pages to display in the standard dialog box. If this member is **NULL**, no additional pages will be displayed. The **cPropSheetPages** member contains the number of elements in this array.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Unicode and ANSI names<br> | **CRYPTUI\_VIEWSIGNERINFO\_STRUCTW** (Unicode) and **CRYPTUI\_VIEWSIGNERINFO\_STRUCTA** (ANSI)<br> |

## See also

[**CryptUIDlgViewSignerInfo**](https://learn.microsoft.com/windows/win32/seccrypto/cryptuidlgviewsignerinfo)

