# OPENFILENAME_NT4A structure

## Description

The **OPENFILENAME_NT4** structure is identical to [OPENFILENAME](https://learn.microsoft.com/windows/win32/api/commdlg/ns-commdlg-openfilenamea) with _WIN32_WINNT set to 0x0400. It allows an application to take advantage of other post-Microsoft Windows NT 4.0 features while running on Microsoft Windows NT 4.0. Also, MFC42 applications must use **OPENFILENAME_NT4** to avoid heap corruption. This is because Microsoft Foundation Classes (MFC) has classes with embedded **OPENFILENAME** structures, and you must use the same structure size.

**Note** This structure is provided only for compatibility.

## Members

### `lStructSize`

### `hwndOwner`

### `hInstance`

### `lpstrFilter`

### `lpstrCustomFilter`

### `nMaxCustFilter`

### `nFilterIndex`

### `lpstrFile`

### `nMaxFile`

### `lpstrFileTitle`

### `nMaxFileTitle`

### `lpstrInitialDir`

### `lpstrTitle`

### `Flags`

### `nFileOffset`

### `nFileExtension`

### `lpstrDefExt`

### `lCustData`

### `lpfnHook`

### `lpTemplateName`