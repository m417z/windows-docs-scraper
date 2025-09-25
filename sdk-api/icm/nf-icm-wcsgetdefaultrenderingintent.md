## Description

Retrieves the default rendering intent in the specified profile management scope.

## Parameters

### `scope`

The profile management scope for this operation, which can be system-wide or the current user only.

### `pdwRenderingIntent`

A pointer to the variable that will hold the rendering intent.

For more information, see [Rendering intents](https://learn.microsoft.com/windows/win32/wcs/rendering-intents).

## Return value

If this function succeeds, the return value is **TRUE**.

If this function fails, the return value is **FALSE**. For extended error information, call **GetLastError**.

## Remarks

This function does not revert to the system-wide scope if you do not set the per-user default rendering intent. Instead, it fails, which allows the calling process to distinguish between the per-user and the system-wide setting. If the per-user rendering intent cannot be retrieved, call this function again with system-wide.

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Windows Color System schemas and algorithms](https://learn.microsoft.com/windows/win32/wcs/windows-color-system-schemas-and-algorithms)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)