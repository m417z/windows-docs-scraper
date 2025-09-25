typedef struct _TOPOLOGY_MAP {
  USHORT  TOP_Length;
  USHORT  TOP_CRC;
  ULONG   TOP_Generation;
  USHORT  TOP_Node_Count;
  USHORT  TOP_Self_ID_Count;
  SELF_ID TOP_Self_ID_Array[1];
} TOPOLOGY_MAP, *PTOPOLOGY_MAP;