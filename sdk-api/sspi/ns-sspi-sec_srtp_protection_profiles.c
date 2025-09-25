typedef struct _SEC_SRTP_PROTECTION_PROFILES {
  unsigned short ProfilesSize;
  unsigned short ProfilesList[ANYSIZE_ARRAY];
} SEC_SRTP_PROTECTION_PROFILES, *PSEC_SRTP_PROTECTION_PROFILES;