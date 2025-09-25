typedef struct tagPOINTER_DEVICE_PROPERTY {
  INT32  logicalMin;
  INT32  logicalMax;
  INT32  physicalMin;
  INT32  physicalMax;
  UINT32 unit;
  UINT32 unitExponent;
  USHORT usagePageId;
  USHORT usageId;
} POINTER_DEVICE_PROPERTY;