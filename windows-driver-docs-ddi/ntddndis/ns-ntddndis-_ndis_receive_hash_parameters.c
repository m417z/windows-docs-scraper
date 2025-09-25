typedef struct _NDIS_RECEIVE_HASH_PARAMETERS {
  NDIS_OBJECT_HEADER Header;
  ULONG              Flags;
  ULONG              HashInformation;
  USHORT             HashSecretKeySize;
  ULONG              HashSecretKeyOffset;
} NDIS_RECEIVE_HASH_PARAMETERS, *PNDIS_RECEIVE_HASH_PARAMETERS;