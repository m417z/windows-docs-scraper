typedef struct _WSDXML_PREFIX_MAPPING {
  DWORD                 Refs;
  WSDXML_PREFIX_MAPPING *Next;
  WSDXML_NAMESPACE      *Space;
  WCHAR                 *Prefix;
} WSDXML_PREFIX_MAPPING;