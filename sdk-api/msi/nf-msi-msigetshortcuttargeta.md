# MsiGetShortcutTargetA function

## Description

The
**MsiGetShortcutTarget** function examines a shortcut and returns its product, feature name, and component if available.

## Parameters

### `szShortcutPath` [in]

A null-terminated string specifying the full path to a shortcut.

### `szProductCode` [out]

A GUID for the product code of the shortcut. This string buffer must be 39 characters long. The first 38 characters are for the
[GUID](https://learn.microsoft.com/windows/desktop/Msi/guid), and the last character is for the terminating null character. This parameter can be null.

### `szFeatureId` [out]

The feature name of the shortcut. The string buffer must be MAX_FEATURE_CHARS+1 characters long. This parameter can be null.

### `szComponentCode` [out]

A GUID of the component code. This string buffer must be 39 characters long. The first 38 characters are for the
[GUID](https://learn.microsoft.com/windows/desktop/Msi/guid), and the last character is for the terminating null character. This parameter can be null.

## Return value

This function returns UINT.

## Remarks

If the function fails, and the shortcut exists, the regular contents of the shortcut may be accessed through the
[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) interface.

Otherwise, the state of the target may be determined by using the
[Installer Selection Functions](https://learn.microsoft.com/windows/desktop/Msi/database-functions).

> [!NOTE]
> The msi.h header defines MsiGetShortcutTarget as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).