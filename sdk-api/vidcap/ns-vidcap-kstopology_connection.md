# KSTOPOLOGY_CONNECTION structure

## Description

This topic applies to Windows XP Service Pack 2 or later.

The **KSTOPOLOGY_CONNECTION** structure describes a node connection within a kernel-streaming (KS) filter. A node can be connected to another node within the filter, or to a pin on the filter.

## Members

### `FromNode`

Index of the upstream node in the connection. If the upstream connection is a pin, rather than a node, the value is KSFILTER_NODE.

### `FromNodePin`

If the value of the **FromNode** field is KSFILTER_NODE, this field specifies the index of the upstream pin. Otherwise, this field is ignored.

### `ToNode`

Index of the downstream node in the connection. If the downstream connection is a pin, rather than a node, the value is KSFILTER_NODE.

### `ToNodePin`

If the value of the **ToNode** field is KSFILTER_NODE, this field specifies the index of the downstream pin. Otherwise, this field is ignored.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)

[IKsTopologyInfo::get_ConnectionInfo](https://learn.microsoft.com/windows/desktop/api/vidcap/nf-vidcap-ikstopologyinfo-get_connectioninfo)