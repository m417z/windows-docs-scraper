## Description

Retrieves various information about the color management module (CMM) that created the specified color transform.

## Parameters

### `hColorTransform`

Identifies the transform for which to find CMM information.

### `unnamedParam2`

Specifies the information to be retrieved. This parameter can take one of the following constant values.

| Value | Meaning |
|-|-|
|

**CMM\_WIN\_VERSION**

| Retrieves the version of Windows targeted by the color management module (CMM).<br> |
|

**CMM\_DLL\_VERSION**

| Retrieves the version number of the CMM.<br> |
|

**CMM\_IDENT**

| Retrieves the CMM signature registered with the International Color Consortium (ICC).<br> |

## Return value

If this function succeeds, the return value is the information specified in *dwInfo.*

If this function fails, the return value is zero.

## Remarks

## See also

* [Basic color management concepts](https://learn.microsoft.com/windows/win32/wcs/basic-color-management-concepts)
* [Functions](https://learn.microsoft.com/windows/win32/wcs/functions)