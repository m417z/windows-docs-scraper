typedef struct _PEP_COMPONENT_ACTIVE {
  [in]  PEPHANDLE             DeviceHandle;
  [in]  ULONG                 Component;
  [in]  BOOLEAN               Active;
  [out] PPEP_WORK_INFORMATION WorkInformation;
  [out] BOOLEAN               NeedWork;
} PEP_COMPONENT_ACTIVE, *PPEP_COMPONENT_ACTIVE;