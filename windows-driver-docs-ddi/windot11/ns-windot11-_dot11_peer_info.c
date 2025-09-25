typedef struct _DOT11_PEER_INFO {
  DOT11_MAC_ADDRESS       MacAddress;
  USHORT                  usCapabilityInformation;
  DOT11_AUTH_ALGORITHM    AuthAlgo;
  DOT11_CIPHER_ALGORITHM  UnicastCipherAlgo;
  DOT11_CIPHER_ALGORITHM  MulticastCipherAlgo;
  BOOLEAN                 bWpsEnabled;
  USHORT                  usListenInterval;
  UCHAR                   ucSupportedRates[MAX_NUM_SUPPORTED_RATES_V2];
  USHORT                  usAssociationID;
  DOT11_ASSOCIATION_STATE AssociationState;
  DOT11_POWER_MODE        PowerMode;
  LARGE_INTEGER           liAssociationUpTime;
  DOT11_PEER_STATISTICS   Statistics;
} DOT11_PEER_INFO, *PDOT11_PEER_INFO;