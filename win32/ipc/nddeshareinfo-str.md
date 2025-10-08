# NDDESHAREINFO structure

\[Network DDE is no longer supported. Nddeapi.dll is present on Windows Vista, but all function calls return NDDE\_NOT\_IMPLEMENTED.\]

Contains DDE share attributes maintained by the NetDDE Share Database Manager (DSDM). The security descriptor associated with each DDE share is not passed through this structure but is accessed through specific functions. The NetDDE DSDM API accepts this structure for set functions; for get functions, the DSDM returns the structure packed into the supplied buffer along with the data referenced by the members **lpszShareName**, **lpszAppTopicList**, and **lpszItemList**.

## Members

**lRevision**

The revision level of the **NDDESHAREINFO** structure. Currently, the revision level is 1.

**lpszShareName**

The name of the share. This string must be no more than MAX\_NDDESHARENAME characters long.

**lShareType**

One or more DDE share types. This member can be a combination of the following supported DDE share types.

| Share type | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------|
| **SHARE\_TYPE\_NEW**<br>0x02 | The share contains an OLE application/topic pair.<br> |
| **SHARE\_TYPE\_OLD**<br>0x01 | The share contains a DDE application/topic pair.<br> |
| **SHARE\_TYPE\_STATIC**<br>0x04 | The share contains a static application/topic pair.<br> |

**lpszAppTopicList**

A pointer to a buffer containing null-terminated strings for the DDE, OLE, and static application/topic pairs. The buffer should be in the following format:

``` syntax
<DDE application name>|<DDE topic name>\0
<OLE application name>|<OLE topic name>\0
<static application name>|<static topic name>\0\0
```

**fSharedFlag**

If this member is **FALSE**, the DDE share will not allow remote users to communicate through it by using DDE. However, local users can still communicate through the DDE share. Local client links are always implied if the associated DACL grants access.

**fService**

If this member is set, the DDE share will not check whether the current user has set it as trusted before allowing DDE communication.

**fStartAppFlag**

If this member is set and the share is trusted to start applications, NetDDE will attempt to start the application specified by **lpszAppTopicList** if it cannot initially start a DDE conversation with the application.

**nCmdShow**

When NetDDE starts an application to initiate a DDE conversation, this value is sent to the application through the *nCmdShow* parameter of the [**WinMain**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-winmain) function. It defines the preferred mode for the application window to be shown in. This parameter is significant only if **fStartAppFlag** is active. The logged on user in whose context the application is started can also override this option when promoting the share to trusted status. The default for this member is SW\_SHOWMAXIMIZED.

**qModifyId**

An 8-byte serial number that indicates the modification serial number of the DDE share. Every time the DDE share is modified by a [**NDdeShareSetInfo**](https://learn.microsoft.com/windows/win32/ipc/nddesharesetinfo) or [**NDdeSetShareSecurity**](https://learn.microsoft.com/windows/win32/ipc/nddesetsharesecurity) call, these values are changed.

**cNumItems**

The number of items listed in **lpszItemList**. If **cNumItems** is zero, then **lpszItemList** is empty, and the share information and associated security descriptor apply to all items serviced by the associated application.

**lpszItemList**

A pointer to a buffer containing null-terminated strings that specify the items the client application in a DDE transaction can request or start advise loops on. If no items are listed, the DDE share allows any item to be used. The number of items in the list must match the **cNumItems** count.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Nddeapi.h |

## See also

[Network Dynamic Data Exchange Overview](https://learn.microsoft.com/windows/win32/ipc/network-dynamic-data-exchange)

[Network DDE Structures](https://learn.microsoft.com/windows/win32/ipc/network-dde-structures)

[**NDdeSetShareSecurity**](https://learn.microsoft.com/windows/win32/ipc/nddesetsharesecurity)

[**NDdeShareSetInfo**](https://learn.microsoft.com/windows/win32/ipc/nddesharesetinfo)

[**WinMain**](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-winmain)

