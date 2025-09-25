# CERT_VIEWPROPERTIES_STRUCT_W structure

## Description

[The **CERT_VIEWPROPERTIES_STRUCT** structure is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CERT_VIEWPROPERTIES_STRUCT** structure defines information used when the [CertViewProperties](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certviewpropertiesa) function is called to display a certificate's properties.

## Members

### `dwSize`

The size, in bytes, of this structure.

### `hwndParent`

A handle to the parent window.

### `hInstance`

A handle to the module instance.

### `dwFlags`

Bitwise combination of zero or more of the following values.

| Value | Meaning |
| --- | --- |
| **CM_ENABLEHOOK**<br><br>1 (0x1) | Specifies that a hook function is enabled. |
| **CM_SHOW_HELP**<br><br>2 (0x2) | Specifies that a help file is used. |
| **CM_SHOW_HELPICON**<br><br>4 (0x4) | Specifies that a help icon is used. |
| **CM_ENABLETEMPLATE**<br><br>8 (0x8) | Specifies that a template is enabled. |
| **CM_HIDE_ADVANCEPAGE**<br><br>16 (0x10) | Specifies that the **Advance** tab is not displayed. |
| **CM_HIDE_TRUSTPAGE**<br><br>32 (0x20) | Specifies that the **Trust** tab is not displayed. |
| **CM_NO_NAMECHANGE**<br><br>64 (0x40) | Specifies that the name cannot be changed. |
| **CM_NO_EDITTRUST**<br><br>128 (0x80) | Specifies that the trust cannot be edited. |
| **CM_HIDE_DETAILPAGE**<br><br>256 (0x100) | Specifies that the **Detail** tab is not displayed. |
| **CM_ADD_CERT_STORES**<br><br>512 (0x200) | Specifies that certificate stores are opened. |

### `szTitle`

A pointer to a null-terminated string for the title of the user interface.

### `pCertContext`

Certificate context for the certificate to be shown.

### `arrayPurposes`

A pointer to an array of null-terminated strings that specify the certificate purposes.

### `cArrayPurposes`

Number of elements in the **arrayPurposes** array. If this value is zero, then no trust status is displayed.

### `cRootStores`

Number of elements in the **rghstoreRoots** array.

### `rghstoreRoots`

Array of Root certificate store handles.

### `cStores`

Number of elements in the **rghstoreCAs** array.

### `rghstoreCAs`

Array of other certificate store handles.

### `cTrustStores`

Number of elements in the **rghstoreTrust** array.

### `rghstoreTrust`

Array of trust certificate store handles.

### `hprov`

A handle to the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) to use for verification.

### `lCustData`

Value used for custom data.

### `dwPad`

Padding location.

### `szHelpFileName`

A pointer to a null-terminated string for the Help file name.

### `dwHelpId`

ID for the Help file topic.

### `nStartPage`

Number of the first property page.

### `cArrayPropSheetPages`

Number of elements in the **arrayPropSheetPages** array.

### `arrayPropSheetPages`

A pointer to an array of **PROPSHEETPAGE** structures that specify the property pages.

## See also

[CertViewProperties](https://learn.microsoft.com/windows/desktop/api/cryptdlg/nf-cryptdlg-certviewpropertiesa)

## Remarks

> [!NOTE]
> The cryptdlg.h header defines CERT_VIEWPROPERTIES_STRUCT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).