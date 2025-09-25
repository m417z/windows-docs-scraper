typedef struct _KTMOBJECT_CURSOR {
  GUID  LastQuery;
  ULONG ObjectIdCount;
  GUID  ObjectIds[1];
} KTMOBJECT_CURSOR, *PKTMOBJECT_CURSOR;