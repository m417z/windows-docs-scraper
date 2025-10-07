# ConfirmationType enumeration

Specifies the type of confirmation that can occur on an [**IContextNode**](https://learn.microsoft.com/windows/win32/tablet/icontextnode) object.

## Constants

**ConfirmationType\_None**

No confirmation is applied. The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) is free to change a context node or any of its descendants as needed.

**ConfirmationType\_NodeTypeAndProperties**

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) cannot change the type or any properties of the specified context node.

**ConfirmationType\_TopBoundary**

The [**IInkAnalyzer**](https://learn.microsoft.com/windows/win32/tablet/iinkanalyzer) will not perform operations, including adding ink or merging with other [**ContextNodes**](https://learn.microsoft.com/windows/win32/tablet/icontextnodes), that cause the TopBoundary to move beyond the current top boundary. For example:

- An application analyzes a set of Ink, and a ParagraphNode is identified.
- The application confirms the TopBoundary of this paragraph.
- The user of the application writes new ink above the current paragraph. When analyze is called again, the new ink will not be incorporated into the Confirmed paragraph node.
- Since only the top boundary is confirmed, the ContextNode can continue to grow in other directions. Deleting strokes can cause the top boundary to move down. Translating the ContextNode can cause the location to change, but will not allow additional ink to be merged in the new location.

This ConfirmationType is only applicable to paragraph nodes.

## Remarks

You can use the **NodeTypeAndProperties** value only for ink word and ink drawing nodes (see [**IContextNode::GetType**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-gettype)). Otherwise, an **E\_INVALIDARG** is returned from [**IContextNode::Confirm**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-confirm).

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |
| Header<br> | IACom.h (also requires IACom\_i.c) |

## See also

[**IContextNode::Confirm**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-confirm)

[**IContextNode::IsConfirmed**](https://learn.microsoft.com/windows/win32/tablet/icontextnode-isconfirmed)

