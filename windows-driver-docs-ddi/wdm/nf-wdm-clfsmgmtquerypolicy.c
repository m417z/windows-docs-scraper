CLFSUSER_API NTSTATUS ClfsMgmtQueryPolicy(
  [in]  PLOG_FILE_OBJECT      LogFile,
  [in]  CLFS_MGMT_POLICY_TYPE PolicyType,
  [out] PCLFS_MGMT_POLICY     Policy,
  [out] PULONG                PolicyLength
);