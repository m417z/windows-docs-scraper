typedef struct _SP_NEWDEVICEWIZARD_DATA {
  SP_CLASSINSTALL_HEADER ClassInstallHeader;
  DWORD                  Flags;
  HPROPSHEETPAGE         DynamicPages[MAX_INSTALLWIZARD_DYNAPAGES];
  DWORD                  NumDynamicPages;
  HWND                   hwndWizardDlg;
} SP_NEWDEVICEWIZARD_DATA, *PSP_NEWDEVICEWIZARD_DATA;