typedef enum _POLICY_NOTIFICATION_INFORMATION_CLASS {
  PolicyNotifyAuditEventsInformation = 1,
  PolicyNotifyAccountDomainInformation,
  PolicyNotifyServerRoleInformation,
  PolicyNotifyDnsDomainInformation,
  PolicyNotifyDomainEfsInformation,
  PolicyNotifyDomainKerberosTicketInformation,
  PolicyNotifyMachineAccountPasswordInformation,
  PolicyNotifyGlobalSaclInformation,
  PolicyNotifyMax
} POLICY_NOTIFICATION_INFORMATION_CLASS, *PPOLICY_NOTIFICATION_INFORMATION_CLASS;