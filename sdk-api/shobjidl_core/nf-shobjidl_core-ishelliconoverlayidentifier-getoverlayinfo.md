# IShellIconOverlayIdentifier::GetOverlayInfo

## Description

Provides the location of the icon overlay's bitmap.

## Parameters

### `pwszIconFile` [out]

Type: **PWSTR**

A null-terminated Unicode string that contains the fully qualified path of the file containing the icon. The .dll, .exe, and .ico file types are all acceptable. You must set the **ISIOI_ICONFILE** flag in *pdwFlags* if you return a file name.

### `cchMax`

Type: **int**

The size of the *pwszIconFile* buffer, in Unicode characters.

### `pIndex` [out]

Type: **int***

Pointer to an index value used to identify the icon in a file that contains multiple icons. You must set the **ISIOI_ICONINDEX** flag in *pdwFlags* if you return an index.

### `pdwFlags` [out]

Type: **DWORD***

Pointer to a bitmap that specifies the information that is being returned by the method. This parameter can be one or both of the following values.

#### ISIOI_ICONFILE (0x00000001)

The path of the icon file is returned through *pwszIconFile*.

#### ISIOI_ICONINDEX (0x00000002)

There is more than one icon in *pwszIconFile*. The icon's index is returned through *pIndex*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method is called by the Shell at startup so that the handler's icon overlay can be added to the system image list. After initialization is complete, the Shell calls **GetOverlayInfo** when it needs to display the handler's icon overlay.

**Note** Once the image has been loaded into the system image list during initialization, it cannot be changed. After initialization, the file name and index are used only to identify the icon overlay. The system will not load a new icon overlay. When **GetOverlayInfo** is called, your handler must return the same file name and index that were specified when the function was first called.