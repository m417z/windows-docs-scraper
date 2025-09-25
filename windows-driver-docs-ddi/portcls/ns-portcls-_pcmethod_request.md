# _PCMETHOD_REQUEST structure

## Description

The PCMETHOD_REQUEST structure specifies a method request.

## Members

### `MajorTarget`

Pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of a miniport object that supports the method set and method specified by **MethodItem**.

### `MinorTarget`

Pointer to an [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown) interface of a stream object associated with **MajorTarget**. If the request does not specify a minor target, set this member to **NULL**.

### `Node`

Specifies the node ID of the target node for the request. If the target is not a node, this member is set to ULONG(-1).

### `MethodItem`

Pointer to a [PCMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcmethod_item) structure that describes a method supported by a filter, pin, or node.

### `Verb`

Specifies the type of method request. This member can be set to the bitwise OR of one or more of the flag bits in the following table.

| Flag bit | Meaning |
| --- | --- |
| PCMETHOD_ITEM_FLAG_BASICSUPPORT | Returns basic support information about the method specified by **MethodItem**->**Id**. |
| PCMETHOD_ITEM_FLAG_SEND | Executes the method specified by **MethodItem**->**Id**. The client should conform to the basic-support information for the method. |
| PCMETHOD_ITEM_FLAG_SETSUPPORT | Returns information about support for the method set specified by **MethodItem**->**Set**. |

## Remarks

This is the structure that the port driver passes to the miniport driver's method-handler routine. The [PCMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcmethod_item) structure contains a pointer to a method handler that takes a PCMETHOD_REQUEST pointer as its single call parameter.

The WDM audio subsystem does not currently support method requests.

## See also

[PCFILTER_NODE](https://learn.microsoft.com/previous-versions/ff537695(v=vs.85))

[PCMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/ns-portcls-pcmethod_item)