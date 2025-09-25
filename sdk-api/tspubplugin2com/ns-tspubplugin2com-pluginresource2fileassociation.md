# pluginResource2FileAssociation structure

## Description

Contains information about a file association in RemoteApp and Desktop Connection.

## Members

### `extName`

A null-terminated string that contains the file name extension. The length of this string is limited to **MAX_FILE_ASSOC_EXTENSION_SIZE** characters, including the terminating **NULL** character.

### `primaryHandler`

Indicates if this is the primary handler for the file association.

### `pceIconSize`

The size, in bytes, of the **iconContents** buffer.

### `iconContents`

A byte array that contains the icon to display for files with the specified extension.

## Remarks

**MAX_FILE_ASSOC_EXTENSION_SIZE** is declared as follows:

`#define MAX_FILE_ASSOC_EXTENSION_SIZE 256`

## See also

[pluginResource2](https://learn.microsoft.com/windows/win32/api/tspubplugin2com/ns-tspubplugin2com-pluginresource2)