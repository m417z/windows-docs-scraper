typedef struct ldapapiinfoW {
  int    ldapai_info_version;
  int    ldapai_api_version;
  int    ldapai_protocol_version;
  PWCHAR *ldapai_extensions;
  PWCHAR ldapai_vendor_name;
  int    ldapai_vendor_version;
} LDAPAPIInfoW;