typedef struct HWREQCHK_DEVICE_HARDWARE_REQUIREMENT {
  HWREQCHK_TARGET_RELEASE TargetRelease;
  HWREQCHK_PRODUCT_TYPE   ProductType;
  ULONG                   Revision;
  BOOL                    IsLatestRequirementForProductType;
  WCHAR                   RequirementName[HWREQCHK_MAX_HARDWARE_REQUIREMENT_NAME];
} HWREQCHK_DEVICE_HARDWARE_REQUIREMENT;