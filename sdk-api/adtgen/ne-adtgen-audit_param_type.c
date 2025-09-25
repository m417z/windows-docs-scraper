typedef enum _AUDIT_PARAM_TYPE {
  APT_None,
  APT_String,
  APT_Ulong,
  APT_Pointer,
  APT_Sid,
  APT_LogonId,
  APT_ObjectTypeList,
  APT_Luid,
  APT_Guid,
  APT_Time,
  APT_Int64,
  APT_IpAddress,
  APT_LogonIdWithSid
} AUDIT_PARAM_TYPE;