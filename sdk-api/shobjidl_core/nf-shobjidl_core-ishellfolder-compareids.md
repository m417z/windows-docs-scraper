# IShellFolder::CompareIDs

## Description

Determines the relative order of two file objects or folders, given their item identifier lists.

## Parameters

### `lParam` [in]

Type: **LPARAM**

A value that specifies how the comparison should be performed.

The lower sixteen bits of *lParam* define the sorting rule. Most applications set the sorting rule to the default value of zero, indicating that the two items should be compared by name. The system does not define any other sorting rules. Some folder objects might allow calling applications to use the lower sixteen bits of *lParam* to specify folder-specific sorting rules. The rules and their associated *lParam* values are defined by the folder.

When the system folder view object calls **IShellFolder::CompareIDs**, the lower sixteen bits of *lParam* are used to specify the column to be used for the comparison.

The upper sixteen bits of *lParam* are used for flags that modify the sorting rule. The system currently defines these modifier flags.

#### SHCIDS_ALLFIELDS

[Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). Compare all the information contained in the [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure, not just the display names. This flag is valid only for folder objects that support the [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2) interface. For instance, if the two items are files, the folder should compare their names, sizes, file times, attributes, and any other information in the structures. If this flag is set, the lower sixteen bits of *lParam* must be zero.

#### SHCIDS_CANONICALONLY

[Version 5.0](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb776779(v=vs.85)). When comparing by name, compare the system names but not the display names. When this flag is passed, the two items are compared by whatever criteria the Shell folder determines are most efficient, as long as it implements a consistent sort function. This flag is useful when comparing for equality or when the results of the sort are not displayed to the user. This flag cannot be combined with other flags.

### `pidl1` [in]

Type: **PCUIDLIST_RELATIVE**

A pointer to the first item's [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. It will be relative to the folder. This **ITEMIDLIST** structure can contain more than one element; therefore, the entire structure must be compared, not just the first element.

### `pidl2` [in]

Type: **PCUIDLIST_RELATIVE**

A pointer to the second item's [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure. It will be relative to the folder. This **ITEMIDLIST** structure can contain more than one element; therefore, the entire structure must be compared, not just the first element.

## Return value

Type: **HRESULT**

If this method is successful, the CODE field of the **HRESULT** contains one of the following values. For information regarding the extraction of the CODE field from the returned **HRESULT**, see Remarks. If this method is unsuccessful, it returns a COM error code.

| Return code | Description |
| --- | --- |
| **Negative** | A negative return value indicates that the first item should precede the second (pidl1 < pidl2). |
| **Positive** | A positive return value indicates that the first item should follow the second (pidl1 > pidl2). |
| **Zero** | A return value of zero indicates that the two items are the same (pidl1 = pidl2). |

## Remarks

### Note to Calling Applications

Do not set the **SHCIDS_ALLFIELDS** flag in *lParam* if the folder object does not support [IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2). Doing so might have unpredictable results. If you use the **SHCIDS_ALLFIELDS** flag, the lower sixteen bits of *lParam* must be set to zero.

Use the [HRESULT_CODE](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_code) macro to extract the CODE field from the **HRESULT**, then cast the result as a **short**.

```cpp
HRESULT hres = psf->CompareIDs(lParam, pidl1, pidl2);
if ((short)HRESULT_CODE(hres) < 0)
   { /* pidl1 comes first */ }
else if ((short)HRESULT_CODE(hres) > 0)
   { /* pidl2 comes first */ }
else
   { /* the two pidls are equal */ }

```

### Note to Implementers

To extract the sorting rule, use a bitwise AND operator (&) to combine *lParam* with SHCIDS_COLUMNMASK (0X0000FFFF). This operation masks off the upper sixteen bits of *lParam*, including the **SHCIDS_ALLFIELDS** value.

The [MAKE_HRESULT](https://learn.microsoft.com/windows/desktop/api/dmerror/nf-dmerror-make_hresult) macro is useful for constructing the return value for
an implementation of the CompareIDs method. For example:

```cpp
HRESULT CompareIDs(LPARAM lParam, PCUIDLIST_RELATIVE pidl1, PCUIDLIST_RELATIVE pidl2)
{
    short sResult;
    unsigned uSeverity = 0x000000000;

    // Code that determines the relative order of pidl1 and pidl2 according to
    // any sorting rules specified by lParam goes here.
    //
    // Set sResult = -1 if pidl1 precedes pidl2 (pidl1 < pidl2).
    // Set sResult =  1 if pidl1 follows pidl2. (pidl1 > pidl2).
    // Set sResult =  0 if pidl1 and pidl2 are equivalent in terms of ordering. (pidl1 = pidl2).
    //
    // Leave uSeverity = 0 if the order is successfully determined.
    // Set uSeverity = 0x00000001 if there is an error.

    return MAKE_HRESULT(uSeverity, 0, (unsigned short)sResult);
}

```

## See also

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)