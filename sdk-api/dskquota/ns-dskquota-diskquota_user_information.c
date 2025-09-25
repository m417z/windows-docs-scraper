typedef struct DiskQuotaUserInformation {
  LONGLONG QuotaUsed;
  LONGLONG QuotaThreshold;
  LONGLONG QuotaLimit;
} DISKQUOTA_USER_INFORMATION, *PDISKQUOTA_USER_INFORMATION;