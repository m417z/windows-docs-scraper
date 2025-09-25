# ItsPubPlugin2::ResolvePersonalDesktop

## Description

Called to resolve a mapping between the specified user and a virtual machine in a personal virtual desktop collection.

## Parameters

### `userId` [in]

A null-terminated string that contains the security identifier (SID) of the user.

### `poolId` [in]

A null-terminated string that contains the identifier of the collection to obtain the personal desktop from or create the personal desktop in.

### `ePdResolutionType` [in]

A value of the [TSPUB_PLUGIN_PD_RESOLUTION_TYPE](https://learn.microsoft.com/windows/win32/api/tspubplugin2com/ne-tspubplugin2com-tspub_plugin_pd_resolution_type) enumeration that specifies the type of resolution being requested.

### `pPdAssignmentType` [out]

A value of the [TSPUB_PLUGIN_PD_ASSIGNMENT_TYPE](https://learn.microsoft.com/windows/win32/api/tspubplugin2com/ne-tspubplugin2com-tspub_plugin_pd_assignment_type) enumeration that specifies what type of assignment was made for the personal desktop.

### `endPointName` [out]

A null-terminated string that receives the name of the end point for the desktop. The length of this string is limited to **MAX_ENDPOINT_SIZE** characters, including the terminating **NULL** character.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**MAX_ENDPOINT_SIZE** is declared as follows:

`#define MAX_ENDPOINT_SIZE 256`

## See also

[ItsPubPlugin2](https://learn.microsoft.com/windows/desktop/api/tspubplugin2com/nn-tspubplugin2com-itspubplugin2)