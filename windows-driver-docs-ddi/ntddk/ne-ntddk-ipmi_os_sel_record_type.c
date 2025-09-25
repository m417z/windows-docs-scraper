typedef enum _IPMI_OS_SEL_RECORD_TYPE {
  IpmiOsSelRecordTypeWhea,
  IpmiOsSelRecordTypeOther,
  IpmiOsSelRecordTypeWheaErrorXpfMca,
  IpmiOsSelRecordTypeWheaErrorPci,
  IpmiOsSelRecordTypeWheaErrorNmi,
  IpmiOsSelRecordTypeWheaErrorOther,
  IpmiOsSelRecordTypeRaw,
  IpmiOsSelRecordTypeDriver,
  IpmiOsSelRecordTypeBugcheckRecovery,
  IpmiOsSelRecordTypeBugcheckData,
  IpmiOsSelRecordTypeMax
} IPMI_OS_SEL_RECORD_TYPE, *PIPMI_OS_SEL_RECORD_TYPE;