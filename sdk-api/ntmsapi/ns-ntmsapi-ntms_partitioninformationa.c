typedef struct _NTMS_PARTITIONINFORMATIONA {
  NTMS_GUID     PhysicalMedia;
  NTMS_GUID     LogicalMedia;
  DWORD         State;
  WORD          Side;
  DWORD         dwOmidLabelIdLength;
  BYTE          OmidLabelId[NTMS_OMIDLABELID_LENGTH];
  CHAR          szOmidLabelType[NTMS_OMIDLABELTYPE_LENGTH];
  CHAR          szOmidLabelInfo[NTMS_OMIDLABELINFO_LENGTH];
  DWORD         dwMountCount;
  DWORD         dwAllocateCount;
  LARGE_INTEGER Capacity;
} NTMS_PARTITIONINFORMATIONA;