typedef struct _FAX_ROUTE {
  DWORD     SizeOfStruct;
  DWORD     JobId;
  DWORDLONG ElapsedTime;
  DWORDLONG ReceiveTime;
  DWORD     PageCount;
  LPCWSTR   Csid;
  LPCWSTR   Tsid;
  LPCWSTR   CallerId;
  LPCWSTR   RoutingInfo;
  LPCWSTR   ReceiverName;
  LPCWSTR   ReceiverNumber;
  LPCWSTR   DeviceName;
  DWORD     DeviceId;
  LPBYTE    RoutingInfoData;
  DWORD     RoutingInfoDataSize;
} FAX_ROUTE, *PFAX_ROUTE;