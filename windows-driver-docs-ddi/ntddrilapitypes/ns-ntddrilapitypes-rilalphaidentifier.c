typedef struct RILALPHAIDENTIFIER {
  DWORD                   cbSize;
  DWORD                   dwParams;
  RILALPHAIDENTIFIDERTYPE dwType;
  WCHAR                   wszReason[256];
} RILALPHAIDENTIFIER, *LPRILALPHAIDENTIFIER;