typedef struct _SFV_CREATE {
  UINT               cbSize;
  IShellFolder       *pshf;
  IShellView         *psvOuter;
  IShellFolderViewCB *psfvcb;
} SFV_CREATE;