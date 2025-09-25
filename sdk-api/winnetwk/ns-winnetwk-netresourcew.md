# NETRESOURCEW structure

## Description

The following structure contains information about a network resource. It is used by several of the network provider functions, including
[NPOpenEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npopenenum)
and [NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection).

## Members

### `dwScope`

Indicates the scope of the enumeration. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RESOURCE_CONNECTED** | Current connections to network resources. |
| **RESOURCE_GLOBALNET** | All network resources. These may or may not be connected. |
| **RESOURCE_CONTEXT** | The network resources associated with the user's current and default network context. The meaning of this is provider-specific. |

### `dwType`

Indicates the resource type. This can be one of the following values.

| Value | Meaning |
| --- | --- |
| **RESOURCETYPE_DISK** | The resource is a shared disk volume. |
| **RESOURCETYPE_PRINT** | The resource is a shared printer. |
| **RESOURCETYPE_ANY** | The resource matches more than one type, for example, a container of both print and disk resources, or a resource which is neither print or disk. |

### `dwDisplayType`

Set by the provider to indicate what display type a user interface should use to represent this resource. The following types are defined.

| Value | Meaning |
| --- | --- |
| **RESOURCEDISPLAYTYPE_NETWORK** | The resource is a network provider. |
| **RESOURCEDISPLAYTYPE_DOMAIN** | The resource is a collection of servers. |
| **RESOURCEDISPLAYTYPE_SERVER** | The resource is a server. |
| **RESOURCEDISPLAYTYPE_SHARE** | The resource is a share point. |
| **RESOURCEDISPLAYTYPE_DIRECTORY** | The resource is a directory. |
| **RESOURCEDISPLAYTYPE_GENERIC** | The resource type is unspecified. This value is used by network providers that do not specify resource types. |

### `dwUsage`

A bitmask that indicates how you can enumerate information about the resource. It is defined only if **dwScope** is set to RESOURCE_GLOBALNET. The **dwUsage** field can contain one or more of the following flags.

| Value | Meaning |
| --- | --- |
| **RESOURCEUSAGE_CONNECTABLE** | You can connect to the resource by calling [NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection). If **dwType** is RESOURCETYPE_DISK, then, after you have connected to the resource, you can use the file system APIs, such as [FindFirstFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findfirstfilea), and [FindNextFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-findnextfilea), to enumerate any files and directories the resource contains. |
| **RESOURCEUSAGE_CONTAINER** | The resource is a container for other resources that can be enumerated by means of the [NPOpenEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npopenenum), [NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource), and [NPCloseEnum](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npcloseenum) functions. <br><br>The container may, however, be empty at the time the enumeration is made. In other words, the first call to [NPEnumResource](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npenumresource) may return WN_NO_MORE_ENTRIES. |

### `lpLocalName`

If **dwScope** is RESOURCE_CONNECTED, the **lpLocalName** field contains the name of a redirected device. If the connection is a deviceless connection, this field contains **NULL**.

If **dwScope** is not set to RESOURCE_CONNECTED, this field is undefined.

### `lpRemoteName`

If the enumerated item is a network resource, this field contains a remote network name. This name may be then passed to
[NPAddConnection](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-npaddconnection) to make a network connection if **dwUsage** is set to RESOURCEUSAGE_CONNECTABLE. If the enumerated item is a current connection, this field will refer to the remote network name that **lpLocalName** is connected to.

### `lpComment`

May be any provider-supplied comment associated with the enumerated item.

### `lpProvider`

Specifies the name of the provider that owns this enumerated item.

## Remarks

> [!NOTE]
> The winnetwk.h header defines NETRESOURCE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).