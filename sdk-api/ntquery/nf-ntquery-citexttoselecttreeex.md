# CITextToSelectTreeEx function

## Description

[Indexing Service is no longer supported as of Windows XP and is unavailable for use as of Windows 8. Instead, use [Windows Search](https://learn.microsoft.com/windows/desktop/search/-search-3x-wds-overview) for client side search and [Microsoft Search Server Express](http://www.microsoft.com/en-us/download/details.aspx?id=18914) for server side search.]

Creates a **SELECT** node for a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure using the Query Language Dialect that you specify.

## Parameters

### `pwszRestriction`

A pointer to a null-terminated string specifying an Indexing Service query. The syntax for queries is described in [Query Languages for Indexing Service](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/query-languages-for-indexing-service).

### `ulDialect`

A value from [ISQLANG_*](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/isqlang-constants) constants that specifies a specific version of the Indexing Service query language to be used.

### `ppTree`

A pointer to a variable that receives a pointer to the [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure for the command tree built by the function.

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
| **E_ACCESSDENIED** | The function was denied access to the specified path. |
| **E_HANDLE** | The function encountered an invalid handle, probably due to a low-memory situation. |
| **E_INVALIDARG** | The function received an invalid parameter. |
| **E_OUTOFMEMORY** | The function did not have sufficient memory or other resources to complete the operation. |
| **E_FAIL** | An unknown error has occurred. |

## Remarks

Command trees created by the **CITextToSelectTreeEx** function contain the select portion of a [DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree) structure. A tree returned by the **CITextToSelectTreeEx** function can be combined with project and sort nodes to form a complete command tree. Use the **CITextToSelectTreeEx** function instead of the [CITextToFullTreeEx](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttofulltreeex) function if the sort order and project columns tree nodes are already available.

The query tree allocated by the **CITextToSelectTreeEx** function must be freed either with the [ICommandTree::FreeCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-freecommandtree) method or passed to the [ICommandTree::SetCommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nf-cmdtree-icommandtree-setcommandtree) method with the *fCopy* parameter set to **FALSE**.

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
HRESULT hr = CiTextToSelectTreeEx( L"microsoft and @issuenumber=2",
                                 ISQLANG_V1
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

## See also

[CIPROPERTYDEF](https://learn.microsoft.com/windows/desktop/api/ntquery/ns-ntquery-cipropertydef)

[CIRestrictionToFullTree](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-cirestrictiontofulltree)

[CITextToFullTreeEx](https://learn.microsoft.com/windows/desktop/api/ntquery/nf-ntquery-citexttofulltreeex)

[DBCOMMANDTREE](https://learn.microsoft.com/previous-versions/windows/desktop/indexsrv/dbcommandtree)

[ICommandTree](https://learn.microsoft.com/previous-versions/windows/desktop/api/cmdtree/nn-cmdtree-icommandtree)