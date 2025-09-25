typedef struct {
  DWORD dwFlags;
  CLSID clsidWizardDialog;
  CLSID clsidWizardPrimaryPage;
  DWORD cWizardExtensions;
  CLSID aWizardExtensions[1];
} DSCLASSCREATIONINFO, *LPDSCLASSCREATIONINFO;