HRESULT SetPacketValuesByProperty(
  [in]           BSTR    bstrPropertyName,
  [in]           VARIANT PacketValues,
  [in, optional] long    Index,
  [in, optional] long    Count,
  [out, retval]  long    *NumberOfPacketsSet
);