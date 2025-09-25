typedef struct _MSR_UPDATE_KEY {
  unsigned char KeyLength;
  unsigned char KeyNameLength;
  unsigned char Key[MSR_KEY_SIZE];
  unsigned char KeyName[MSR_KEY_NAME_SIZE];
} MSR_UPDATE_KEY, *PMSR_UPDATE_KEY;