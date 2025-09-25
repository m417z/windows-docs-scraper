typedef struct _NTMS_PARTITIONINFORMATIONW {
  NTMS_GUID     PhysicalMedia;
  NTMS_GUID     LogicalMedia;
  DWORD         State;
  WORD          Side;
  DWORD         dwOmidLabelIdLength;
  BYTE          OmidLabelId[NTMS_OMIDLABELID_LENGTH];
  WCHAR         szOmidLabelType[NTMS_OMIDLABELTYPE_LENGTH];
  WCHAR         szOmidLabelInfo[NTMS_OMIDLABELINFO_LENGTH];
  DWORD         dwMountCount;
  DWORD         dwAllocateCount;
  LARGE_INTEGER Capacity;
} NTMS_PARTITIONINFORMATIONW;