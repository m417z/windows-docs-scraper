# AssocGetPerceivedType function

## Description

Retrieves a file's perceived type based on its extension.

## Parameters

### `pszExt` [in]

Type: **PCWSTR**

A pointer to a buffer that contains the file's extension. This should include the leading period, for example ".txt".

### `ptype` [out]

Type: **[PERCEIVED](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-perceived)***

A pointer to a [PERCEIVED](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-perceived) value that indicates the perceived type.

### `pflag` [out]

Type: **PERCEIVEDFLAG***

A pointer to a value that indicates the source of the perceived type information. One or more of the following values.

#### PERCEIVEDFLAG_UNDEFINED (0x0000)

No perceived type was found ([PERCEIVED_TYPE_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/api/shtypes/ne-shtypes-perceived)).

#### PERCEIVEDFLAG_SOFTCODED (0x0001)

The perceived type was determined through an association in the registry.

#### PERCEIVEDFLAG_HARDCODED (0x0002)

The perceived type is inherently known to Windows.

#### PERCEIVEDFLAG_NATIVESUPPORT (0x0004)

The perceived type was determined through a codec provided with Windows.

#### PERCEIVEDFLAG_GDIPLUS (0x0010)

The perceived type is supported by the GDI+ library.

#### PERCEIVEDFLAG_WMSDK (0x0020)

The perceived type is supported by the Windows Media SDK.

#### PERCEIVEDFLAG_ZIPFOLDER (0x0040)

The perceived type is supported by Windows compressed folders.

### `ppszType` [out, optional]

Type: **PWSTR***

If the function returns a success code, this contains the address of a pointer to a buffer that receives the perceived type string, for instance "text" or "video". This value can be **NULL**.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function first compares the extension against a hard-coded set of extensions known to Windows. If that search fails to reveal a match, the registered associations under HKEY_CLASSES_ROOT are searched for a key that matches the extension and contains a PerceivedType value. If that value is found, the extension set is again searched for a match. If again no match is found, the perceived type is determined to be PERCEIVED_TYPE_CUSTOM. If either a key that matches the extension or a PerceivedType value is not found, the perceived type is reported as PERCEIVED_TYPE_UNSPECIFIED.