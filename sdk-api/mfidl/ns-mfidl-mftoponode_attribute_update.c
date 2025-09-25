typedef struct _MFTOPONODE_ATTRIBUTE_UPDATE {
  TOPOID            NodeId;
  GUID              guidAttributeKey;
  MF_ATTRIBUTE_TYPE attrType;
  union {
    UINT32 u32;
    UINT64 u64;
    double d;
  };
} MFTOPONODE_ATTRIBUTE_UPDATE;