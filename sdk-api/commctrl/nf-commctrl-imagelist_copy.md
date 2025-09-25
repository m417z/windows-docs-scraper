# ImageList_Copy function

## Description

Copies images within a given image list.

## Parameters

### `himlDst`

Type: **HIMAGELIST**

A handle to an image list that is the target of the copy operation. In current versions of Windows, both *himlDst* and *himlSrc* must be identical.

### `iDst`

Type: **int**

The zero-based index of the image to be used as the destination of the copy operation.

### `himlSrc`

Type: **HIMAGELIST**

A handle to an image list that is the target of the copy operation. In current versions of Windows, both *himlDst* and *himlSrc* must be identical.

### `iSrc`

Type: **int**

The zero-based index of the image to be used as the source of the copy operation.

### `uFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

the bit flag value that specifies the type of copy operation to be made. This parameter can be one of the following values:

| Value | Meaning |
| --- | --- |
| **ILCF_MOVE** | The source image is copied to the destination image's index. This operation results in multiple instances of a given image. |
| **ILCF_SWAP** | The source and destination images exchange positions within the image list. |

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns nonzero if successful, or zero otherwise.