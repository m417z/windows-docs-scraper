# CryptCATEnumerateMember function

## Description

[The **CryptCATEnumerateMember** function is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

The **CryptCATEnumerateMember** function enumerates the members of a catalog.

## Parameters

### `hCatalog` [in]

The handle of the catalog that contains the members to enumerate. This value cannot be **NULL**.

### `pPrevMember` [in]

A pointer to a [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that identifies which member of the catalog was last retrieved. If this parameter is **NULL**, this function will retrieve the first member of the catalog.

## Return value

This function returns a pointer to a [CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember) structure that represents the next member of the catalog. If there are no more members in the catalog to enumerate, this function returns **NULL**.

## Remarks

Do not free the returned pointer nor any of the members pointed to by the returned pointer.

#### Examples

The following pseudocode example shows how to use this function to enumerate all of the members of a catalog.

```cpp
CRYPTCATMEMBER *pMember = NULL;

for(pMember = CryptCATEnumerateMember(hCatalog, pMember);
    NULL != pMember;
    pMember = CryptCATEnumerateMember(hCatalog, pMember))
{
   // Use the catalog member.
}
```

## See also

[CRYPTCATMEMBER](https://learn.microsoft.com/windows/desktop/api/mscat/ns-mscat-cryptcatmember)