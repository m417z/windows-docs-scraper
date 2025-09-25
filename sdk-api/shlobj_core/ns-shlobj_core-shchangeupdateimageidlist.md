# SHChangeUpdateImageIDList structure

## Description

[**SHChangeUpdateImageIDList** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Stores the information used as parameters to [SHUpdateImage](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shupdateimagea) in a form mimicking an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) so that they can be used by [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify).

## Members

### `cb`

Type: **USHORT**

The size of the structure, in bytes.

### `iIconIndex`

Type: **int**

The zero-based index of the icon in the file specified by **szName**. Obtain this value by calling [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation) and retrieving the value pointed to by *piIndex*.

### `iCurIndex`

Type: **int**

The zero-based index in the system image list of the icon being updated.

### `uFlags`

Type: **UINT**

Flags that determine the icon attributes. Obtain this value by calling [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation) and retrieving the value pointed to by *pwFlags*. These two flags are relevant to [SHUpdateImage](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shupdateimagea).

#### GIL_NOTFILENAME

The location is not a file name/index pair. Calling applications that decide to extract the icon from the location must call this object's [IExtractIcon::Extract](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-extract) method to obtain the desired icon images.

#### GIL_SIMULATEDOC

The calling application should create a document icon using the specified icon.

### `dwProcessID`

### `szName`

Type: **WCHAR[MAX_PATH]**

A null-terminated Unicode string that specifies the fully qualified path of the file that contains the icon. Obtain this value by calling [IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation) and retrieving the value pointed to by *szIconFile*.

### `cbZero`

Type: **USHORT**

#### - dwProcessIDint

Type: **DWORD**

The identifier of the process sending the SHCNE_UPDATEIMAGE notification.

## Remarks

This example demonstrates the use of **SHChangeUpdateImageIDList** and [SHChangeDWORDAsIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shchangedwordasidlist) by [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) to mimic the [SHUpdateImage](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shupdateimagea) function.

```
void MyUpdateImage(LPCWSTR pszHashItem, int iIndex, UINT uFlags, int iImageIndex)
{
    SHChangeUpdateImageIDList rgPidl;
    SHChangeDWORDAsIDList rgDWord;
    int cchLen;
    USHORT *pcb;

    // Validate parameters: iImageIndex must be a valid system image list value.
    if (iImageIndex < 0)
    {
        return;
    }

    // Validate parameters: pszHashItem must not exceed MAX_PATH in length
    cchLen = lstrlenW(pszHashItem);
    if (cchLen >= MAX_PATH)
    {
        return;
    }

    // Load SHChangeUpdateImageIDList
    rgPidl.dwProcessID = GetCurrentProcessId();
    rgPidl.iIconIndex = iIndex;
    rgPidl.iCurIndex = iImageIndex;
    rgPidl.uFlags = uFlags;
    lstrcpynW(rgPidl.szName, pszHashItem, MAX_PATH);
    pcb = &rgPidl.szName[cchLen+1];

    // Set the size of the first element
    rgPidl.cb = (USHORT)((BYTE*)pcb - (BYTE*)rgPidl);

    // Terminate the "ITEMIDLIST"
    *pcb = 0;

    // Load SHChangeDWORDAsIDList
    rgDWord.cb = (USHORT)FIELD_OFFSET(SHChangeDWORDAsIDList, cbZero);
    rgDWord.dwItem1 = iImageIndex;
    rgDWord.dwItem2 = 0;
    rgDWord.cbZero = 0;

    // Parameters are now in the form that SHCNE_UPDATEIMAGE can accept
    SHChangeNotify(SHCNE_UPDATEIMAGE, SHCNF_IDLIST, &rgDWord, &rgPidl);
}
```

## See also

[IExtractIcon::GetIconLocation](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iextracticona-geticonlocation)

[SHChangeDWORDAsIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shchangedwordasidlist)