# FH_LOCAL_POLICY_TYPE enumeration

## Description

Specifies the type of a local policy for the File History feature. Each local policy has a numeric parameter associated with it.

## Constants

### `FH_FREQUENCY:0`

This local policy specifies how frequently backups are to be performed for the current user. The numeric parameter contains the time, in seconds, from the end of one backup until the start of the next one. The default value of the numeric parameter for this policy is 3600 seconds (1 hour).

### `FH_RETENTION_TYPE`

This local policy specifies when previous versions of files and folders can be deleted from a backup target. See the [FH_RETENTION_TYPES](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_retention_types) enumeration for the list of possible values. The default value of the numeric parameter for this policy is **FH_RETENTION_DISABLED**.

### `FH_RETENTION_AGE`

This local policy specifies the minimum age of previous versions that can be deleted from a backup target when the **FH_RETENTION_AGE_BASED** retention type is specified. For more information, see the [FH_RETENTION_TYPES](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_retention_types) enumeration. The numeric parameter contains the minimum age, in days. The default value of the numeric parameter for this policy is 365 days (1 year).

### `MAX_LOCAL_POLICY`

The maximum enumeration value for this enumeration. This value and all values greater than it are reserved for system use.

## Remarks

To retrieve the value of the numeric parameter for a local policy, use the [IFhConfigMgr::GetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getlocalpolicy) method.

To set the value of the numeric parameter for the local policy, use the [IFhConfigMgr::SetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setlocalpolicy) method.

## See also

[FH_RETENTION_TYPES](https://learn.microsoft.com/windows/desktop/api/fhcfg/ne-fhcfg-fh_retention_types)

[IFhConfigMgr::GetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-getlocalpolicy)

[IFhConfigMgr::SetLocalPolicy](https://learn.microsoft.com/windows/desktop/api/fhcfg/nf-fhcfg-ifhconfigmgr-setlocalpolicy)