typedef struct tagSMDATA {
  DWORD            dwMask;
  DWORD            dwFlags;
  HMENU            hmenu;
  HWND             hwnd;
  UINT             uId;
  UINT             uIdParent;
  UINT             uIdAncestor;
  IUnknown         *punk;
  PIDLIST_ABSOLUTE pidlFolder;
  PUITEMID_CHILD   pidlItem;
  IShellFolder     *psf;
  void             *pvUserData;
} SMDATA, *LPSMDATA;