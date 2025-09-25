# IExtractIconW::GetIconLocation

## Description

Gets the location and index of an icon.

## Parameters

### `uFlags`

Type: **UINT**

One or more of the following values. This parameter can also be **NULL**.

#### GIL_ASYNC (0x0020)

Set this flag to determine whether the icon should be extracted asynchronously. If the icon can be extracted rapidly, this flag is usually ignored. If extraction will take more time, **GetIconLocation** should return E_PENDING. See the Remarks for further discussion.

#### GIL_DEFAULTICON (0x0040)

Retrieve information about the fallback icon. Fallback icons are usually used while the desired icon is extracted and added to the cache.

#### GIL_FORSHELL (0x0002)

The icon is displayed in a Shell folder.

#### GIL_FORSHORTCUT (0x0080)

The icon indicates a shortcut. However, the icon extractor should not apply the shortcut overlay; that will be done later. Shortcut icons are state-independent.

#### GIL_OPENICON (0x0001)

The icon is in the open state if both open-state and closed-state images are available. If this flag is not specified, the icon is in the normal or closed state. This flag is typically used for folder objects.

#### GIL_CHECKSHIELD (0x0200)

Explicitly return either GIL_SHIELD or GIL_FORCENOSHIELD in *pwFlags*. Do not block if GIL_ASYNC is set.

### `pszIconFile` [out]

Type: **PTSTR**

A pointer to a buffer that receives the icon location. The icon location is a null-terminated string that identifies the file that contains the icon.

### `cchMax`

Type: **UINT**

The size of the buffer, in characters, pointed to by *pszIconFile*.

### `piIndex` [out]

Type: **int***

A pointer to an **int** that receives the index of the icon in the file pointed to by *pszIconFile*.

### `pwFlags` [out]

Type: **UINT***

A pointer to a **UINT** value that receives zero or a combination of the following values.

#### GIL_DONTCACHE (0x0010)

The physical image bits for this icon are not cached by the calling application.

#### GIL_NOTFILENAME (0x0008)

The location is not a file name/index pair. The values in *pszIconFile* and *piIndex* cannot be passed to [ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona) or [ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa).

When this flag is omitted, the value returned in *pszIconFile* is a fully-qualified path name to either a .ico file or to a file that can contain icons. Also, the value returned in *piIndex* is an index into that file that identifies which of its icons to use. Therefore, when the GIL_NOTFILENAME flag is omitted, these values can be passed to [ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona) or [ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa).

#### GIL_PERCLASS (0x0004)

All objects of this class have the same icon. This flag is used internally by the Shell. Typical implementations of [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) do not require this flag because the flag implies that an icon handler is not required to resolve the icon on a per-object basis. The recommended method for implementing per-class icons is to register a DefaultIcon for the class.

#### GIL_PERINSTANCE (0x0002)

Each object of this class has its own icon. This flag is used internally by the Shell to handle cases like Setup.exe, where objects with identical names can have different icons. Typical implementations of [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) do not require this flag.

#### GIL_SIMULATEDOC (0x0001)

The calling application should create a document icon using the specified icon.

#### GIL_SHIELD (0x0200)

**Windows Vista only**. The calling application must stamp the icon with the UAC shield.

#### GIL_FORCENOSHIELD (0x0400)

**Windows Vista only**. The calling application must not stamp the icon with the UAC shield.

##### - pwFlags.GIL_DONTCACHE (0x0010)

The physical image bits for this icon are not cached by the calling application.

##### - pwFlags.GIL_FORCENOSHIELD (0x0400)

**Windows Vista only**. The calling application must not stamp the icon with the UAC shield.

##### - pwFlags.GIL_NOTFILENAME (0x0008)

The location is not a file name/index pair. The values in *pszIconFile* and *piIndex* cannot be passed to [ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona) or [ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa).

When this flag is omitted, the value returned in *pszIconFile* is a fully-qualified path name to either a .ico file or to a file that can contain icons. Also, the value returned in *piIndex* is an index into that file that identifies which of its icons to use. Therefore, when the GIL_NOTFILENAME flag is omitted, these values can be passed to [ExtractIcon](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticona) or [ExtractIconEx](https://learn.microsoft.com/windows/desktop/api/shellapi/nf-shellapi-extracticonexa).

##### - pwFlags.GIL_PERCLASS (0x0004)

All objects of this class have the same icon. This flag is used internally by the Shell. Typical implementations of [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) do not require this flag because the flag implies that an icon handler is not required to resolve the icon on a per-object basis. The recommended method for implementing per-class icons is to register a DefaultIcon for the class.

##### - pwFlags.GIL_PERINSTANCE (0x0002)

Each object of this class has its own icon. This flag is used internally by the Shell to handle cases like Setup.exe, where objects with identical names can have different icons. Typical implementations of [IExtractIcon](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iextracticona) do not require this flag.

##### - pwFlags.GIL_SHIELD (0x0200)

**Windows Vista only**. The calling application must stamp the icon with the UAC shield.

##### - pwFlags.GIL_SIMULATEDOC (0x0001)

The calling application should create a document icon using the specified icon.

##### - uFlags.GIL_ASYNC (0x0020)

Set this flag to determine whether the icon should be extracted asynchronously. If the icon can be extracted rapidly, this flag is usually ignored. If extraction will take more time, **GetIconLocation** should return E_PENDING. See the Remarks for further discussion.

##### - uFlags.GIL_CHECKSHIELD (0x0200)

Explicitly return either GIL_SHIELD or GIL_FORCENOSHIELD in *pwFlags*. Do not block if GIL_ASYNC is set.

##### - uFlags.GIL_DEFAULTICON (0x0040)

Retrieve information about the fallback icon. Fallback icons are usually used while the desired icon is extracted and added to the cache.

##### - uFlags.GIL_FORSHELL (0x0002)

The icon is displayed in a Shell folder.

##### - uFlags.GIL_FORSHORTCUT (0x0080)

The icon indicates a shortcut. However, the icon extractor should not apply the shortcut overlay; that will be done later. Shortcut icons are state-independent.

##### - uFlags.GIL_OPENICON (0x0001)

The icon is in the open state if both open-state and closed-state images are available. If this flag is not specified, the icon is in the normal or closed state. This flag is typically used for folder objects.

## Return value

Type: **HRESULT**

Returns S_OK if the function returned a valid location, or S_FALSE if the Shell should use a default icon. If the **GIL_ASYNC** flag is set in *uFlags*, the method can return E_PENDING to indicate that icon extraction will be time-consuming.

## Remarks

When a client sets the **GIL_ASYNC** flag in *uFlags* and receives E_PENDING as a return value, it typically creates a background thread to extract the icon. It calls **GetIconLocation** from that thread, without the **GIL_ASYNC** flag, to retrieve the icon location. It then calls [IExtractIcon::Extract](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-extract) to extract the icon. Returning E_PENDING implies that the object is free threaded. In other words, it can safely be called concurrently by multiple threads.

The **GIL_DEFAULTICON** flag is usually set in the case where the desired icon is found, but that icon is not present in the icon cache. Icon extraction is a low priority background process, and as such may be delayed by other processes. The default icon will be displayed in place of the final icon during the time that it takes for that final icon to be extracted, added to the cache, and made available.