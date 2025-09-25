# FAX_ROUTE_CALLBACKROUTINES structure

## Description

The **FAX_ROUTE_CALLBACKROUTINES** structure contains pointers to callback functions the fax service provides. A fax routing extension's routing methods can call these callback functions to manage the files in the fax file list associated with a received fax document.

## Members

### `SizeOfStruct`

Type: **DWORD**

Specifies the size, in bytes, of the **FAX_ROUTE_CALLBACKROUTINES** structure. The fax service sets this member to sizeof(FAX_ROUTE_CALLBACKROUTINES). For information about backward compatibility, see the following Remarks section.

### `FaxRouteAddFile`

Type: **PFAXROUTEADDFILE**

Pointer to a [FaxRouteAddFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteaddfile) callback function that a fax routing method uses to add a file to the fax file list associated with a received fax document.

### `FaxRouteDeleteFile`

Type: **PFAXROUTEDELETEFILE**

Pointer to a [FaxRouteDeleteFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutedeletefile) callback function that a fax routing method uses to delete a file from the fax file list associated with a received fax document.

### `FaxRouteGetFile`

Type: **PFAXROUTEGETFILE**

Pointer to a [FaxRouteGetFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutegetfile) callback function that a fax routing method uses to retrieve a specific file name from the fax file list associated with a received fax document.

### `FaxRouteEnumFiles`

Type: **PFAXROUTEENUMFILES**

Pointer to a [FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles) callback function that a fax routing method uses to enumerate the files in the fax file list associated with a received fax document.

### `FaxRouteModifyRoutingData`

Type: **PFAXROUTEMODIFYROUTINGDATA**

Pointer to a [FaxRouteModifyRoutingData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemodifyroutingdata) callback function that a fax routing method uses to modify the routing data associated with a subsequent fax routing method.

## Remarks

The fax routing extension DLL must store the pointers to these callback functions in a global variable for later use.

If the **SizeOfStruct** member is greater than sizeof(FAX_ROUTE_CALLBACKROUTINES), this indicates that the **FAX_ROUTE_CALLBACKROUTINES** structure has been updated by Microsoft, and your application is using an earlier version. To maintain backward compatibility, changes will be appended to the original prototype of the **FAX_ROUTE_CALLBACKROUTINES** structure. For example, new members for additional callback functions will be added sequentially after the **FaxRouteModifyRoutingData** member.

For more information, see [Fax Routing Extension Registration](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-registration) and [Fax File Lists](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-file-lists).

## See also

[Fax Routing Extension Application Programming Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-about-the-fax-routing-extension-api)

[Fax Routing Extension Structures](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-fax-routing-extension-structures)

[FaxRouteAddFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteaddfile)

[FaxRouteDeleteFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutedeletefile)

[FaxRouteEnumFiles](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxrouteenumfiles)

[FaxRouteGetFile](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutegetfile)

[FaxRouteModifyRoutingData](https://learn.microsoft.com/previous-versions/windows/desktop/api/faxroute/nc-faxroute-pfaxroutemodifyroutingdata)