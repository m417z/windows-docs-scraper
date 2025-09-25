typedef struct _MPR40_SERVICE_CHARACTERISTICS {
  DWORD                              dwVersion;
  DWORD                              dwProtocolId;
  DWORD                              fSupportedFunctionality;
  PIS_SERVICE                        pfnIsService;
  PDO_UPDATE_SERVICES                pfnUpdateServices;
  PCREATE_SERVICE_ENUMERATION_HANDLE pfnCreateServiceEnumerationHandle;
  PENUMERATE_GET_NEXT_SERVICE        pfnEnumerateGetNextService;
  PCLOSE_SERVICE_ENUMERATION_HANDLE  pfnCloseServiceEnumerationHandle;
  PGET_SERVICE_COUNT                 pfnGetServiceCount;
  PCREATE_STATIC_SERVICE             pfnCreateStaticService;
  PDELETE_STATIC_SERVICE             pfnDeleteStaticService;
  PBLOCK_CONVERT_SERVICES_TO_STATIC  pfnBlockConvertServicesToStatic;
  PBLOCK_DELETE_STATIC_SERVICES      pfnBlockDeleteStaticServices;
  PGET_FIRST_ORDERED_SERVICE         pfnGetFirstOrderedService;
  PGET_NEXT_ORDERED_SERVICE          pfnGetNextOrderedService;
} MPR40_SERVICE_CHARACTERISTICS;