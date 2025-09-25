typedef struct _SEC_TRAFFIC_SECRETS {
  wchar_t                 SymmetricAlgId[SZ_ALG_MAX_SIZE];
  wchar_t                 ChainingMode[SZ_ALG_MAX_SIZE];
  wchar_t                 HashAlgId[SZ_ALG_MAX_SIZE];
  unsigned short          KeySize;
  unsigned short          IvSize;
  unsigned short          MsgSequenceStart;
  unsigned short          MsgSequenceEnd;
  SEC_TRAFFIC_SECRET_TYPE TrafficSecretType;
  unsigned short          TrafficSecretSize;
  unsigned char           TrafficSecret[ANYSIZE_ARRAY];
} SEC_TRAFFIC_SECRETS, *PSEC_TRAFFIC_SECRETS;