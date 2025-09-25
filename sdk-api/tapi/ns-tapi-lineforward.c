typedef struct lineforward_tag {
  DWORD dwForwardMode;
  DWORD dwCallerAddressSize;
  DWORD dwCallerAddressOffset;
  DWORD dwDestCountryCode;
  DWORD dwDestAddressSize;
  DWORD dwDestAddressOffset;
  DWORD dwCallerAddressType;
  DWORD dwDestAddressType;
} LINEFORWARD, *LPLINEFORWARD;