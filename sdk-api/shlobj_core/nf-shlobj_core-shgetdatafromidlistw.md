# SHGetDataFromIDListW function

## Description

Retrieves extended property data from a relative identifier list.

## Parameters

### `psf` [in]

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

The address of the parent [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface. This must be the immediate parent of the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure referenced by the *pidl* parameter.

### `pidl` [in]

Type: **PCUITEMID_CHILD**

A pointer to an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure that identifies the object relative to the folder specified in *psf*.

### `nFormat`

Type: **int**

The format in which the data is being requested. This parameter must be set to one of the following values.

#### SHGDFIL_FINDDATA

Format used for file system objects. The *pv* parameter is the address of a [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure.

#### SHGDFIL_NETRESOURCE

Format used for network resources. The *pv* parameter is the address of a [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) structure.

#### SHGDFIL_DESCRIPTIONID

[Version 4.71](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Format used for network resources. The *pv* parameter is the address of an [SHDESCRIPTIONID](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shdescriptionid) structure.

### `pv` [out]

Type: **void***

A pointer to a buffer that, when this function returns successfully, receives the requested data. The format of this buffer is determined by *nFormat*.

If *nFormat* is **SHGDFIL_NETRESOURCE**, there are two possible cases. If the buffer is large enough, the net resource's string information (fields for the network name, local name, provider, and comments) will be placed into the buffer. If the buffer is not large enough, only the net resource structure will be placed into the buffer and the string information pointers will be **NULL**.

### `cb`

Type: **int**

Size of the buffer at *pv*, in bytes.

##### - nFormat.SHGDFIL_DESCRIPTIONID

[Version 4.71](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Format used for network resources. The *pv* parameter is the address of an [SHDESCRIPTIONID](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shdescriptionid) structure.

##### - nFormat.SHGDFIL_FINDDATA

Format used for file system objects. The *pv* parameter is the address of a [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure.

##### - nFormat.SHGDFIL_NETRESOURCE

Format used for network resources. The *pv* parameter is the address of a [NETRESOURCE](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) structure.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or E_INVALIDARG otherwise.

## Remarks

This function extracts only information that is present in the pointer to an item identifier list (PIDL). Since the content of a PIDL depends on the folder object that created the PIDL, there is no guarantee that all requested information will be available. In addition, the information that is returned reflects the state of the object at the time the PIDL was created. The current state of the object could be different. For example, if you set *nFormat* to **SHGDFIL_FINDDATA**, the function might assign meaningful values to only some of the members of the [WIN32_FIND_DATA](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-win32_find_dataa) structure. The remaining members will be set to zero. To retrieve complete current information on a file system file or folder, use standard file system functions such as [GetFileTime](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-getfiletime) or [FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea).

E_INVALIDARG is returned if the *psf*, *pidl*, *pv*, or *cb* parameter does not match the *nFormat* parameter, or if *nFormat* is not one of the specific SHGDFIL_ values shown above.

> [!NOTE]
> The shlobj_core.h header defines SHGetDataFromIDList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).