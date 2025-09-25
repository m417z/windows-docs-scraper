typedef struct _USBC_FUNCTION_DESCRIPTOR {
  UCHAR                     FunctionNumber;
  UCHAR                     NumberOfInterfaces;
  PUSB_INTERFACE_DESCRIPTOR *InterfaceDescriptorList;
  UNICODE_STRING            HardwareId;
  UNICODE_STRING            CompatibleId;
  UNICODE_STRING            FunctionDescription;
  ULONG                     FunctionFlags;
  PVOID                     Reserved;
} USBC_FUNCTION_DESCRIPTOR, *PUSBC_FUNCTION_DESCRIPTOR;