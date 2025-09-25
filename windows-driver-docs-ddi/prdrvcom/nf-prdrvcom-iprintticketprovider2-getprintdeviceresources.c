HRESULT GetPrintDeviceResources(
  [in]  IN LPCWSTR           pszLocaleName,
  [in]  IN IXMLDOMDocument2  *pPrintTicket,
  [out] OUT IXMLDOMDocument2 **ppDeviceResources
);