# pluginResource structure

## Description

Contains information about a resource that can be assigned to users in RemoteApp and Desktop Connection.

## Members

### `alias`

The alias of the resource.

### `name`

The name of the resource.

### `resourceFileContents`

The contents of the resource file. The plug-in should allocate memory for this member by calling the [CoTaskMemAlloc](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemalloc) function.

### `fileExtension`

The file name extension of the resource file. If this member is set to ".rdp", RD Web Access opens the file by using the ActiveX control.

### `resourcePluginType`

A unique identifier that identifies the resource plug-in.

### `isDiscoverable`

A Boolean value that indicates whether the resource should be displayed in RD Web Access or RemoteApp and Desktop Connections.

### `resourceType`

The type of resource.

#### 1

RemoteApp application.

#### 2

Personal virtual desktop.

### `pceIconSize`

The size, in bytes, of the icon.

### `iconContents`

A byte array that defines the icon to be displayed for the resource.

### `pcePluginBlobSize`

The size, in bytes, of the **blobContents** member.

### `blobContents`

This member is reserved. Set it to **NULL**.

## See also

[RemoteApp and Desktop Connection Management Service Interfaces](https://learn.microsoft.com/windows/desktop/TermServ/remoteapp-and-desktop-connection-management-service-interfaces)

[RemoteApp and Desktop Connection Management Service Structures](https://learn.microsoft.com/windows/desktop/TermServ/remoteapp-and-desktop-connection-management-service-structures)