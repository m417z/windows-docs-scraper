# LsaUnregisterPolicyChangeNotification function

## Description

The **LsaUnregisterPolicyChangeNotification** function disables a previously registered notification event.

## Parameters

### `InformationClass` [in]

A
[POLICY_NOTIFICATION_INFORMATION_CLASS](https://learn.microsoft.com/windows/win32/api/ntsecapi/ne-ntsecapi-policy_notification_information_class) value that specifies the policy changes that your application will stop receiving notifications for. Specify one of the following values.

| Value | Meaning |
| --- | --- |
| **PolicyNotifyAuditEventsInformation** | Auditing policy changes. |
| **PolicyNotifyAccountDomainInformation** | Account domain information changes. |
| **PolicyNotifyServerRoleInformation** | Server role changes. |
| **PolicyNotifyDomainEfsInformation** | EFS policy information changes. |
| **PolicyNotifyDomainKerberosTicketInformation** | Kerberos ticket policy information changes. |
| **PolicyNotifyDnsDomainInformation** | Domain Name System (DNS) information, name, or SID of the system's primary domain changes. |

### `NotificationEventHandle` [in]

A handle to the notification event to unregister.

## Return value

If the function succeeds, the return value is STATUS_SUCCESS.

If the function fails, the return value is an NTSTATUS code. For more information, see
[LSA Policy Function Return Values](https://learn.microsoft.com/windows/desktop/SecMgmt/management-return-values).

You can use the
[LsaNtStatusToWinError](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsantstatustowinerror) function to convert the NTSTATUS code to a Windows error code.

## Remarks

For an example that demonstrates calling this function see
[Receiving Policy Change Events](https://learn.microsoft.com/windows/desktop/SecMgmt/receiving-policy-change-events).

## See also

[LsaRegisterPolicyChangeNotification](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaregisterpolicychangenotification)