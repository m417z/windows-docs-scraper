HRESULT OnServerCertificateReceived(
  [in] IXMLHTTPRequest3 *pXHR,
  [in] DWORD            dwCertificateErrors,
  [in] DWORD            cServerCertificateChain,
  [in] const XHR_CERT   *rgServerCertificateChain
);