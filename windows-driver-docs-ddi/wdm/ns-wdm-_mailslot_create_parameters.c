typedef struct _MAILSLOT_CREATE_PARAMETERS {
  ULONG         MailslotQuota;
  ULONG         MaximumMessageSize;
  LARGE_INTEGER ReadTimeout;
  BOOLEAN       TimeoutSpecified;
} MAILSLOT_CREATE_PARAMETERS, *PMAILSLOT_CREATE_PARAMETERS;