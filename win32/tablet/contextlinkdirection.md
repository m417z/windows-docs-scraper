# ContextLinkDirection enumeration

Specifies the direction of an [**IContextLink**](https://learn.microsoft.com/windows/win32/tablet/icontextlink) object.

## Constants

**ContextLinkDirection\_LinksWith**

The [**IContextNode**](https://learn.microsoft.com/windows/win32/tablet/icontextnode) is a directional drawing that points away from the [**IContextLink**](https://learn.microsoft.com/windows/win32/tablet/icontextlink).

**ContextLinkDirection\_LinksFrom**

The [**IContextNode**](https://learn.microsoft.com/windows/win32/tablet/icontextnode) is a directional drawing that points to the [**IContextLink**](https://learn.microsoft.com/windows/win32/tablet/icontextlink).

**ContextLinkDirection\_LinksTo**

There are no directional drawings in the link. For example, an ink drawing can underline an ink word. There is no direction inferred from the underline.

## Examples

The following example takes an [**IContextNode**](https://learn.microsoft.com/windows/win32/tablet/icontextnode) object, `m_pSelectedNode`, and saves all the **IContextNode** objects that it links to by walking up the ancestor tree and adding the objects into a `CArray` object, `linkedToNodes`. `CheckHResult` is a function that takes an `HRESULT` and a string, and throws an exception created with the string if the `HRESULT` is not **SUCCESS**.

```C++
// Find all first ancestor that contains links of type Enclose
CArray<IContextNode*,IContextNode*> linkedToNodes = CArray<IContextNode*,IContextNode*>();
IContextNode* pAncestor;
CheckHResult(m_pSelectedNode->GetParentNode(&pAncestor),
    "IContextNode::GetParentNode failed");
while (pAncestor != NULL)
{
    // Get the links
    IContextLinks* pLinks;
    CheckHResult(pAncestor->GetContextLinks(&pLinks),
        "IContextNode::GetContextLinks failed");
    ULONG nLinks;
    CheckHResult(pLinks->GetCount(&nLinks), "IContextLinks::GetCount failed");
    for (ULONG i = 0; i < nLinks; i++)
    {
        IContextLink* pLink;
        CheckHResult(pLinks->GetContextLink(i, &pLink),
            "IContextLinks::GetContextLink failed");
        // Check link direction
        ContextLinkDirection linkDirection;
        CheckHResult(pLink->GetContextLinkDirection(&linkDirection),
            "IContextLink:GetContextLinkDirection failed");
        if (linkDirection == ContextLinkDirection_LinksTo)
        {
            // Get source node and add the array
            IContextNode* pSourceNode;
            CheckHResult(pLink->GetSourceNode(&pSourceNode),
                "IContextLink::GetSourceNode failed");
            linkedToNodes.Add(pSourceNode);
        }
    }

    // Go up another level
    IContextNode* pNewAncestor;
    CheckHResult(pAncestor->GetParentNode(&pNewAncestor),
        "IContextNode::GetParentNode failed");
    pAncestor = pNewAncestor;
}
```

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[**IContextLink**](https://learn.microsoft.com/windows/win32/tablet/icontextlink)

[**IContextNode::AddContextLink**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-addcontextlink)

