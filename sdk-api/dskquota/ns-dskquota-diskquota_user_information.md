# DISKQUOTA_USER_INFORMATION structure

## Description

Represents the per-user quota information.

## Members

### `QuotaUsed`

The disk space charged to the user, in bytes. This is the amount of information stored, not necessarily the number of bytes used on disk.

### `QuotaThreshold`

The warning threshold for the user, in bytes. You can use the
[IDiskQuotaControl::SetQuotaLogFlags](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-setquotalogflags) method to configure the system to generate a system logfile entry when the disk space charged to the user exceeds this value.

### `QuotaLimit`

The quota limit for the user, in bytes. If this value is -1, the user has an unlimited quota.

You can use the [IDiskQuotaControl::SetQuotaLogFlags](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-setquotalogflags) method to configure the system to generate a system logfile entry when the disk space charged to the user exceeds this value. You can also use the
[IDiskQuotaControl::SetQuotaState](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-setquotastate) method to configure the system to deny additional disk space to the user when the disk space charged to the user exceeds this value.

## See also

[IDiskQuotaControl::SetQuotaLogFlags](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-setquotalogflags)

[IDiskQuotaControl::SetQuotaState](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotacontrol-setquotastate)

[IDiskQuotaUser::GetQuotaInformation](https://learn.microsoft.com/windows/desktop/api/dskquota/nf-dskquota-idiskquotauser-getquotainformation)