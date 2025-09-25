# CIDA structure

## Description

Used with the [CFSTR_SHELLIDLIST](https://learn.microsoft.com/windows/desktop/shell/clipboard) clipboard format to transfer the pointer to an item identifier list (PIDL) of one or more Shell namespace objects.

## Members

### `cidl`

Type: **UINT**

The number of PIDLs that are being transferred, not including the parent folder.

### `aoffset`

Type: **UINT[1]**

An array of offsets, relative to the beginning of this structure. The array contains **cidl**+1 elements. The first element of **aoffset** contains an offset to the fully qualified PIDL of a parent folder. If this PIDL is empty, the parent folder is the desktop. Each of the remaining elements of the array contains an offset to one of the PIDLs to be transferred. All of these PIDLs are relative to the PIDL of the parent folder.

## Remarks

To use this structure to retrieve a particular PIDL, add the **aoffset** value of the PIDL to the address of the structure. The following two macros can be used to retrieve PIDLs from the structure. The first retrieves the PIDL of the parent folder. The second retrieves a PIDL, specified by its zero-based index.

```
#define HIDA_GetPIDLFolder(pida) (LPCITEMIDLIST)(((LPBYTE)pida)+(pida)->aoffset[0])
#define HIDA_GetPIDLItem(pida, i) (LPCITEMIDLIST)(((LPBYTE)pida)+(pida)->aoffset[i+1])
```

The value that is returned by these macros is a pointer to the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. Since these structures vary in length, you must determine the end of the structure by parsing it. See [NameSpace](https://learn.microsoft.com/windows/desktop/shell/shell-namespace) for further discussion of PIDLs and the **ITEMIDLIST** structure.