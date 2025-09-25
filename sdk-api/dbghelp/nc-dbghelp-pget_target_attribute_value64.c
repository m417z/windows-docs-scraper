PGET_TARGET_ATTRIBUTE_VALUE64 PgetTargetAttributeValue64;

BOOL PgetTargetAttributeValue64(
  [in]  HANDLE hProcess,
  [in]  DWORD Attribute,
  [in]  DWORD64 AttributeData,
  [out] DWORD64 *AttributeValue
)
{...}