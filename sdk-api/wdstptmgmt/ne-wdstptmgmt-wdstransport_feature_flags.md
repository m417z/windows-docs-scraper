# WDSTRANSPORT_FEATURE_FLAGS enumeration

## Description

Indicates which WDS features are installed on the WDS server.

## Constants

### `WdsTptFeatureAdminPack:0x1`

The server has the WDS administrator pack installed. This feature is used for managing WDS local or remote WDS servers.

### `WdsTptFeatureTransportServer:0x2`

The server has the WDS Transport Server role installed. This feature provides a generic, extensible transport platform that can be used by any application. Generally, this role has to be installed on the server for most of the WdsTptMgmt functionality to be available. Without this role, only limited functionality about the server's install state would be available through WdsTptMgmt.

### `WdsTptFeatureDeploymentServer:0x4`

The server has the WDS Deployment Server role installed. This feature allows administrators to add operating system images to the server and configure it to allow PXE-booting clients to enumerate and install these images.