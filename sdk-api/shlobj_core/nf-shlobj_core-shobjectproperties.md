# SHObjectProperties function

## Description

[**SHObjectProperties** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Invokes the **Properties** context menu command on a Shell object.

## Parameters

### `hwnd` [in]

Type: **HWND**

The handle of the parent window of the dialog box. This value can be **NULL**.

### `shopObjectType` [in]

Type: **DWORD**

A flag value that specifies the type of object.

#### SHOP_PRINTERNAME

*pszObjectName* contains the friendly name of a printer.

#### SHOP_FILEPATH

*pszObjectName* contains a fully qualified file name.

#### SHOP_VOLUMEGUID

*pszObjectName* contains either (a) a volume name of the form \\?\Volume{GUID}\, where {GUID} is a globally unique identifier (for example, "\\?\Volume\{2eca078d-5cbc-43d3-aff8-7e8511f60d0e}\)", or (b) a drive path (for example, "C:\").

### `pszObjectName` [in]

Type: **PCWSTR**

A null-terminated Unicode string that contains the object name. The contents of the string are determined by the flag set in *shopObjectType*.

### `pszPropertyPage` [in]

Type: **PCWSTR**

A null-terminated Unicode string that contains the name of the property sheet page to be opened initially. Set this parameter to **NULL** to specify the default page.

## Return value

Type: **BOOL**

**TRUE** if the command is successfully invoked; otherwise, **FALSE**.