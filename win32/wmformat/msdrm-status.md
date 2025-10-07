# MSDRM\_STATUS enumeration

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **MSDRM\_STATUS** enumeration type defines status conditions for the DRM subsystem.

## Constants

**DRM\_ERROR**

Specifies that an error has occurred.

**DRM\_INFORMATION**

Specifies that there is additional status information.

**DRM\_BACKUPRESTORE\_BEGIN**

Specifies that a license backup or restore operation has begun.

**DRM\_BACKUPRESTORE\_END**

Specifies that a license backup or restore operation has ended.

**DRM\_BACKUPRESTORE\_CONNECTING**

Specifies that a license backup or restore operation is in progress and that the client computer is connecting with the backup server.

**DRM\_BACKUPRESTORE\_DISCONNECTING**

Specifies that a license backup or restore operation is in progress and that the client computer is disconnecting from the backup server.

**DRM\_ERROR\_WITHURL**

Specifies that the DRM operation has encountered a bad URL.

**DRM\_RESTRICTED\_LICENSE**

Specifies that the DRM operation cannot continue because no license granting the required right exists on the client computer.

**DRM\_NEEDS\_INDIVIDUALIZATION**

Specifies that the DRM operation cannot continue because the DRM subsystem needs to be individualized.

**DRM\_PLAY\_OPL\_NOTIFICATION**

Specifies that a playback operation cannot be completed because an output protection level requirement has not been met.

**DRM\_COPY\_OPL\_NOTIFICATION**

Specifies that a copy operation cannot be completed because an output protection level requirement has not been met.

**DRM\_REFRESHCRL\_COMPLETE**

Specifies that a call to [**IWMDRMSecurity::PerformSecurityUpdate**](https://learn.microsoft.com/windows/win32/wmformat/iwmdrmsecurity-performsecurityupdate) has completed refreshing a revocation list.

## Remarks

None.

## Requirements

| Requirement | Value |
|-------------------|---------------------------------------------------------------------------------------|
| Header<br> | Wmdrmsdk.h |

## See also

[**Enumeration Types**](https://learn.microsoft.com/windows/win32/wmformat/drm-enumeration-types)

