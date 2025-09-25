typedef struct _ads_object_info {
  LPWSTR pszRDN;
  LPWSTR pszObjectDN;
  LPWSTR pszParentDN;
  LPWSTR pszSchemaDN;
  LPWSTR pszClassName;
} ADS_OBJECT_INFO, *PADS_OBJECT_INFO;