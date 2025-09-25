typedef struct tagUSAGE_PROPERTIES {
  USHORT level;
  USHORT page;
  USHORT usage;
  INT32  logicalMinimum;
  INT32  logicalMaximum;
  USHORT unit;
  USHORT exponent;
  BYTE   count;
  INT32  physicalMinimum;
  INT32  physicalMaximum;
} USAGE_PROPERTIES, *PUSAGE_PROPERTIES;