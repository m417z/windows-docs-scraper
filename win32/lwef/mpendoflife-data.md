# MPENDOFLIFE\_DATA structure

"End of life" notification data.

## Members

**ftSignatureExpiry**

Type: **FILETIME**

Time when the signature expires.

**ftPlatformExpiry**

Type: **FILETIME**

Time when the platform expires.

**fAdminControlled**

Type: **BOOL**

True if the administrator controlling the policy for showing the notification. If set, this tells the UI to not show the EOL notification.

**fEndOfLifeImpendingOrPast**

Type: **BOOL**

True if "End of Life" is pending or past. If false, UI and clients can clear any EOL related states.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

