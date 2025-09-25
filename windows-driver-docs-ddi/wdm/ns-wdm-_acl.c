typedef struct _ACL {
  UCHAR  AclRevision;
  UCHAR  Sbz1;
  USHORT AclSize;
  USHORT AceCount;
  USHORT Sbz2;
} ACL;