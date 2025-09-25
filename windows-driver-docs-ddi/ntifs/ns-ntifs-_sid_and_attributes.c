typedef struct _SID_AND_ATTRIBUTES {
#if ...
  PISID Sid;
#else
  PSID  Sid;
#endif
  ULONG Attributes;
} SID_AND_ATTRIBUTES, *PSID_AND_ATTRIBUTES;