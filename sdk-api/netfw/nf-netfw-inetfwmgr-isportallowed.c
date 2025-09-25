HRESULT IsPortAllowed(
  [in]  BSTR               imageFileName,
  [in]  NET_FW_IP_VERSION  ipVersion,
  [in]  LONG               portNumber,
  [in]  BSTR               localAddress,
  [in]  NET_FW_IP_PROTOCOL ipProtocol,
  [out] VARIANT            *allowed,
  [out] VARIANT            *restricted
);