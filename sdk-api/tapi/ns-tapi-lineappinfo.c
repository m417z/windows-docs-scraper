typedef struct lineappinfo_tag {
  DWORD dwMachineNameSize;
  DWORD dwMachineNameOffset;
  DWORD dwUserNameSize;
  DWORD dwUserNameOffset;
  DWORD dwModuleFilenameSize;
  DWORD dwModuleFilenameOffset;
  DWORD dwFriendlyNameSize;
  DWORD dwFriendlyNameOffset;
  DWORD dwMediaModes;
  DWORD dwAddressID;
} LINEAPPINFO, *LPLINEAPPINFO;