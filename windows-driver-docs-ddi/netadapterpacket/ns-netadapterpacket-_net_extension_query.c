typedef struct _NET_EXTENSION_QUERY {
  ULONG              Size;
  PCWSTR             Name;
  ULONG              Version;
  NET_EXTENSION_TYPE Type;
} NET_EXTENSION_QUERY;