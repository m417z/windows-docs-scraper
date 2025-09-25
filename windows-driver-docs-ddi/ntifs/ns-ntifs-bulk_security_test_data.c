typedef struct {
  ACCESS_MASK DesiredAccess;
  ULONG       SecurityIds[1];
} BULK_SECURITY_TEST_DATA, *PBULK_SECURITY_TEST_DATA;