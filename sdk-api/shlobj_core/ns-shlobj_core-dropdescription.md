# DROPDESCRIPTION structure

## Description

Describes the image and accompanying text for a drop object.

## Members

### `type`

Type: **[DROPIMAGETYPE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-dropimagetype)**

A [DROPIMAGETYPE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ne-shlobj_core-dropimagetype) indicating the stock image to use.

### `szMessage`

Type: **WCHAR[MAX_PATH]**

Text such as "Move to %1".

### `szInsert`

Type: **WCHAR[MAX_PATH]**

Text such as "Documents", inserted as specified by **szMessage**.

## Remarks

Some UI coloring is applied to the text in **szInsert** if used by specifying %1 in **szMessage**. The characters %% and %1 are the subset of [FormatMessage](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-formatmessage) markers that are processed here.