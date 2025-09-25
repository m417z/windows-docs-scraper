typedef struct _RADIUS_EXTENSION_CONTROL_BLOCK {
  DWORD                    cbSize;
  DWORD                    dwVersion;
  RADIUS_EXTENSION_POINT   repPoint;
  RADIUS_CODE              rcRequestType;
  RADIUS_CODE              rcResponseType;
  PRADIUS_ATTRIBUTE_ARRAY()(_RADIUS_EXTENSION_CONTROL_BLOCK *This) * GetRequest;
  PRADIUS_ATTRIBUTE_ARRAY()(_RADIUS_EXTENSION_CONTROL_BLOCK *This,RADIUS_CODE rcResponseType) * GetResponse;
  DWORD()(_RADIUS_EXTENSION_CONTROL_BLOCK *This,RADIUS_CODE rcResponseType)                   * SetResponseType;
} RADIUS_EXTENSION_CONTROL_BLOCK, *PRADIUS_EXTENSION_CONTROL_BLOCK;