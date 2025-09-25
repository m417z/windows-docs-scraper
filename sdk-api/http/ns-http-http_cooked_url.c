typedef struct _HTTP_COOKED_URL {
  USHORT FullUrlLength;
  USHORT HostLength;
  USHORT AbsPathLength;
  USHORT QueryStringLength;
  PCWSTR pFullUrl;
  PCWSTR pHost;
  PCWSTR pAbsPath;
  PCWSTR pQueryString;
} HTTP_COOKED_URL, *PHTTP_COOKED_URL;