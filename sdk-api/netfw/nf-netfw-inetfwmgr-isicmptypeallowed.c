HRESULT IsIcmpTypeAllowed(
  [in]  NET_FW_IP_VERSION ipVersion,
  [in]  BSTR              localAddress,
  [in]  BYTE              type,
  [out] VARIANT           *allowed,
  [out] VARIANT           *restricted
);