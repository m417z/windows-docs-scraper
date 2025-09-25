typedef struct _MSR_AUTHENTICATE_DEVICE {
  unsigned char Size;
  unsigned char Challenge1[MSR_CHALLENGE_SIZE];
  unsigned char SessionId[MSR_SESSION_ID_SIZE];
} MSR_AUTHENTICATE_DEVICE, *PMSR_AUTHENTICATE_DEVICE;