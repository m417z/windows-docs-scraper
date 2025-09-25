typedef struct DNS_PROXY_INFORMATION {
  ULONG                      version;
  DNS_PROXY_INFORMATION_TYPE proxyInformationType;
  PWSTR                      proxyName;
} DNS_PROXY_INFORMATION;