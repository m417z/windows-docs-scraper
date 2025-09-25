# SHChangeDWORDAsIDList structure

## Description

[**SHChangeDWORDAsIDList** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Stores two **DWORD** values in a form mimicking an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) so that they can be used by [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify).

## Members

### `cb`

Type: **USHORT**

The size of the structure, in bytes.

### `dwItem1`

Type: **DWORD**

First **DWORD** value.

### `dwItem2`

Type: **DWORD**

Second **DWORD** value.

### `cbZero`

Type: **USHORT**

## Remarks

This example demonstrates the use of [SHChangeUpdateImageIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shchangeupdateimageidlist) and **SHChangeDWORDAsIDList** by [SHChangeNotify](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shchangenotify) to mimic the [SHUpdateImage](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shupdateimagea) function.

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

[SHChangeUpdateImageIDList](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shchangeupdateimageidlist)