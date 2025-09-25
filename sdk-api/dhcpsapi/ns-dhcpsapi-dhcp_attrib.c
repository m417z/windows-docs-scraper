typedef struct _DHCP_ATTRIB {
  DHCP_ATTRIB_ID DhcpAttribId;
  ULONG          DhcpAttribType;
  union {
    BOOL  DhcpAttribBool;
    ULONG DhcpAttribUlong;
  };
  union {
    BOOL  DhcpAttribBool;
    ULONG DhcpAttribUlong;
  };
} DHCP_ATTRIB, *PDHCP_ATTRIB, *LPDHCP_ATTRIB;