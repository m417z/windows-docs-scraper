typedef struct _CRYPT_XML_ALGORITHM_INFO {
  DWORD cbSize;
  WCHAR *wszAlgorithmURI;
  WCHAR *wszName;
  DWORD dwGroupId;
  WCHAR *wszCNGAlgid;
  WCHAR *wszCNGExtraAlgid;
  DWORD dwSignFlags;
  DWORD dwVerifyFlags;
  void  *pvPaddingInfo;
  void  *pvExtraInfo;
} CRYPT_XML_ALGORITHM_INFO, *PCRYPT_XML_ALGORITHM_INFO;