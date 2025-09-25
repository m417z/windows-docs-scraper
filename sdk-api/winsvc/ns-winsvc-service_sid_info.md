# SERVICE_SID_INFO structure

## Description

Represents a service security identifier (SID).

## Members

### `dwServiceSidType`

The service SID type.

| Value | Meaning |
| --- | --- |
| **SERVICE_SID_TYPE_NONE**<br><br>0x00000000 | Use this type to reduce application compatibility issues. |
| **SERVICE_SID_TYPE_RESTRICTED**<br><br>0x00000003 | This type includes SERVICE_SID_TYPE_UNRESTRICTED. The service SID is also added to the restricted SID list of the process token. Three additional SIDs are also added to the restricted SID list: <br><br>* World SID S-1-1-0<br>* Service logon SID<br>* Write-restricted SID S-1-5-33<br><br>One ACE that allows GENERIC_ALL access for the service logon SID is also added to the service process token object.<br><br>If there are multiple services hosted in the same process and one service has SERVICE_SID_TYPE_RESTRICTED, all services must have SERVICE_SID_TYPE_RESTRICTED. |
| **SERVICE_SID_TYPE_UNRESTRICTED**<br><br>0x00000001 | When the service process is created, the service SID is added to the service process token with the following attributes: SE_GROUP_ENABLED_BY_DEFAULT | SE_GROUP_OWNER. |

## Remarks

The change takes effect the next time the system is started.

The SCM adds the specified service SIDs to the process token, plus the following additional SIDs.

| SID | Attributes |
| --- | --- |
| Logon SID | SE_GROUP_ENABLED | SE_GROUP_ENABLED_BY_DEFAULT | SE_GROUP_LOGON_ID | SE_GROUP_MANDATORY |
| Local SID | SE_GROUP_MANDATORY | SE_GROUP_ENABLED | SE_GROUP_ENABLED_BY_DEFAULT |

This enables developers to control access to the objects a service uses, instead of relying on the use of the LocalSystem account to obtain access.

Use the [LookupAccountName](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountnamea) and [LookupAccountSid](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-lookupaccountsida) functions to convert between a service name and a service SID. The account name is of the following form:

NT SERVICE\*SvcName*

Note that NT SERVICE is the domain name.

## See also

[ChangeServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-changeserviceconfig2a)

[QueryServiceConfig2](https://learn.microsoft.com/windows/desktop/api/winsvc/nf-winsvc-queryserviceconfig2a)