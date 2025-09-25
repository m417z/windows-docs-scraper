typedef struct TOKENBINDING_RESULT_DATA {
  TOKENBINDING_TYPE             bindingType;
  DWORD                         identifierSize;
  TOKENBINDING_IDENTIFIER       *identifierData;
  TOKENBINDING_EXTENSION_FORMAT extensionFormat;
  DWORD                         extensionSize;
  PVOID                         extensionData;
} TOKENBINDING_RESULT_DATA;