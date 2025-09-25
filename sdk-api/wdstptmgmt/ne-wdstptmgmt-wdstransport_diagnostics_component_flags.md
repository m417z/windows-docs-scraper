# WDSTRANSPORT_DIAGNOSTICS_COMPONENT_FLAGS enumeration

## Description

Configures which WDS components have diagnostics enabled. WDS diagnostics log events to the system event log.

## Constants

### `WdsTptDiagnosticsComponentPxe:0x1`

Diagnostics are enabled for the PXE component of WDS, which answers requests from clients performing a PXE network boot. This component is typically used by the WDS Deployment Server role but is also available for various third-party applications that use the WDS Transport Server role.

### `WdsTptDiagnosticsComponentTftp:0x2`

Diagnostics are enabled for the TFTP component of WDS, which handles simple file transfers from clients that are typically in a pre-boot environment. This component is typically used by the WDS Deployment Server role but is also available for various third-party applications that use the WDS Transport Server role.

### `WdsTptDiagnosticsComponentImageServer:0x4`

Diagnostics are enabled for the Image Server component of WDS, which handles client requests for enumerating operating system images on the server. This component is typically used by the WDS Deployment Server role.

### `WdsTptDiagnosticsComponentMulticast:0x8`

Diagnostics are enabled for the Multicast component of WDS, which handles multicast file transfers from clients.