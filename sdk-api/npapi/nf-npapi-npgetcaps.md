# NPGetCaps function

## Description

Returns information about which services are supported on the network.

## Parameters

### `nIndex` [in]

Specifies the type of information to return. The following values are defined.

| Value | Meaning |
| --- | --- |
| **WNNC_ADMIN** | A bitmask that indicates which administrative functions the network provider supports. |
| **WNNC_CONNECTION** | A bitmask that indicates which connection functions the network provider supports. |
| **WNNC_DIALOG** | A bitmask that indicates which provider-specific dialog box functions the network provider supports. |
| **WNNC_ENUMERATION** | A bitmask that indicates which enumeration functions the network provider supports. |
| **WNNC_NET_TYPE** | Network type and provider version. |
| **WNNC_SPEC_VERSION** | WNet API version supported by the provider. |
| **WNNC_START** | The [state](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) of the network provider. |
| **WNNC_USER** | A bitmask that indicates which user functions the network provider supports. |

## Return value

The **NPGetCaps** function returns either a constant or a bitmask, depending on the value of the *nIndex* parameter. A few of the *nIndex* values cause a constant to be returned. But in most cases, the *nIndex* parameter specifies which set of services to query, and the returned value is a bitmask that indicates which services in this set are supported. In these cases, a zero return value indicates that none of the services in the set are supported.

The following list shows the values that *nIndex* may contain, each followed by a description of what is returned for that value.

####WNNC_ADMIN
Returns a mask that indicates which of the administrative functions the network provider supports. This can be one or more of the following.

| Flag | Function supported |
| -----|------------------------ |
WNNC_ADM_DIRECTORYNOTIFY | [NPDirectoryNotify](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npdirectorynotify)
WNNC_ADM_GETDIRECTORYTYPE | [NPGetDirectoryType](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npgetdirectorytype)

####WNNC_CONNECTION
Returns a mask that indicates which of the connection functions the network provider supports. This can be one or more of the following.

| Flag | Function supported |
| -----|------------------------ |
| WNNC_CON_ADDCONECTION (0x00000001) | [NPAddConnection](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npaddconnection) |
| WNNC_CON_CANCELCONNECTION (0x00000002) | [NPCancelConnection](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npcancelconnection) |
| WNNC_CON_GETCONNECTIONS (0x00000004) | [NPGetConnection](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npgetconnection) |
| WNNC_CON_ADDCONECTION3 (0x00000008) | [NPAddConnection3](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npaddconnection3) |
| WNNC_CON_GETPERFORMANCE (0x00000040) | [NPGetConnectionPerformance](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npgetconnectionperformance) |
| WNNC_CON_DEFER (0x00000080) | Deferred connections are supported with [NPAddConnection3](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npaddconnection3). |

####WNNC_DIALOG
Returns a mask that indicates which of the dialog box functions the network provider supports. This can be one or more of the following.

| Flag | Function supported |
| -----|------------------------ |
| WNNC_DLG_DEVICEMODE| [NPDeviceMode](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npdevicemode) |
| WNNC_DLG_FORMATNETNAME| [NPFormatNetworkName](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npformatnetworkname) |
| WNNC_DLG_GETRESOURCEINFORMATION | [NPGetResourceInformation](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npgetresourceinformation) |
| WNNC_DLG_GETRESOURCEPARENT | [NPGetResourceParent](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npgetresourceparent) |
| WNNC_DLG_PERMISSIONEDITOR | This flag is not used. |
| WNNC_DLG_PROPERTYDIALOG | [NPPropertyDialog](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-nppropertydialog) and NPGetPropertyText |
| WNNC_DLG_SEARCHDIALOG | [NPSearchDialog](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npsearchdialog) |

####WNNC_ENUMERATION

Returns a mask that indicates which scopes of enumeration, if any, are supported. For more information about enumeration scopes, see the Parameters section in the reference topic NPOpenEnum. This can be one or more of the following.

| Flag | Enumeration type supported |
-------|-----------------------------
| WNNC_ENUM_GLOBAL (0x00000001) | [NPOpenEnum](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npopenenum) is implemented and supports a scope of all resources on the network. In other words, NPOpenEnum supports RESOURCE_GLOBALNET. |
| WNNC_ENUM_LOCAL (0x00000002) | [NPOpenEnum](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npopenenum) is implemented and supports a scope of all currently connected resources. In other words, NPOpenEnum supports RESOURCE_CONNECTED.|
| WNNC_ENUM_CONTEXT (0x00000004) | [NPOpenEnum](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npopenenum) is implemented and supports a scope of all resources associated with the user's current and default network context. In other words, NPOpenEnum supports RESOURCE_CONTEXT. |

**Note** If WNNC_ENUMERATION returns a nonzero bitmask, you know that the network provider supports [NPOpenEnum](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npopenenum) and can infer that the provider also supports [NPEnumResource](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npenumresource) and [NPCloseEnum](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npcloseenum). This is because a network provider that supports NPOpenEnum is also expected to support NPEnumResource and NPCloseEnum.
####WNNC_NET_TYPE
Returns a value that indicates the type of network that the network provider supports. The high word contains the provider type, and the low word may contain a subtype. Developers who are working on new providers should obtain a new network type from Microsoft. A provider that does not return the correct network type may cause the WNET functions to behave in unpredictable ways.

The network type can be one of the following.

* WNNC_NET_10NET
* WNNC_NET_INTERGRAPH
* WNNC_NET_3IN1
* WNNC_NET_LANMAN
* WNNC_NET_9TILES
* WNNC_NET_LANSTEP
* WNNC_NET_APPLETALK
* WNNC_NET_LANTASTIC
* WNNC_NET_AS400
* WNNC_NET_LIFENET
* WNNC_NET_BMC
* WNNC_NET_LOCUS
* WNNC_NET_BWNFS
* WNNC_NET_MASFAX
* WNNC_NET_CLEARCASE
* WNNC_NET_MSNET
* WNNC_NET_COGENT
* WNNC_NET_NETWARE
* WNNC_NET_CSC
* WNNC_NET_OBJECT_DIRE
* WNNC_NET_DCE
* WNNC_NET_PATHWORKS
* WNNC_NET_DECOREB
* WNNC_NET_POWERLAN
* WNNC_NET_DISTENCT
* WNNC_NET_PROTSTOR
* WNNC_NET_EXTENDNET
* WNNC_NET_RDR2SAMPLE
* WNNC_NET_FARALLON
* WNNC_NET_SHIVA
* WNNC_NET_FJ REDIR
* WNNC_NET_SUN_PC_NFS
* WNNC_NET_FRONTIER
* WNNC_NET_SYMFONET
* WNNC_NET_FTP_NFS
* WNNC_NET_TWINS
* WNNC_NET_HOB_NFS
* WNNC_NET_VINES
* WNNC_NET_IBMAL

####WNNC_SPEC_VERSION
Returns WNNC_SPEC_VERSION51. The high and low words of the return value contain the major and minor version numbers of the WNet API specification supported by the credential manager.

####WNNC_START
Returns one of the following values to indicate if and when the provider is likely to start. The MPR will wait for the longest time-out period specified by all network providers.

| Flag| Start time |
|-----|-----|
| 0x0 | Indicates the provider will not start, for example, if it is disabled. The MPR will not retry starting the network provider. |
| Time | Indicates the time, in milliseconds, until the provider starts. |
| 0xFFFFFFFF | Indicates that the provider does not know when it will start. If the network provider returns this value, the MPR uses its default value, 60 seconds.|
| 0x1 | Indicates that the provider is already started. |

####WNNC_USER
Returns WNNC_USR_GETUSER if the network provider supports the [NPGetUser](https://learn.microsoft.com/windows/win32/api/npapi/nf-npapi-npgetuser) function.

## Remarks

When a start time is returned by **NPGetCaps**, the MPR uses this value to determine when to try to start all network providers again. MPR uses the longest start time returned by the providers it called.

## See also

[NPLogonNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nplogonnotify)

[NPPasswordChangeNotify](https://learn.microsoft.com/windows/desktop/api/npapi/nf-npapi-nppasswordchangenotify)