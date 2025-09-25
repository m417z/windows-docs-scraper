typedef struct ldapapiinfoA {
  int  ldapai_info_version;
  int  ldapai_api_version;
  int  ldapai_protocol_version;
  char **ldapai_extensions;
  char *ldapai_vendor_name;
  int  ldapai_vendor_version;
} LDAPAPIInfoA;