# SHOpenWithDialog function

## Description

Displays the **Open With** dialog box.

## Parameters

### `hwndParent` [in, optional]

Type: **HWND**

The handle of the parent window. This value can be **NULL**.

### `poainfo` [in]

Type: **const [OPENASINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-openasinfo)***

A pointer to an [OPENASINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-openasinfo) structure, which specifies the contents of the resulting dialog.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Starting in Windows 10, the **OAIF_ALLOW_REGISTRATION**, **OAIF_FORCE_REGISTRATION**, and **OAIF_HIDE_REGISTRATION** flags will be ignored by **SHOpenWithDialog**. The **Open With** dialog box can no longer be used to change the default program used to open a file extension. You can only use **SHOpenWithDialog** to open a single file.

If **SHOpenWithDialog** is called without passing **OAIF_EXEC**, the user will receive a dialog that informs them that they can change the default programs used to open file extensions in their **Settings**.