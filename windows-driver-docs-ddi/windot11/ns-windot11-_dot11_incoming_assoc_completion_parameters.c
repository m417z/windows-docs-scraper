typedef struct _DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS {
  NDIS_OBJECT_HEADER     Header;
  DOT11_MAC_ADDRESS      PeerMacAddr;
  ULONG                  uStatus;
  UCHAR                  ucErrorSource;
  BOOLEAN                bReAssocReq;
  BOOLEAN                bReAssocResp;
  ULONG                  uAssocReqOffset;
  ULONG                  uAssocReqSize;
  ULONG                  uAssocRespOffset;
  ULONG                  uAssocRespSize;
  DOT11_AUTH_ALGORITHM   AuthAlgo;
  DOT11_CIPHER_ALGORITHM UnicastCipher;
  DOT11_CIPHER_ALGORITHM MulticastCipher;
  ULONG                  uActivePhyListOffset;
  ULONG                  uActivePhyListSize;
  ULONG                  uBeaconOffset;
  ULONG                  uBeaconSize;
} DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS, *PDOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS;