typedef struct tagLVINSERTGROUPSORTED {
  PFNLVGROUPCOMPARE pfnGroupCompare;
  void              *pvData;
  LVGROUP           lvGroup;
} LVINSERTGROUPSORTED, *PLVINSERTGROUPSORTED;