typedef struct _USBFN_CLASS_INFORMATION_PACKET_EX {
  USBFN_CLASS_INTERFACE_EX FullSpeedClassInterfaceEx;
  USBFN_CLASS_INTERFACE_EX HighSpeedClassInterfaceEx;
  USBFN_CLASS_INTERFACE_EX SuperSpeedClassInterfaceEx;
  WCHAR                    InterfaceName[MAX_INTERFACE_NAME_LENGTH];
  WCHAR                    InterfaceGuid[MAX_INTERFACE_GUID_LENGTH];
  BOOLEAN                  HasInterfaceGuid;
} USBFN_CLASS_INFORMATION_PACKET_EX, *PUSBFN_CLASS_INFORMATION_PACKET_EX;