typedef enum _POLICY_INFORMATION_CLASS {
  PolicyAuditLogInformation = 1,
  PolicyAuditEventsInformation,
  PolicyPrimaryDomainInformation,
  PolicyPdAccountInformation,
  PolicyAccountDomainInformation,
  PolicyLsaServerRoleInformation,
  PolicyReplicaSourceInformation,
  PolicyDefaultQuotaInformation,
  PolicyModificationInformation,
  PolicyAuditFullSetInformation,
  PolicyAuditFullQueryInformation,
  PolicyDnsDomainInformation,
  PolicyDnsDomainInformationInt,
  PolicyLocalAccountDomainInformation,
  PolicyMachineAccountInformation,
  PolicyMachineAccountInformation2,
  PolicyLastEntry
} POLICY_INFORMATION_CLASS, *PPOLICY_INFORMATION_CLASS;