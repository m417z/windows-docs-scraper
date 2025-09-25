# PFNDPAMERGECONST callback function

## Description

Defines the prototype for the merge function used by [DPA_Merge](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nf-dpa_dsa-dpa_merge), using constant values.

## Parameters

### `uMsg` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A message that instructs this function how to handle the merge. One of the following values.

| Value | Meaning |
| --- | --- |
| **DPAMM_MERGE**<br><br>0x1 | Perform any additional processing needed when merging *p2* into *p1*. The function should return a pointer to an item that contains the result of the merge. |
| **DPAMM_DELETE**<br><br>0x2 | Perform any additional processing needed when a delete occurs as part of the merge. The function should return **NULL**. |
| **DPAMM_INSERT**<br><br>0x3 | Perform any user-defined processing when the merge results in an item being inserted as part of the merge. The return value of this function should point to the item result that is inserted as part of the merge. |

### `pvDest` [in]

Type: **const void***

A pointer to the destination item in the merge.

### `pvSrc` [in]

Type: **const void***

A pointer to the source item in the merge.

### `lParam` [in]

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Additional data that can be used by the merge callback.

## Return value

Type: **const void***

A pointer to constant data which results from the merge, or **NULL** if there is a failure when DPAMM_MERGE or DPAMM_INSERT is used.

## See also

[PFNDPAMERGE](https://learn.microsoft.com/windows/desktop/api/dpa_dsa/nc-dpa_dsa-pfndpamerge)