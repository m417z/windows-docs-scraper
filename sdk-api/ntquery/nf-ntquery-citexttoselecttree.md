# CITextToSelectTree function

## Description

> [!Note]
> Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](https://www.microsoft.com/download/details.aspx?id=18914) for server side search.

Creates a **SELECT** node for a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure using Query Language Dialect 1.

## Parameters

### `pwszRestriction`

A pointer to a null-terminated string specifying an Indexing Service Query Language Dialect 1 query.

### `ppTree`

A pointer to the address of the location to receive the [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure that represents the top node of the **SELECT** part of the full command tree.

### `cProperties`

The number of properties in the *pProperties* array, or zero if *pProperties* is **NULL**.

### `pProperties`

A pointer to an array of properties that can be referred to by friendly name in *pwszRestriction*. Column names in the **wcsFriendlyName** member of each [CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef) structure must be specified in uppercase. Indexing Service's built-in properties do not need to be defined to be used. It is an error to define a property with the same friendly name as that of a built-in property.

### `LocaleID`

The locale identifier (LCID) used for nodes in the tree returned in *ppTree* that contain an LCID member, including such nodes as content restrictions and sort order.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation was completed successfully. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## Remarks

Command trees created by **CITextToSelectTree** contain the **SELECT** portion of a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure. A tree returned by **CITextToSelectTree** can be combined with project and sort nodes to form a complete command tree. Use **CITextToSelectTree** instead of the [CITextToFullTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttofulltree) function if the sort order and project columns tree nodes are already available.

The query tree allocated by **CITextToSelectTree** must be freed either with the [ICommandTree::FreeCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-freecommandtree) method or passed to the [ICommandTree::SetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-setcommandtree) method with the *fCopy* parameter set to **FALSE**.

#### Examples

This example creates a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure. A custom property from a Word document named "IssueNumber" of type "Number" is defined and used in the query.

```cpp
DBCOMMANDTREE * pCompleteTree;
DBCOMMANDTREE * pTableNode;

// ...
// Insert code here to make pCompleteTree a complete tree using pTableNode
// as the DBOP_table_name node that has no query restriction (yet).
// User CoTaskMemAlloc to allocate memory for the nodes.
// ...
//

CIPROPERTYDEF aProperties[1];
const GUID guidOffice = { 0xd5cdd505, 0x2e9c, 0x101b,
                          0x93, 0x97, 0x08, 0x00, 0x2b, 0x2c, 0xf9, 0xae }
                            };
aProperties[0].wcsFriendlyName = L"ISSUENUMBER";
aProperties[0].dbType = DBTYPE_R8;
aProperties[0].dbCol.uGuid.guid = guidOffice;
aProperties[0].dbCol.eKind = DBKIND_GUID_NAME;
aProperties[0].dbCol.pwszName.ulPropid = L"ISSUENUMBER";
DBCOMMANDTREE * pSelectTree;
HRESULT hr = CiTextToSelectTree( L"Microsoft and @issuenumber=2",
                                 &pSelectTree,
                                 1,
                                 aProperties,
                                 GetSystemDefaultLCID() );
if ( SUCCEEDED( hr ) )
{
    pTableNode->pctNextSibling = pSelectTree;
    hr = pICommand->SetCommandTree( pCompleteTree,
                                    DBCOMMANDREUSE_NONE,
                                    FALSE );
    if ( SUCCEEDED( hr ) )
    {
        // ...
        // execute a query
        // ...
    }
}

```

The following diagram shows the [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure pSelectTree created by the example code.

![](https://learn.microsoft.com/windows/win32/api/ntquery/images/dbcmdtr1.png)

## See also

[CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef)

[CIRestrictionToFullTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cirestrictiontofulltree)

[CITextToSelectTreeEx](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttoselecttreeex)

[DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree)

[ICommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nn-cmdtree-icommandtree)

