# MPSIGUPDATE\_DATA structure

Notification data passed to the signature update callback function.

## Members

**dwPercentComplete**

Type: **DWORD**

An estimate of the percentage across all the updates that have been downloaded and/or installed.

**dwTotalUpdates**

Type: **DWORD**

Total number of updates to download and/or install.

**dwCurrentUpdateIndex**

Type: **DWORD**

Zero-based index value that specifies which update among those required is currently being downloaded and/or installed.

**eType**

Type: **MPSIGUPDATE\_TYPE**

Update type. One of the following possible values:

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------|
|

**MPSIGUPDATE\_TYPE\_NONE**

| |
|

**MPSIGUPDATE\_TYPE\_MANAGED**

| WSUS update. Cancel requires administrator rights.<br> |
|

**MPSIGUPDATE\_TYPE\_HTTP**

| HTTP update. Administrator rights not needed to cancel.<br> |
|

**MPSIGUPDATE\_TYPE\_HTTP\_SRV**

| HTTP from service. Cancel requires administrator rights.<br> |
|

**MPSIGUPDATE\_TYPE\_UNC**

| UNC share. Administrator rights not needed to cancel.<br> |
|

**MPSIGUPDATE\_TYPE\_UNMANAGED**

| MU/WU update. Cancel requires administrator rights.<br> |
|

**MPSIGUPDATE\_TYPE\_MANAGED\_PLATFORM**

| WSUS update for PLATFORM. Cancel requires administrator rights.<br> |
|

**MPSIGUPDATE\_TYPE\_UNMANAGED\_PLATFORM**

| MU/WU update for PLATFORM. Cancel requires administrator rights.<br> |

**Stage**

Type: **MP\_UPDATE\_STAGE**

Update stage. One of the following possible values:

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-----------------------------------|
|

**MP\_STAGE\_UNKNOWN**

| Update stage unknown.<br> |
|

**MP\_SEARCH\_UPDATE**

| Update search stage.<br> |
|

**MP\_DOWNLOAD\_UPDATE**

| Update download stage.<br> |
|

**MP\_INSTALL\_UPDATE**

| Update install stage.<br> |

**Path**

Type: **MP\_MIDL\_STRING LPWSTR**

Update path.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

