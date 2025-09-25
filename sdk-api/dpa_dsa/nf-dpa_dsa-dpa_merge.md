# DPA_Merge function

## Description

[**DPA_Merge** is available through Windows XP with Service Pack 2 (SP2). It might be altered or unavailable in subsequent versions.]

Combines the contents of two dynamic pointer arrays (DPAs).

## Parameters

### `hdpaDest` [in, out]

Type: **HDPA**

A handle to the first DPA. This array can be optionally presorted. When this function returns, contains the handle to the merged array.

### `hdpaSrc` [in]

Type: **HDPA**

A handle to the second DPA. This array can be optionally presorted.

### `dwFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Options determining the method used to merge the two arrays. DPAM_NORMAL, DPAM_UNION, and DPAM_UNION are mutually exclusive—only one of those flags can be set, optionally in conjunction with DPAM_SORTED.

| Value | Meaning |
| --- | --- |
| **DPAM_SORTED**<br><br>0x00000001 | The arrays are presorted; skip sorting. If this flag is not set, the arrays are sorted before they are merged. |
| **DPAM_NORMAL**<br><br>0x00000002 | The final array consists of all of the elements originally present in *hdpaDest*. If any of those elements are also found in *hdpaSrc*, those elements are merged in the final array. The [PFNDPAMERGE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpamerge) callback function is called with the DPAMM_MERGE message.<br><br> <br><br>When this flag is set, the final size of the array at *hdpaDest* is the same as its initial size. |
| **DPAM_UNION**<br><br>0x00000004 | The final array is the union of all elements in both arrays. Elements found in both arrays are merged in the final array. Elements found in only one array or the other are added as found. When this flag is set, the [PFNDPAMERGE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpamerge) callback function can be called with the DPAMM_MERGE or DPAMM_INSERT message. <br><br> <br><br>The final size of the array is at least the size of the larger of *hdpaDest* and *hdpaSrc*, and at most the sum of the two. |
| **DPAM_INTERSECT**<br><br>0x00000008 | Only elements found in both *hdpaSrc* and *hdpaDest* are merged to form the final array. When this flag is set, the [PFNDPAMERGE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpamerge) callback function can be called with the DPAMM_MERGE or DPAMM_DELETE message. <br><br> <br><br>The final size of the array can range between 0 and the smaller of *hdpaDest* and *hdpaSrc*. |

### `pfnCompare` [in]

Type: **[PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare)**

The [PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare) callback function that compares two elements, one from each DPA, to determine whether they are the same item. If so, the callback function pointed to by *pfnCompare* is called.

### `pfnMerge` [in]

Type: **[PFNDPAMERGE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpamerge)**

The [PFNDPAMERGE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpamerge) callback function that merges the contents when an element is found in both DPAs and is found to be the same item by [PFNDPACOMPARE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndacompare).

### `lParam` [in]

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Additional parameter used to declare the basis of comparison upon which equality is determined.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if successful; otherwise, **FALSE**.

## Remarks

**DPA_Merge** is not exported by name. To use it, you must use [GetProcAddress](https://learn.microsoft.com/windows/desktop/api/libloaderapi/nf-libloaderapi-getprocaddress) and request ordinal 11 from ComCtl32.dll to obtain a function pointer.