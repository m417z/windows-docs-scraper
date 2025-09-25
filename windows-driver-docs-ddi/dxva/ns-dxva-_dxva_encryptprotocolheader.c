typedef struct _DXVA_EncryptProtocolHeader {
  DXVA_EncryptProtocolFunc dwFunction;
  DWORD                    ReservedBits[3];
  GUID                     guidEncryptProtocol;
} DXVA_EncryptProtocolHeader, *LPDXVA_EncryptProtocolHeader;