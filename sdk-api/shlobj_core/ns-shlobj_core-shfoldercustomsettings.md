# SHFOLDERCUSTOMSETTINGS structure

## Description

Holds custom folder settings. This structure is used with the [SHGetSetFolderCustomSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsetfoldercustomsettings) function.

## Members

### `dwSize`

Type: **DWORD**

The size of the structure, in bytes.

### `dwMask`

Type: **DWORD**

A **DWORD** value specifying which folder attributes to read or write from this structure. Use one or more of the following values to indicate which structure members are valid:

#### FCSM_VIEWID

**Deprecated**. **pvid** contains the folder's GUID.

#### FCSM_WEBVIEWTEMPLATE

**Deprecated**. **pszWebViewTemplate** contains a pointer to a buffer containing the path to the folder's WebView template.

#### FCSM_INFOTIP

**pszInfoTip** contains a pointer to a buffer containing the folder's info tip.

#### FCSM_CLSID

**pclsid** contains the folder's CLSID.

#### FCSM_ICONFILE

**pszIconFile** contains the path to the file containing the folder's icon.

#### FCSM_LOGO

**pszLogo** contains the path to the file containing the folder's thumbnail icon.

#### FCSM_FLAGS

Not used.

### `pvid`

Type: **SHELLVIEWID***

The folder's GUID.

### `pszWebViewTemplate`

Type: **LPTSTR**

A pointer to a null-terminated string containing the path to the folder's [WebView template](https://learn.microsoft.com/windows/desktop/lwef/web-view).

### `cchWebViewTemplate`

Type: **DWORD**

If the [SHGetSetFolderCustomSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsetfoldercustomsettings) parameter *dwReadWrite* is **FCS_READ**, this is the size of the **pszWebViewTemplate** buffer, in characters. If not, this is the number of characters to write from that buffer. Set this parameter to 0 to write the entire string.

### `pszWebViewTemplateVersion`

Type: **LPTSTR**

A pointer to a null-terminated buffer containing the WebView template version.

### `pszInfoTip`

Type: **LPTSTR**

A pointer to a null-terminated buffer containing the text of the folder's infotip.

### `cchInfoTip`

Type: **DWORD**

If the [SHGetSetFolderCustomSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsetfoldercustomsettings) parameter *dwReadWrite* is **FCS_READ**, this is the size of the **pszInfoTip** buffer, in characters. If not, this is the number of characters to write from that buffer. Set this parameter to 0 to write the entire string.

### `pclsid`

Type: **CLSID***

A pointer to a CLSID used to identify the folder in the Windows registry. Further folder information is stored in the registry under that CLSID entry.

### `dwFlags`

Type: **DWORD**

Not used.

### `pszIconFile`

Type: **LPTSTR**

A pointer to a null-terminated buffer containing the path to file containing the folder's icon.

### `cchIconFile`

Type: **DWORD**

If the [SHGetSetFolderCustomSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsetfoldercustomsettings) parameter *dwReadWrite* is **FCS_READ**, this is the size of the **pszIconFile** buffer, in characters. If not, this is the number of characters to write from that buffer. Set this parameter to 0 to write the entire string.

### `iIconIndex`

Type: **int**

The index of the icon within the file named in **pszIconFile**.

### `pszLogo`

Type: **LPTSTR**

A pointer to a null-terminated buffer containing the path to the file containing the folder's logo image. This is the image used in thumbnail views.

### `cchLogo`

Type: **DWORD**

If the [SHGetSetFolderCustomSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsetfoldercustomsettings) parameter *dwReadWrite* is **FCS_READ**, this is the size of the **pszLogo** buffer, in characters. If not, this is the number of characters to write from that buffer. Set this parameter to 0 to write the entire string.

## Remarks

In Windows XP Service Pack 2 (SP2) and earlier versions, this structure supported both ANSI and Unicode strings. In Windows Vista and later versions, only Unicode strings are supported.